#pragma once
#include "BSTEyt.h"
#include <cstddef>
#include <array>
#include <algorithm>
#include <cmath>


template<class Key, std::size_t Budget = 8>
class BSTEytPrefProb : public BSTEyt<Key> {
    using Base = BSTEyt<Key>;
    static_assert(Budget >= 2, "Budget must be at least two");


    static inline void pf(const std::vector<Key>& a, std::size_t idx)
    {
        if (idx < a.size()) __builtin_prefetch(&a[idx], 0, 1);
    }

    static void prefetchSubtree(const std::vector<Key>& a,
                                std::size_t            start,
                                std::size_t&           quota)
    {
        if (quota == 0 || start >= a.size()) return;

        std::array<std::size_t, Budget> q{};
        std::size_t front = 0, back = 0;
        q[back++] = start;

        while (front < back && quota) {
            std::size_t parent = q[front++];
            std::size_t l = 2 * parent + 1;
            std::size_t r = l + 1;

            if (l < a.size() && quota) {
                pf(a, l); --quota;
                if (quota && back < q.size()) q[back++] = l;
            }
            if (r < a.size() && quota) {
                pf(a, r); --quota;
                if (quota && back < q.size()) q[back++] = r;
            }
        }
    }

    mutable bool minmax_ready_ = false;
    mutable Key  min_key_{};
    mutable Key  max_key_{};

    [[gnu::always_inline]] inline void ensureMinMax() const
    {
        if (__builtin_expect(minmax_ready_, 1)) [[likely]]
            return;

        const auto& a = Base::arr_;
        if (__builtin_expect(a.empty(), 0)) [[unlikely]] return;                      
        auto [mn, mx] = std::minmax_element(a.begin(), a.end());
        min_key_ = *mn;
        max_key_ = *mx;
        minmax_ready_ = true;
    }

public:
    bool contains(const Key& k) const override
    {
        const_cast<BSTEytPrefProb*>(this)->Base::freeze();
        const auto& a = Base::arr_;
        if (a.empty()) return false;

        ensureMinMax();

        double ratio = (max_key_ == min_key_)
                     ? 0.5
                     : double(k - min_key_) / double(max_key_ - min_key_);
        ratio = std::clamp(ratio, 0.0, 1.0);

        std::size_t spent = 0;
        std::size_t i = 0;                
        std::size_t l = 1;                  
        std::size_t r = 2;                  

        if (l < a.size()) { pf(a, l); ++spent; }
        if (r < a.size()) { pf(a, r); ++spent; }

        std::size_t remaining = (Budget > spent) ? Budget - spent : 0;
        std::size_t left_budget  = std::size_t(std::round(remaining * (1.0 - ratio)));
        if (left_budget > remaining) left_budget = remaining;    
        std::size_t right_budget = remaining - left_budget;

        prefetchSubtree(a, l, left_budget);
        prefetchSubtree(a, r, right_budget);

        while (i < a.size()) {
            const Key& key = a[i];
            if (k == key) return true;
            i = (k < key) ? 2 * i + 1 : 2 * i + 2;
        }
        return false;
    }
};
