#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#define ARRAY_SIZE 100


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


template <typename T>
class queue_node {
public:
    T value;
protected:
    queue_node();
    queue_node *next;
};


template <typename T>
class queue : private queue_node<T> {
public:
    queue();
    void enqueue(T); // add node to the end of the list
    T dequeue(); // remove node at index
    bool is_empty(); // check if queue is empty
private:
    queue_node<T> *root;
};

// class double_list_node {
// public:
//     double_list_node *next;
//     double_list_node *prev;
//     int value;
// };

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
    void breadth_first_visit(binary_tree_node<T> *);

    int count(binary_tree_node<T> *);

private:
    binary_tree_node<T> *root;
    void visit(binary_tree_node<T> *);
};

template <typename T>
class binary_tree_array {
public:
    binary_tree_array();

    T get_father(int);
    T get_left_son(int);
    T get_right_son(int);
    T get_brother(int);
protected:
    T data[ARRAY_SIZE];
};


template <typename T> // uso una template, ma occorre avere sempre un tipo per cui e' definito ordinamento
class avl_tree_node {
public:
    T value;
protected:
    avl_tree_node();
    avl_tree_node *left;
    avl_tree_node *right;
    int height;
};

template <typename T>
class avl_tree : private avl_tree_node<T> {
public:
    avl_tree();

private:
    avl_tree_node<T> *root;
    int node_height(avl_tree_node<T> *); // ottieni altezza del nodo

    avl_tree_node<T> *rotate_right(avl_tree_node<T> *);
    avl_tree_node<T> *rotate_left(avl_tree_node<T> *);

    int get_balance(avl_tree_node<T> *);
    avl_tree_node<T> *insert(avl_tree_node<T> *, int);
};

#endif // DATA_TYPES_H