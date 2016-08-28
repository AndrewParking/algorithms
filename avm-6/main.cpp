#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hashing.hpp"


int main()
{
    int size;
    int key;

    /* Linear hashtable test */

    // std::cout << "Enter hashtable size:" << std::endl;
    // std::cin >> size;
    //
    // LinearHashTable * ht = new LinearHashTable(size);
    //
    // for (int i = 0; i < size; ++i)
    // {
    //     std::cout << "Enter " << i << " key:" << std::endl;
    //     std::cin >> key;
    //     ht->insert_key(key);
    // }
    //
    // ht->print_table();
    //
    // delete ht;

    /* Chained hashtable test */

    std::cout << "Enter hashtable size:" << std::endl;
    std::cin >> size;

    ChainedHashTable * cht = new ChainedHashTable(size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << "Enter " << i << " key:" << std::endl;
        std::cin >> key;
        cht->insert_key(key);
    }

    cht->print_table();

    delete cht;

    return 0;
}
