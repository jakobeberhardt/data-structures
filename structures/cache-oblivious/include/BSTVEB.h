#pragma once
#include "IBST.h"
#include <vector>
#include <cstddef>
#include <algorithm>

namespace detail {
template<class Key>
void build_veb(std::vector<Key>& out, size_t idx,
               const std::vector<Key>& in, size_t lo, size_t hi) {
    if (lo >= hi) return;
    size_t mid = (lo + hi) / 2;              
    out[idx] = in[mid];
    build_veb(out, 2 * idx + 1, in, lo, mid); 
    build_veb(out, 2 * idx + 2, in, mid + 1, hi);
}
}

template<class Key>
class BSTVEB : public IBST<Key> {
    std::vector<Key> a_;       
    bool frozen_ = false;      
    std::vector<Key> inserts_;

    void freeze() {
        if (frozen_) return;
        inserts_.erase(std::unique(inserts_.begin(), inserts_.end()),
                       inserts_.end());
        std::sort(inserts_.begin(), inserts_.end());
        size_t pow2 = 1;
        while (pow2 < inserts_.size()) pow2 <<= 1;
        a_.assign(pow2 - 1, inserts_.back());
        detail::build_veb(a_, 0, inserts_, 0, inserts_.size());
        frozen_ = true;
    }
public:
    void insert(const Key& k) override {
        if (frozen_) throw std::logic_error("insert after first contains()");
        inserts_.push_back(k);
    }
    bool contains(const Key& k) const override {
        const_cast<BSTVEB*>(this)->freeze();
        size_t i = 0;
        while (i < a_.size()) {
            if (k == a_[i]) return true;
            i = (k < a_[i]) ? 2 * i + 1 : 2 * i + 2;
        }
        return false;
    }
};
