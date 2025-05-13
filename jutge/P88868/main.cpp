#include <bits/stdc++.h>
using namespace std;

const int MAX_TOTAL_CHARS = 1000000; 
const int MAX_NODES       = MAX_TOTAL_CHARS + 1;  

struct Node {
    int next[26];
    int cnt = 0;
    bool term = false;

    Node() { fill(begin(next), end(next), -1); }
};

struct SuffixDS {
    vector<Node> t;
    vector<int>  path;     
    SuffixDS() {
        t.reserve(MAX_NODES);
        t.emplace_back();          
        path.reserve(100);         
    }

    void reset() {
        t.clear();                  
        t.emplace_back();
    }

    bool insert(const string& s) {
        int v = 0;  path.clear();
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = (int)t.size();
                t.emplace_back();
            }
            v = t[v].next[c];
            path.push_back(v);
        }
        if (t[v].term) return true;
        t[v].term = true;
        for (int u : path) ++t[u].cnt;
        return false;
    }

    bool erase(const string& s) {
        int v = 0;  path.clear();
        for (char ch : s) {
            int c = ch - 'a';
            v = t[v].next[c];
            if (v == -1) return false; 
            path.push_back(v);
        }
        if (!t[v].term) return false;
        t[v].term = false;
        for (int u : path) --t[u].cnt;
        return true;
    }

    int count(const string& s) const {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            v = t[v].next[c];
            if (v == -1) return 0;
        }
        return t[v].cnt;
    }
};

int main() {
    cin.tie(nullptr);

    SuffixDS D;
    string s;
    char   op;

    while (cin >> op) {
        if (op == 'R') {
            D.reset();
            cout << "---\n";
            continue;
        }

        cin >> s;
        reverse(s.begin(), s.end());   

        if (op == 'I')      D.insert(s);
        else if (op == 'E') D.erase(s);
        else if (op == 'C') cout << D.count(s) << '\n';
    }
    return 0;
}
