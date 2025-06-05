#pragma once
#include "IBST.h"
#include <memory>
#include <utility>

template<class Key>
class BSTPtr : public IBST<Key> {
    struct Node {
        Key key;
        std::unique_ptr<Node> l, r;
        explicit Node(const Key& k) : key(k) {}
    };

    std::unique_ptr<Node> root_;

    static void insert(std::unique_ptr<Node>& p, const Key& k) {
        if (!p) {
            p = std::make_unique<Node>(k);
        } else if (k < p->key) {
            insert(p->l, k);
        } else if (k > p->key) {
            insert(p->r, k);
        }
    }

    static bool contains(const std::unique_ptr<Node>& p, const Key& k) {
        const Node* cur = p.get();
        while (cur) {
            if (k == cur->key) return true;
            cur = (k < cur->key) ? cur->l.get() : cur->r.get();
        }
        return false;
    }
public:
    void insert  (const Key& k)       override { insert  (root_, k); }
    bool contains(const Key& k) const override { return contains(root_, k); }
};
