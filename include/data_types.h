class free_list_node {
public:
    free_list_node *next;
    int value;
protected:
    free_list_node();
};

class free_list : free_list_node {
public:
    free_list();
    free_list_node *root;
    int at(int); // get value at index
    int add_node(int); // add node to the end of the list
    int remove_node(int); // remove node at index
    int remove_value(int); // remove node with value
    int remove_last(); // remove last node
    int insert_at(int, int); // insert node at index
};


class double_list_node {
public:
    double_list_node *next;
    double_list_node *prev;
    int value;
};

class double_list : double_list_node {
public:
    double_list();
    double_list_node *root;
    int at(int); // get value at index
    int add_node(int); // add node to the end of the list
    int remove_node(int); // remove node at index
};