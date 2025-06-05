#include <bits/stdc++.h>
using namespace std;

struct Edge {
    char ch; 
    int  to;         
    int  next;       
};

struct Node {
    int first; 
    int subCnt;
    bool term;        
    Node() : first(-1), subCnt(0), term(false) {}
};

class Trie {
    vector<Node> V;
    vector<Edge> E;          

    int find_child(int v, char c) const {
        for (int e = V[v].first; e != -1; e = E[e].next)
            if (E[e].ch == c) return E[e].to;
        return -1;
    }

    int add_child(int v, char c) {
        int u = (int)V.size();
        V.emplace_back();
        int e = (int)E.size();
        E.push_back({c, u, V[v].first});
        V[v].first = e;
        return u;
    }

public:
    Trie() { V.emplace_back(); }

    void insert(const string& s) {
        vector<int> path;
        int v = 0;
        for (char ch : s) {
            int u = find_child(v, ch);
            if (u == -1) u = add_child(v, ch);
            v = u;
            path.push_back(v);
        }
        if (V[v].term) return; 
        V[v].term = true;
        for (int idx : path) ++V[idx].subCnt;
    }

    vector<int> prefixCnt(const string& w) const {
        vector<int> res;
        int v = 0;
        for (char ch : w) {
            int u = find_child(v, ch);
            if (u == -1) { res.push_back(0); break; }
            v = u;
            res.push_back(V[v].subCnt);
            if (V[v].subCnt == 0) break;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        vector<string> tok;
        string w;
        while (ss >> w) tok.push_back(w);

        if (tok.size() == 1) {
            const string& q = tok[0];
            auto res = trie.prefixCnt(q);
            cout << q << ':';
            for (int x : res) cout << ' ' << x;
            cout << '\n';
        }
        else if (tok.size() == 2) {
            trie.insert(tok[0]);                   
        }
    }
    return 0;
}
