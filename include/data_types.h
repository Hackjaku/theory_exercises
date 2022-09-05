#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include <iostream>
#include "../utils/utility_functions.h"
#include "../utils/definitions.h"

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

template <typename T>
class splay_tree_node {
public:
    T value;
protected:
    splay_tree_node();
    splay_tree_node *left;
    splay_tree_node *right;
};

template <typename T>
class splay_tree : private splay_tree_node<T> {
public:
    splay_tree();
    splay_tree_node<T> *insert(splay_tree_node<T> *, int);

private:
    splay_tree_node<T> *root;
    splay_tree_node<T>* right_rotate(splay_tree_node<T> *);
    splay_tree_node<T>* left_rotate(splay_tree_node<T> *);
    splay_tree_node<T>* splay(splay_tree_node<T> *, int);
};

template <typename T>
class max_heap {
public:
    max_heap(T[]);
    void removemax(T);
private:
    void build_heap();
    T data[ARRAY_SIZE];
    void sift_down(int);
    bool is_leaf(int);
    int left_child(int);
    int right_child(int);
};


template <typename T>
class gnt_node {
protected:
    gnt_node();
    T value;
    bool is_leaf();
    gnt_node *parent; // continene il puntatore al padre
    gnt_node *leftmost_child; // continene il puntatore al figlio piu' a sinistra
    gnt_node *right_sibling; // continene il puntatore al fratello alla sua destra

    void insert_first(gnt_node *); // inserisce un figlio
    void insert_next(gnt_node *); // inserisce un fratello
    void remove_first(gnt_node *); // rimuove un figlio
    void remove_next(gnt_node *); // rimuove un fratello
};

template <typename T>
class generic_tree : private gnt_node<T> {
public:
    generic_tree();
    void clear();
private:
    gnt_node<T> *root;
    void new_root(T&, gnt_node<T> *, gnt_node<T> *); // combina due sottoalberi
    void preorder_visit(gnt_node<T> *);
    void verify_order(gnt_node<T> *, bool&);
};

#define UNVISITED 0
#define VISITED 1

class graph {
public:
    virtual int n() = 0; // numero vertici
    virtual int e() = 0; // numero archi

    virtual int first_neighbor(int) = 0; // primo vicino
    virtual int next_neighbor(int, int) = 0; // vicino successivo

    virtual void set_edge(int, int, int) = 0; // inserisce un arco
    virtual void del_edge(int, int) = 0; // rimuove un arco

    virtual int weight(int, int) = 0; // peso di un arco
    virtual int get_mark(int) = 0;
    virtual void set_mark(int, int) = 0;
};

#endif // DATA_TYPES_H