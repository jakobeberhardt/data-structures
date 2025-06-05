#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1'000'000'000LL;          

struct Node {
    int        val;
    int        pri; 
    Node      *l, *r;
    int        sz;
    long long  sm;
    Node(int v) : val(v), pri((rand()<<16)^rand()), l(nullptr), r(nullptr), sz(1), sm(v) {}
};

struct Treap {
    Node *root;
    Treap() { root = new Node(0); }

    static int        size(Node* n) { return n ? n->sz : 0; }
    static long long  sum (Node* n) { return n ? n->sm : 0; }

    static void upd(Node* t) {
        if (!t) return;
        t->sz = 1 + size(t->l) + size(t->r);
        t->sm = t->val + sum(t->l) + sum(t->r);
    }

    static void split_rank(Node* t, int k, Node*& a, Node*& b) {
        if (!t) { a = b = nullptr; return; }
        if (size(t->l) >= k) { 
            split_rank(t->l, k, a, t->l);
            b = t;
            upd(b);
        } else {
            split_rank(t->r, k - size(t->l) - 1, t->r, b);
            a = t;
            upd(a);
        }
    }

    static void split(Node* t, int key, Node*& a, Node*& b) {
        if (!t) { a = b = nullptr; return; }
        if (t->val < key) {
            split(t->r, key, t->r, b);
            a = t;
            upd(a);
        } else {
            split(t->l, key, a, t->l);
            b = t;
            upd(b);
        }
    }

    static Node* merge(Node* a, Node* b) {
        if (!a || !b) return a ? a : b;
        if (a->pri > b->pri) {
            a->r = merge(a->r, b);
            upd(a);
            return a;
        }
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }

    static bool find(Node* t, int key) {
        while (t) {
            if (t->val == key) return true;
            t = (key < t->val) ? t->l : t->r;
        }
        return false;
    }

    void insert(int key) {
        if (find(root, key)) return; 
        Node *l, *r;
        split(root, key, l, r);      
        root = merge(merge(l, new Node(key)), r);
    }

    long long range_sum(int i, int j) {        
        Node *A, *B, *C, *D;
        split_rank(root, i - 1, A, B); 
        split_rank(B, j - i + 1, C, D); 
        long long ans = sum(C);
        root = merge(A, merge(C, D));
        return ans;
    }

    int size() const { return size(root); }
};

int main() {
    
    srand(42);

    int m;
    while (cin >> m && m) {
        Treap S;
        
		for (int ins = 0; ins < m; ++ins) {
            long long y; int i, j;
            cin >> y >> i >> j;
            long long seg = S.range_sum(i, j);
            int z = int( (y + seg) % MOD );

            if (Treap::find(S.root, z)) {
                cout << "R " << z << '\n';
            } else {
                S.insert(z);
                cout << "I " << z << '\n';
            }
        }
        cout << "----------\n";
    }
    return 0;
}
