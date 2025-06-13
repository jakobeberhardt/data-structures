set -euo pipefail

usage() {
  echo "Usage: $0 <base_json> <n_min> <n_max> <step> [--link-q] [--cpu ID] [--nice N]"
  exit 1
}

if [[ $# -lt 4 ]]; then usage; fi

BASE_CFG=$1; shift
N_MIN=$1;   shift
N_MAX=$1;   shift
STEP=$1;    shift

CPU_ID=0          
NICE_VAL=-20      
LINK_Q=false

while [[ $# -gt 0 ]]; do
  case $1 in
    --link-q) LINK_Q=true; shift ;;
    --cpu)    CPU_ID=$2;  shift 2 ;;
    --nice)   NICE_VAL=$2; shift 2 ;;
    *)        usage ;;
  esac
done

echo "# Running on CPU $CPU_ID  (nice $NICE_VAL)"
echo "# n from $N_MIN to $N_MAX in steps of $STEP"
$LINK_Q && echo "# q linked to n"

make

IMPLS=(
  "BST_VEB" "BST_EYT" "BST_EYT_PREF" "BST_EYT_PREF_TWO" "BST_EYT_PREF_THREE" "BST_EYT_PREF_FOUR" "BST_EYT_PREF_PROB"
)

TMP=$(mktemp)
cleanup() { rm -f "$TMP"; }
trap cleanup EXIT

for (( N=N_MIN; N<=N_MAX; N+=STEP )); do
  if $LINK_Q; then
    jq --argjson n "$N" '.n=$n | .q=$n' "$BASE_CFG" > "$TMP"
  else
    jq --argjson n "$N" '.n=$n' "$BASE_CFG"        > "$TMP"
  fi

  for impl in "${IMPLS[@]}"; do
  nice -n "$NICE_VAL" chrt --fifo 99 taskset -c "$CPU_ID" ./bst-bench "$TMP" "$impl"
done
done


# sudo bash scale_bench.sh data/base.json 500000 10000000 500000  --cpu 2 