#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n = 0) { reset(n); }
    void reset(int n) {
        p.resize(n); iota(p.begin(), p.end(), 0);
        r.assign(n, 0);
    }
    int find(int v) { return p[v] == v ? v : p[v] = find(p[v]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) ++r[a];
        return true;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

int main() {
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {             
        long long total = 0;
        vector<Edge> edges;
        edges.reserve(m);

        for (int i = 0; i < m; ++i) {
            int u, v, c; cin >> u >> v >> c;
            total += c;
            edges.push_back({u, v, c});
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);
        long long mst = 0;
        for (const auto& e : edges)
            if (dsu.unite(e.u, e.v))
                mst += e.w;

        cout << (total - mst) << '\n';
    }
    return 0;
}
