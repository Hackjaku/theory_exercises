#include "data_types.h"

int max(int a, int b) {
    return a > b ? a : b;
}

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

template <typename T>
int binary_tree<T>::count(binary_tree_node<T> *subroot) {
    if (subroot == nullptr) {
        return 0;
    }
    return 1 + count(subroot->left) + count(subroot->right);
}

template <typename T>
queue<T>::queue() {
    root = nullptr;
}

template <typename T>
void queue<T>::enqueue(T value) {
    queue_node<T> *new_node;
    new_node->value = value;
    new_node->next = nullptr;
    if (root == nullptr) {
        root = new_node;
    } else {
        queue_node<T> *current = root;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}

template <typename T>
T queue<T>::dequeue() {
    if (root == nullptr) {
        throw "queue is empty";
    }
    T value = root->value;
    auto tmp = root->next;
    delete root;
    root = tmp;
    return value;
}

template <typename T>
bool queue<T>::is_empty() {
    return root == nullptr;
}

template <typename T>
void binary_tree<T>::breadth_first_visit(binary_tree_node<T> *subroot) {
    queue<binary_tree_node<T> *> q; // creo una coda dove salvare i nodi da visitare
    q.enqueue(subroot); // inserisco il nodo radice nella coda
    while (!q.is_empty()) {
        visit(q.dequeue()); // visito il nodo in testa alla coda
        // TODO verifica che non siano nullptr
        q.enqueue(subroot->left); // inserisco il nodo sinistro nella coda
        q.enqueue(subroot->right); // inserisco il nodo destro nella coda
    }
}

template <typename T>
T binary_tree_array<T>::get_father(int index) {
    return data[(index - 1) / 2];
}

template <typename T>
T binary_tree_array<T>::get_left_son(int index) {
    return data[2 * index + 1];
}

template <typename T>
T binary_tree_array<T>::get_right_son(int index) {
    return data[2 * i + 2];
}

template <typename T>
T binary_tree_array<T>::get_brother(int index) {
    if (index % 2 == 0) {
        return data[index - 1];
    } else {
        return data[index ++ 1];
    }
}

template <typename T>
int avl_tree<T>::node_height(avl_tree_node<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

template <typename T>
avl_tree_node<T>* avl_tree<T>::rotate_left(avl_tree_node<T>* subroot) {
    // ruoto verso sinistra il sottoalbero con radice subroot
    avl_tree_node<T> *new_subroot = subroot->right;
    avl_tree_node<T> *T2 = new_subroot->left;

    new_subroot->left = subroot;
    subroot->right = T2;

    subroot->height = max(node_height(x->left), node_height(x->right)) + 1;
    new_subroot->height = max(node_height(new_subroot->left), node_height(new_subroot->right)) + 1;

    return new_subroot;
}

template <typename T>
avl_tree_node<T>* avl_tree<T>::rotate_right(avl_tree_node<T>* subroot) {
    // ruoto verso sinistra il sottoalbero con radice subroot
    avl_tree_node<T> *new_subroot = subroot->left;
    avl_tree_node<T> *T2 = new_subroot->right;

    new_subroot->right = subroot;
    subroot->left = T2;

    subroot->height = max(node_height(subroot->left), node_height(subroot->right)) + 1;
    new_subroot->height = max(node_height(new_subroot->left), node_height(new_subroot->right)) + 1;

    return new_subroot;
}

template <typename T>
int avl_tree<T>::get_balance(avl_tree_node<T>* subroot) {
    return node_height(subroot->left) - node_height(subroot->right);
}

template <typename T>
avl_tree_node<T>* avl_tree<T>::insert(avl_tree_node<T>* subroot, int value) {
    if (subroot == nullptr) {
        return new avl_tree_node<T>(value);
    }
    if (value < subroot->value) {
        subroot->left = insert(subroot->left, value);
    } else if (value > subroot->value) {
        subroot->right = insert(subroot->right, value);
    } else {
        return subroot;
    }

    // l'altezza e' uguale a quella del figlio piu' alto + 1, quindi le foglie hanno altezza 1
    // e la radice ha altezza massima
    node_height = 1 + max(node_height(subroot->left), node_height(subroot->right));

    int balance = get_balance(subroot); // la differenza tra i due sottoalberi

    // il nodo di sinistra e' piu' alto di quello di destra
    // e il valore da inserire va messi a sinistra del figlio di sinistra
    if (balance > 1 && value < subroot->left->value) {
        return rotate_right(subroot); // ruoto a destra
    }

    // il nodo di destra e' piu' alto di quello di sinistra
    // e il valore da inserire va messo a destra del figlio di destra
    if (balance < -1 && value > subroot->right->value) {
        return rotate_left(subroot);
    }

    // il nodo di sinistra e' piu' alto di quello di destra
    // e il valore da inserire va messo a destra del figlio di sinistra
    if (balance > 1 && value > subroot->left->value) {
        subroot->left = rotate_left(subroot->left);
        return rotate_right(subroot);
    }

    // il nodo di destra e' piu' alto di quello di sinistra
    // e il valore da inserire va messo a sinistra del figlio di destra
    if (balance < -1 && value < subroot->right->value) {
        subroot->right = rotate_right(subroot->right);
        return rotate_left(subroot);
    }

    return subroot;
}

template <typename T>
splay_tree_node<T>* splay_tree<T>::right_rotate(splay_tree_node<T>* subroot) {
    splay_tree_node<T> *new_subroot = subroot->left;
    subroot->left = new_subroot->right;
    new_subroot->right = subroot;
    return new_subroot
}

template <typename T>
splay_tree_node<T>* splay_tree<T>::left_rotate(splay_tree_node<T>* subroot) {
    splay_tree_node<T> *new_subroot = subroot->right;
    subroot->left = new_subroot->left;
    new_subroot->left = subroot;
    return new_subroot
}

template <typename T>
splay_tree_node<T>* splay_tree<T>::splay(splay_tree_node<T>* subroot, int value) {
    if (subroot == nullptr || subroot->value == value) {
        return subroot;
    }

    if (subroot->value > value) {
        if (subroot->left == nullptr) {
            return subroot;
        }

        if (subroot->left->value == value) {
            subroot->left->left = splay(subroot->left->left, value);

            subroot = right_rotate(subroot);
        } else if (root->left->value < value) {
            subroot->left->right = splay(subroot->left->right, value);

            if (subroot->left->right != nullptr) {
                subroot->left = left_rotate(subroot->left);
            }
        }
        return (subroot->left == nullptr) ? subroot : right_rotate(subroot);
    } else {
        if (subroot->right == nullptr) {
            return subroot;
        }

        if (subroot->right->value > value) {
            subroot->right->left = splay(subroot->right->left, value);

            if (subroot->right->left != nullptr) {
                subroot->right = right_rotate(subroot->right);
            }
        } else if (subroot->right->value < value) {
            subroot->right->right = splay(subroot->right->right, value);
            subroot = left_rotate(subroot);

        }
        return (subroot->right == nullptr) ? subroot : left_rotate(subroot);
    }
}

template <typename T>
max_heap<T>::max_heap(T array[]) {
    this->array = new T[capacity];
    build_heap();
}

template <typename T>
void max_heap<T>::sift_down(int index) {
    while (!is_leaf(index)) { // fin quando non arrivo ad una foglia
        int j = left_child(index); // prendo la posizione del figlio di sinistra
        int rc = right_child(index); // prendo la posizione del figlio di destra

        if ((rc < ARRAY_SIZE) && (data[j] < data[rc])) {
            // se sono ancora nei limiti dell'array e il figlio di destra e' piu' grande di quello di sinistra
            j = rc; // j contiene la posizione del figlio di destra
        }

        if (data[index] >= data[j]) {
            // in questo punto data[j] e' il maggiore tra i due figli di index
            // verifico se la posizione corrente (index) e' maggiore o uguale dell'oggetto in posizione j
            return;
        }

        // se sono qui, la posizione corrente (index) e' minore dell'oggetto in posizione j
        // effettuo lo scambio

        swap(data, index, j);

        // continuo con con la procedura passando a j (che e' il maggiore tra i figli di current index)
        index = j;
    }
}

template <typename T>
void max_heap<T>::build_heap() {
    for (int i = ARRAY_SIZE / 2 - 1; i >= 0; --i) {
        sift_down(i);
    }
}

template <typename T>
bool max_heap<T>::is_leaf(int index) {
    // in questo caso l'indice e' sicuramente una foglia
    if (index >= ARRAY_SIZE || left_child(index) >= ARRAY_SIZE) {
        return false;
    }
    // qui andrebbe implementata anche una logica per vedere se il contenuto dell'array
    // e' popolato oppure no
    return true;
}

template <typename T>
int max_heap<T>::left_child(int index) {
    return 2 * index + 1;
}

template <typename T>
int max_heap<T>::right_child(int index) {
    return 2 * index + 2;
}


template <typename T>
void generic_tree<T>::preorder_visit(gnt_node<T>* subroot) {
    // cout << subroot->value << " ";
    // ho visitato questo nodo
    for (gnt_node<T>* child = subroot->leftmost_child(); child != nullptr; child = child->next_sibling()) {
        // partendo dal figlio piu' a sinistra, eseguo preorder per ognuno dei miei figli
        // usando la funzione next_sibling() dei nodi
        preorder_visit(child);
    }
}