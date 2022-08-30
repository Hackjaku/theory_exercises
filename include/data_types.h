class free_list_node {
public:
    free_list_node *next;
    int value;
};

class free_list {
public:
    free_list_node *root;
    int at(int); // get value at index 
};