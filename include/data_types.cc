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