#include <iostream>
#include "btree.hpp"


int main()
{
    int nodes_count;
    BinaryTree<int> * btree = new BinaryTree<int>();

    std::cout << "Enter nodes count:" << std::endl;
    std::cin >> nodes_count;

    for (int i = 0; i < nodes_count; ++i)
    {
        int value;
        std::cout << "Enter " << i << " node value:" << std::endl;
        std::cin >> value;
        btree->insert_node(value);
    }

    btree->left_right_root_traverse();

    return 0;
}
