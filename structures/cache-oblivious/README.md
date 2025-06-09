# Cache-Oblivious: VanEmde-Boas-Trees

- Jakob Eberhardt (jakob.eberhardt@estudiantat.upc.edu)

## Project Structure

- **src/**: Contains the implementation and instrumentation
- **data/**: The data obtained from the benchmarks which are used in the report
- **include/**: Interface and implementation
- **src/util/**: Includes external helper functions, e.g. for input parsing
- **Makefile**: To build the executable for the local architecture
- **build**: Build artifacts
- **tex**: Sources or the report

## Building and running the project

The executable for benchmarking __bst-bench__ is build by executing
```bash
make
```
The config files located under __data/__ correspond to the instances used in the project. The parameter __n__ is the total amount of allocated nodes, __q__ the amount of queries run, __T__ the amount of repetitions, __csv__ for table or CSV output and __seed__ for the RNG.   The benchmark can be executed as following

```json
{
  "n"   : 1000000,
  "q"   : 1000000,
  "T"   : 1,
  "csv" : false,
  "seed": 123
}
```

```bash
sudo bash run_bench.sh data/test.json
```
Note that we need elevated privileges to access the perf hardware counters. The standard benchmark runs the input from the instance configuration on all implementations. 
