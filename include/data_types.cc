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