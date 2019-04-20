#include "solution.h"
#include <iostream>

int main()
{
    LRUCache cache = LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl;
    cache.put(3, 3);    // evicts key 2
    std::cout << cache.get(2) << std::endl;
    cache.put(4, 4);    // evicts key 1
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(4) << std::endl;

    return 0;
}
