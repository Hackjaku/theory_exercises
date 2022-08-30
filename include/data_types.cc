#include "data_types.h"

int free_list::at(int index) {
    free_list_node *current = root;
    for (int i = 0; i < index; ++i) {
        if (current == nullptr) {
            throw "index out of bounds";
        }
        if (i == index) {
            return current->value;
        }
        current = current->next;
    }
}

free_list::free_list() {
    root = nullptr;
}

int free_list::add_node(int value) {
    free_list_node *new_node;
    new_node->value = value;
    new_node->next = nullptr;

    if (root == nullptr) {
        root = new_node;
    } else {
        free_list_node *current = root;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    return 0;
}

int free_list::remove_node(int index) {
    free_list_node *current = root;
    for (int i = 0; i < index; ++i) {
        if (current == nullptr) {
            throw "index out of bounds";
        }
        if (i == index) {
            auto temp = current->next->next;
            delete current->next;
            current->next = temp;
            return 0;
        }
        current = current->next;
        return 0;
    }
}

template <typename T>
binary_tree<T>::binary_tree() {
    root = nullptr;
}

// define preorder function
template <typename T>
void binary_tree<T>::preorder_visit(binary_tree_node<T> *subroot) {
    // e' meglio il controllo se il nodo attuale è nullo piuttosto che verificare se i figli sono nulli
    if (subroot == nullptr) {
        return;
    }
    visit(subroot); // visito il nodo corrente
    preorder(subroot->left); // figlio di sinistra
    preorder(subroot->right); // figlio di destra
}

template <typename T>
void binary_tree<T>::visit(binary_tree_node<T> *subroot) {
    std::cout << subroot->value << " ";
}

template <typename T>
void binary_tree<T>::postorder_visit(binary_tree_node<T> *subroot) {
    if (subroot == nullptr) {
        return;
    }
    postorder(subroot->left); // figlio di sinistra
    postorder(subroot->right); // figlio di destra
    visit(subroot); // visito il nodo corrente
}

template <typename T>
void binary_tree<T>::in_order_visit(binary_tree_node<T> *subroot) {
    if (subroot == nullptr) {
        return;
    }
    preorder(subroot->left); // figlio di sinistra
    visit(subroot); // visito il nodo corrente
    preorder(subroot->right); // figlio di destra
}