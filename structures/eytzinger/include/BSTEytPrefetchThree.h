#pragma once
#include "BSTEyt.h"
#include <cstddef>

template<class Key>
class BSTEytPrefThree : public BSTEyt<Key> {
    using Base = BSTEyt<Key>;

public:
    bool contains(const Key& k) const override
    {
        const_cast<BSTEytPrefThree*>(this)->Base::freeze();
        const auto& a = Base::arr_;

        auto pf = [&](std::size_t idx) {
            if (idx < a.size()) __builtin_prefetch(&a[idx], 0, 1);
        };

        std::size_t i = 0;
        while (i < a.size()) {

            std::size_t l = 2*i + 1;
            std::size_t r = l + 1;
            pf(l); pf(r);

            std::size_t ll = 2*l + 1;
            std::size_t lr = ll + 1;
            std::size_t rl = 2*r + 1;
            std::size_t rr = rl + 1;
            pf(ll); pf(lr); pf(rl); pf(rr);

            pf(2*ll + 1); pf(2*ll + 2);
            pf(2*lr + 1); pf(2*lr + 2);
            pf(2*rl + 1); pf(2*rl + 2);
            pf(2*rr + 1); pf(2*rr + 2);

            if      (k == a[i]) return true;
            else if (k <  a[i]) i = l;
            else                i = r;
        }
        return false;
    }
};
