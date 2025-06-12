#include <cassert>
#include <vector>
#include <iostream>

#include "../include/BSTVEB.h"
#include "../include/BSTEyt.h"
#include "../include/BSTEytPrefetch.h"
#include "../include/BSTEytPrefetchTwo.h"
#include "../include/BSTEytPrefetchThree.h"
#include "../include/BSTEytPrefetchFour.h"
#include "../include/BSTEytPrefetchProb.h"


template<class Tree>
void sanity_check(std::size_t N = 1'024)
{
    Tree t;
    for (std::size_t i = 0; i < N; ++i) t.insert(static_cast<int>(i * 2));

    for (std::size_t i = 0; i < N; ++i) {
        int present = static_cast<int>(i * 2);
        int absent  = present + 1;
        assert(t.contains(present) && "key should be present");
        assert(!t.contains(absent) && "key should be absent");
    }
}

int main()
{
    sanity_check< BSTVEB<int>           >();
    sanity_check< BSTEyt<int>           >();
    sanity_check< BSTEytPref<int>       >();
    sanity_check< BSTEytPrefTwo<int>    >();
    sanity_check< BSTEytPrefThree<int>  >();
    sanity_check< BSTEytPrefFour<int>   >();
    sanity_check< BSTEytPrefProb<int>   >();


    std::cout << "all imps contains() tests passed\n";
    return 0;
}
