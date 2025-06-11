#pragma once
#include "BSTEyt.h"
#include <cstddef>

template<class Key>
class BSTEytPrefTwo : public BSTEyt<Key> {
    using Base = BSTEyt<Key>;

public:
    bool contains(const Key& k) const override {
        const_cast<BSTEytPrefTwo*>(this)->Base::freeze();
        const auto& a = Base::arr_;

        std::size_t i = 0;
        while (i < a.size()) {
            std::size_t l  = 2*i + 1;
            std::size_t r  = l + 1;
            if (l < a.size()) __builtin_prefetch(&a[l], 0, 1);
            if (r < a.size()) __builtin_prefetch(&a[r], 0, 1);

            std::size_t ll = 4*i + 3;   // (2*l)+1
            std::size_t lr = ll + 2;    // (2*l)+3
            std::size_t rl = 4*i + 5;   // (2*r)+1
            std::size_t rr = rl + 2;    // (2*r)+3

            if (ll < a.size()) __builtin_prefetch(&a[ll], 0, 1);
            if (lr < a.size()) __builtin_prefetch(&a[lr], 0, 1);
            if (rl < a.size()) __builtin_prefetch(&a[rl], 0, 1);
            if (rr < a.size()) __builtin_prefetch(&a[rr], 0, 1);

            if      (k == a[i]) return true;
            else if (k <  a[i]) i = l;
            else                i = r;
        }
        return false;
    }
};
