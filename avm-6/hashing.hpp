#pragma once


struct AbstractHashTable
{
    virtual void insert_key(int) = 0;
    virtual void print_table() const = 0;
};


struct LinearHashTable : AbstractHashTable
{

    LinearHashTable(int);
    ~LinearHashTable();
    void insert_key(int);
    void print_table() const;

private:

    int size_;
    int * storage_;

};


struct ListNode
{
    ListNode(int);
    int get_value() const;
    ListNode * get_next();
    bool has_next() const;
    void set_next(ListNode *);

private:

    int value_;
    ListNode * next_;
};


struct ChainedHashTable : AbstractHashTable
{
    ChainedHashTable(int);
    ~ChainedHashTable();
    void insert_key(int);
    void print_table() const;

private:

    void _perform_cleanup(ListNode *);

    int size_;
    ListNode ** storage_;
};
