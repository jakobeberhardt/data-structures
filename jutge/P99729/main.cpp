#include <bits/stdc++.h>
using namespace std;

struct ItTree {
    int n;                     
    vector<long long> bit;
    ItTree(int N = 0) { init(N); }
    void init(int N) { n = N; bit.assign(n + 1, 0); }
    void add(int idx, long long v) {              
        for (; idx <= n; idx += idx & -idx) bit[idx] += v;
    }
    long long sum(int idx) const {                
        long long s = 0;
        for (; idx; idx -= idx & -idx) s += bit[idx];
        return s;
    }
};

int main() {
    cin.tie(nullptr);

    int n, q;
    while (cin >> n >> q) {
        vector<long long> a(n, 0);        
        ItTree ft(n);
        multiset<long long> ms;           
        ms.insert(a.begin(), a.end());

        long long base = 1;               
        long long sumA = 0;               

        while (q--) {
            long long x; int good; cin >> x >> good;

            int lo = 1, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                long long pref = base * mid + ft.sum(mid);
                if (pref > x) hi = mid;
                else           lo = mid + 1;
            }
            int idx = lo - 1;                

            ms.erase(ms.find(a[idx]));
            long long diff = (good ? -1 : +1);
            a[idx] += diff;
            sumA   += diff;
            ft.add(idx + 1, diff);
            ms.insert(a[idx]);

            if (a[idx] + base == 0) {
                ++base;                      
            } else if (*ms.begin() + base == 2) {
                --base;                      
            }
        }

        long long total = 1LL * n * base + sumA;
        for (int i = 0; i < n; ++i) {
            long long num = base + a[i];
            long long g   = std::gcd(num, total);
            cout << num / g << '/' << total / g << '\n';
        }
        cout << '\n';
    }
    return 0;
}
