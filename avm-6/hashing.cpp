#include <iostream>
#include "hashing.hpp"


LinearHashTable::LinearHashTable(int size): size_(size), storage_(new int[size])
{
    for (int i = 0; i < size_; ++i) storage_[i] = 0;
}

LinearHashTable::~LinearHashTable() { delete[] storage_; }

void LinearHashTable::insert_key(int key)
{
    int initial_index = key % size_;
    int counter = 0;

    while (storage_[initial_index] != 0)
    {
        ++counter;
        if (counter > size_) return;
        ++initial_index;
    }

    storage_[initial_index] = key;
}

void LinearHashTable::print_table() const
{
    for (int i = 0; i < size_; ++i)
    {
        std::cout << i << " -> " << storage_[i] << std::endl;
    }
}


ListNode::ListNode(int value): value_(value), next_(NULL) {};

int ListNode::get_value() const { return value_; }

ListNode * ListNode::get_next() { return next_; }

bool ListNode::has_next() const { return next_ != NULL; }

void ListNode::set_next(ListNode * next) { next_ = next; }


ChainedHashTable::ChainedHashTable(int size): size_(size), storage_(new ListNode*[size])
{
    for (int i = 0; i < size_; ++i) storage_[i] = NULL;
}

void ChainedHashTable::_perform_cleanup(ListNode * node)
{
    if (node->has_next()) _perform_cleanup(node->get_next());
    delete node;
}

ChainedHashTable::~ChainedHashTable()
{
    for (int i = 0; i < size_; ++i)
    {
        if (storage_[i] != NULL)  _perform_cleanup(storage_[i]);
    }
}

void ChainedHashTable::insert_key(int key)
{
    int initial_index = key % size_;

    if (storage_[initial_index] == NULL)
    {
        storage_[initial_index] = new ListNode(key);
        return;
    }

    ListNode * node = storage_[initial_index];
    while (node->has_next()) node = node->get_next();

    node->set_next(new ListNode(key));
}

void ChainedHashTable::print_table() const
{
    for (int i = 0; i < size_; ++i)
    {
        if (storage_[i] == NULL)
        {
            std::cout << "-" << std::endl;
            continue;
        }
        ListNode * node = storage_[i];
        while (node != NULL)
        {
            std::cout << node->get_value() << " ";
            node = node->get_next();
        }
        std::cout << std::endl;
    }
}
