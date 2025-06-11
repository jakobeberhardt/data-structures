#pragma once
#include "BSTEyt.h"
#include <cstddef>


template<class Key>
class BSTEytPref : public BSTEyt<Key> {
    using Base = BSTEyt<Key>;

public:
    bool contains(const Key& k) const override {
        const_cast<BSTEytPref*>(this)->Base::freeze();

        const auto& a = Base::arr_;   
        std::size_t i = 0;

        while (i < a.size()) {
            std::size_t l = 2*i + 1;
            std::size_t r = l + 1;
            if (l < a.size()) __builtin_prefetch(&a[l], 0, 1);
            if (r < a.size()) __builtin_prefetch(&a[r], 0, 1);

            if      (k == a[i]) return true;
            else if (k <  a[i]) i = l;
            else                i = r;
        }
        return false;
    }
};
