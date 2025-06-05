#include <bits/stdc++.h>
using namespace std;

struct Node {
    string    str;                 
    int       len;                 
    int       pri;               
    Node     *l, *r;             
    int       sz;              
    long long sm;              

    explicit Node(const string& s)
        : str(s),
          len((int)s.size()),
          pri((rand() << 16) ^ rand()),
          l(nullptr), r(nullptr),
          sz(1), sm(len) {}
};

struct Treap {
    Node* root;
    Treap() : root(nullptr) {}

	static int        size(Node* n) { return n ? n->sz : 0; }
    static long long  sum (Node* n) { return n ? n->sm : 0; }

    static void upd(Node* t) {
        if (!t) return;
        t->sz  = 1 + size(t->l) + size(t->r);
        t->sm = t->len + sum(t->l) + sum(t->r);
    }

    static void split(Node* t, int k, Node*& a, Node*& b) {
        if (!t) { a = b = nullptr; return; }
        if (size(t->l) >= k) {
            split(t->l, k, a, t->l);
            b = t;
        } else {
            split(t->r, k - size(t->l) - 1, t->r, b);
            a = t;
        }
        upd(t);
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

    void insert(int i, const string& s) {
        Node *L, *R;
        split(root, i, L, R);
        root = merge(merge(L, new Node(s)), R);
    }

    static char kthChar(Node* t, long long k) {
        long long left = sum(t->l);
        if (k < left) return kthChar(t->l, k);
        k -= left;
        if (k < t->len) return t->str[k];
        return kthChar(t->r, k - t->len);
    }

    char char_at(long long k) const { return kthChar(root, k); }
};

int main() {

    srand(42);

    Treap T;
    string op;
    while (cin >> op && op[0] != 'E') {
        if (op[0] == 'I') {
            string s; int i;
            cin >> s >> i;
            T.insert(i, s);
        } else {
            long long j;
            cin >> j;
            cout << T.char_at(j);
        }
    }
    cout << '\n';

    return 0;
}
