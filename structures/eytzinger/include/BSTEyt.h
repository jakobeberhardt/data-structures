#pragma once
#include "IBST.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

template<class Key>
class BSTEyt : public IBST<Key> {
protected:  
    std::vector<Key> arr_; 
    static void dedupSort(std::vector<Key>& v) {
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
    }

    void buildEyt(std::size_t idx, std::size_t& pos,
                  const std::vector<Key>& sorted)
    {
        if (idx >= sorted.size()) return;
        buildEyt(2*idx + 1, pos, sorted);
        arr_[idx] = sorted[pos++];
        buildEyt(2*idx + 2, pos, sorted);
    }

    void freeze()
    {
        if (frozen_) return;
        dedupSort(inserts_);
        arr_.resize(inserts_.size());
        std::size_t p = 0;
        buildEyt(0, p, inserts_);
        frozen_ = true;
        inserts_.clear();
        inserts_.shrink_to_fit();
    }

private:
    std::vector<Key> inserts_;           
    bool             frozen_ = false;

public:
    void insert(const Key& k) override {
        if (frozen_)
            throw std::logic_error("BST_EYT: insert after first query");
        inserts_.push_back(k);
    }

    bool contains(const Key& k) const override {
        const_cast<BSTEyt*>(this)->freeze();

        std::size_t i = 0;
        while (i < arr_.size()) {
            if (k == arr_[i])           return true;
            i = (k < arr_[i]) ? 2*i + 1 : 2*i + 2;
        }
        return false;
    }

    std::size_t size_bytes() const override {
        return arr_.size() * sizeof(Key);
    }
};
