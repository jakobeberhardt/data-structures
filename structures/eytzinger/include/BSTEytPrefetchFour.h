#pragma once
#include "BSTEyt.h"
#include <cstddef>

template<class Key>
class BSTEytPrefFour : public BSTEyt<Key> {
    using Base = BSTEyt<Key>;

    static inline void pf(const std::vector<Key>& a, std::size_t idx)
    {
        if (idx < a.size()) __builtin_prefetch(&a[idx], 0, 1);
    }

public:
    bool contains(const Key& k) const override
    {
        const_cast<BSTEytPrefFour*>(this)->Base::freeze();
        const auto& a = Base::arr_;

        std::size_t i = 0;
        while (i < a.size()) {

            std::size_t q[32];           
            int front = 0, back = 0;
            q[back++] = i;

            for (int depth = 0; depth < 4; ++depth) {
                int levelCount = back - front;
                for (int n = 0; n < levelCount; ++n) {
                    std::size_t parent = q[front++];
                    std::size_t l = 2*parent + 1;
                    std::size_t r = l + 1;
                    pf(a, l); pf(a, r);
                    q[back++] = l;
                    q[back++] = r;
                }
            }

            if      (k == a[i]) return true;
            else if (k <  a[i]) i = 2*i + 1;
            else                i = 2*i + 2;
        }
        return false;
    }
};
