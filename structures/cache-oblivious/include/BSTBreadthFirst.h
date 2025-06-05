#pragma once
#include "IBST.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace detail_bf {
template<class Key>
void build_heap(std::vector<Key>& out, std::size_t idx,
                const std::vector<Key>& in,
                std::size_t lo, std::size_t hi)
{
    if (lo >= hi) return;
    std::size_t mid = (lo + hi) / 2;     
    out[idx]        = in[mid];
    build_heap(out, 2*idx + 1, in, lo,     mid);      
    build_heap(out, 2*idx + 2, in, mid + 1, hi);      
}
}

template<class Key>
class BSTBreadthFirst : public IBST<Key> {
    std::vector<Key> a_;     
    std::vector<Key> inserts_;   
    bool frozen_ = false;

    void freeze()
    {
        if (frozen_) return;
        if (inserts_.empty())
            throw std::logic_error("empty tree");

        std::sort(inserts_.begin(), inserts_.end());
        inserts_.erase(std::unique(inserts_.begin(), inserts_.end()),
                       inserts_.end());

        std::size_t pow2 = 1;
        while (pow2 < inserts_.size()) pow2 <<= 1;
        a_.assign(pow2 - 1, inserts_.back());          

        detail_bf::build_heap(a_, 0, inserts_, 0, inserts_.size());
        frozen_ = true;
        inserts_.clear();                            
        inserts_.shrink_to_fit();
    }

public:
    void insert(const Key& k) override
    {
        if (frozen_)
            throw std::logic_error("insert() after first contains()");
        inserts_.push_back(k);
    }

    bool contains(const Key& k) const override
    {
        const_cast<BSTBreadthFirst*>(this)->freeze();

        std::size_t i = 0;
        while (i < a_.size()) {
            if (k == a_[i]) return true;
            i = (k < a_[i]) ? 2*i + 1 : 2*i + 2;
        }
        return false;
    }
};
