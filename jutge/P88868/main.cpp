#include <bits/stdc++.h>
using namespace std;

struct Edge {        
    char ch;           
    int  to;            
    int  next;          
};

struct Node {
    int  first;       
    int  subCnt;       
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
        int v = 0;
        static int path[105]; int plen = 0;      
        
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            char c = s[i];
            int u = find_child(v, c);
            if (u == -1) u = add_child(v, c);
            v = u;
            path[plen++] = v;
        }
        if (V[v].term) return;                 
        V[v].term = true;
        for (int i = 0; i < plen; ++i) ++V[path[i]].subCnt;
    }

    void erase(const string& s) {
        int v = 0;
        static int path[105]; int plen = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            v = find_child(v, s[i]);
            if (v == -1) return;                  
            path[plen++] = v;
        }
        if (!V[v].term) return;                   
        V[v].term = false;
        for (int i = 0; i < plen; ++i) --V[path[i]].subCnt;
    }

    int count_suffix(const string& s) const {
        int v = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            v = find_child(v, s[i]);
            if (v == -1) return 0;
        }
        return V[v].subCnt;
    }

    void reset() {
        V.clear(); E.clear();
        V.emplace_back();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie D;
    string op, s;

    while (cin >> op) {
        if (op[0] == 'R') { 
            D.reset();
            cout << "---\n";
        } else {
            cin >> s;
            switch (op[0]) {
                case 'I': D.insert(s); break;
                case 'E': D.erase(s);  break;
                case 'C': cout << D.count_suffix(s) << '\n'; break;
            }
        }
    }
    return 0;
}
