#pragma once
#include <cstddef>

template<class Key>
class IBST {
public:
    virtual void insert(const Key& k)                = 0;
    virtual bool contains(const Key& k)        const = 0;
    virtual std::size_t size_bytes()     const = 0;
    virtual ~IBST() = default;
};
