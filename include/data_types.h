#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include <iostream>

class free_list_node {
public:
    free_list_node *next;
    int value;
protected:
    free_list_node();
};

class free_list : private free_list_node {
public:
    free_list();
    free_list_node *root;
    int at(int); // get value at index
    int add_node(int); // add node to the end of the list
    int remove_node(int); // remove node at index
    // int remove_value(int); // remove node with value
    // int remove_last(); // remove last node
    // int insert_at(int, int); // insert node at index
};


class double_list_node {
public:
    double_list_node *next;
    double_list_node *prev;
    int value;
};

// class double_list : private double_list_node {
// public:
//     double_list();
//     double_list_node *root;
//     int at(int); // get value at index
//     int add_node(int); // add node to the end of the list
//     int remove_node(int); // remove node at index
// };


template <typename T>
class binary_tree_node {
public:
    T value;

protected:
    binary_tree_node *left;
    binary_tree_node *right;
};

template <typename T>
class binary_tree : private binary_tree_node<T> {
public:
    binary_tree();

    void preorder_visit(binary_tree_node<T> *);
    void postorder_visit(binary_tree_node<T> *);
    void in_order_visit(binary_tree_node<T> *);

private:
    binary_tree_node<T> *root;
    void visit(binary_tree_node<T> *);
};

#endif // DATA_TYPES_H