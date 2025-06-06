#pragma once
#include "IBST.h"
#include <vector>
#include <algorithm>
#include <stdexcept>


namespace detail {
template<class Key>
void build_veb(std::vector<Key>& out,
               const std::vector<Key>& sorted, std::size_t lo, std::size_t hi)
{
    if (lo >= hi) return;                       
    std::size_t mid = (lo + hi) / 2;            
    out.push_back(sorted[mid]);                 
    build_veb(out, sorted, lo, mid);            
    build_veb(out, sorted, mid + 1, hi);        
}
} 

template<class Key>
class BSTVEB : public IBST<Key> {
    std::vector<Key> a_;            
    bool              frozen_ = false;
    std::vector<Key>  inserts_;     


    void freeze() {
        if (frozen_) return;

        std::sort(inserts_.begin(), inserts_.end());
        inserts_.erase(std::unique(inserts_.begin(), inserts_.end()),
                       inserts_.end());

        a_.reserve(inserts_.size());
        detail::build_veb(a_, inserts_, 0, inserts_.size());
        frozen_ = true;
    }

    bool containsRec(const Key& k,
                     std::size_t lo, std::size_t hi, std::size_t idx) const
    {
        if (lo >= hi) return false;            

        const Key& key = a_[idx];
        if (k == key) return true;

        std::size_t mid        = (lo + hi) / 2;
        std::size_t left_size  = mid - lo;    
        std::size_t left_idx   = idx + 1;   
        std::size_t right_idx  = idx + 1 + left_size;

        return (k < key)
             ? containsRec(k, lo, mid,           left_idx)
             : containsRec(k, mid + 1, hi,       right_idx);
    }

public:
    void insert(const Key& k) override {
        if (frozen_)
            throw std::logic_error("I am already frozen!");
        inserts_.push_back(k);
    }

    bool contains(const Key& k) const override {
        const_cast<BSTVEB*>(this)->freeze();   
        return containsRec(k, 0, a_.size(), 0);
    }
};
