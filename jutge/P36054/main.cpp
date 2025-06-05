#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n = 0) { reset(n); }
    void reset(int n) { p.resize(n); iota(p.begin(), p.end(), 0); r.assign(n, 0); }
    int find(int v)     { return p[v] == v ? v : p[v] = find(p[v]); }
    bool unite(int a,int b){
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b] = a;
        if (r[a] == r[b]) ++r[a];
        return true;
    }
};

struct Edge {
    int u,v; long long w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    while (cin >> n >> e) {
        if (n == 0) break;            
        DSU neg(n), nz(n);                      
        vector<Edge> pos;              
        long long negSum = 0;
        int  negCnt = 0, zeroCnt = 0;

        for (int i = 0; i < e; ++i) {
            int u, v; long long w;  cin >> u >> v >> w;

            if (w < 0) {                      
                negSum += w; ++negCnt;
                if (u != v) { neg.unite(u,v);  nz.unite(u,v); }
            }
            else if (w == 0) {                 
                ++zeroCnt;
                if (u != v) nz.unite(u,v);
            }
            else if (u != v)                   
                pos.push_back({u,v,w});
        }

        int compNeg = 0;
        {
            vector<char> seen(n,0);
            for (int v = 0; v < n; ++v)
                if (!seen[neg.find(v)]) {
                    seen[neg.find(v)] = 1;
                    ++compNeg;
                }
        }

        int compNZ = 0;
        {
            vector<char> seen(n,0);
            for (int v = 0; v < n; ++v)
                if (!seen[nz.find(v)]) {
                    seen[nz.find(v)] = 1;
                    ++compNZ;
                }
        }

        sort(pos.begin(), pos.end());
        long long posSum   = 0;
        int       posTaken = 0;                 
        for (auto &e : pos) {
            if (nz.unite(e.u, e.v)) {
                posSum   += e.w;
                ++posTaken;
                if (posTaken == compNZ - 1) break;
            }
        }

        long long c = negSum + posSum;            
        long long m = negCnt + (compNeg - 1);     
        long long M = negCnt + zeroCnt + posTaken;  

        cout << c << ' ' << m << ' ' << M << '\n';
    }
    return 0;
}
