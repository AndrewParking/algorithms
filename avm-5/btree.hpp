#pragma once


template <typename T> struct Node
{

    Node(T value): value_(value), left_child_(NULL), right_child_(NULL) {}

    T get_value() const { return value_; }

    Node * get_left_child() { return left_child_; }
    void set_left_child(Node<T> * child) { left_child_ = child; }
    bool has_left_child() { return left_child_ != NULL; }

    Node * get_right_child() { return right_child_; }
    void set_right_child(Node<T> * child) { right_child_ = child; }
    bool has_right_child() { return right_child_ != NULL; }

private:

    T value_;
    Node<T> * left_child_;
    Node<T> * right_child_;
};


template <typename T> struct BinaryTree
{

    BinaryTree(): root_(NULL) {}

    ~BinaryTree()
    {
        this->_perform_cleanup(this->root_);
    }

    void insert_node(T value)
    {
        Node<T> * child = new Node<T>(value);
        if (this->root_ != NULL) this->_perform_insert(this->root_, child);
        else this->root_ = child;
    }

    void left_root_right_traverse() const
    {
        this->_perform_left_root_right_traversal(this->root_);
    }

    void root_left_right_traverse() const
    {
        this->_perform_root_left_right_traverse(this->root_);
    }

    void left_right_root_traverse() const
    {
        this->_perform_left_right_root_traverse(this->root_);
    }

private:

    void _perform_cleanup(Node<T> * node)
    {
        if (node->has_left_child()) this->_perform_cleanup(node->get_left_child());
        if (node->has_right_child()) this->_perform_cleanup(node->get_right_child());
        delete node;
    }

    void _perform_insert(Node<T> * parent, Node<T> * child)
    {
        if (parent->get_value() > child->get_value())
        {
            if (!parent->has_left_child()) parent->set_left_child(child);
            else this->_perform_insert(parent->get_left_child(), child);
        }
        else if (parent->get_value() < child->get_value())
        {
            if (!parent->has_right_child()) parent->set_right_child(child);
            else this->_perform_insert(parent->get_right_child(), child);
        }
        else return;
    }

    void _perform_left_root_right_traversal(Node<T> * node) const
    {
        if (node->has_left_child()) this->_perform_left_root_right_traversal(node->get_left_child());
        std::cout << node->get_value() << std::endl;
        if (node->has_right_child()) this->_perform_left_root_right_traversal(node->get_right_child());
    }

    void _perform_root_left_right_traverse(Node<T> * node) const
    {
        std::cout << node->get_value() << std::endl;
        if (node->has_left_child()) this->_perform_root_left_right_traverse(node->get_left_child());
        if (node->has_right_child()) this->_perform_root_left_right_traverse(node->get_right_child());
    }

    void _perform_left_right_root_traverse(Node<T> * node) const
    {
        if (node->has_left_child()) this->_perform_left_right_root_traverse(node->get_left_child());
        if (node->has_right_child()) this->_perform_left_right_root_traverse(node->get_right_child());
        std::cout << node->get_value() << std::endl;
    }

    Node<T> * root_;

};
