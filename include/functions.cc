#include "data_types.h"

int max_recursive(int a[], int n) {
    if (n == 1) {
        return a[0];
    }
    int max = max_recursive(a + 1, n-1);
    if (max > a[0]) {
        return max;
    } else {
        return a[0];
    }
}

bool recursive_palindrome(int a[], int sx, int dx) {
    if (sx >= dx) {
        return true;
    }
    bool equals = a[sx] == a[dx];
    return equals && recursive_palindrome(a, sx + 1, dx - 1);
}

void dfs_visit(graph* G, int v) {
    // pre_visit(G, v);
    G->set_mark(v, VISITED);
    for (int w = G->first_neighbor(v); w < G->n(); w = G->next_neighbor(v, w)) {
        if (G->get_mark(w) == UNVISITED) {
            dfs_visit(G, w);
        }
    }
    // post_visit(G, v);
}

void graph_traverse(graph* G) {
    for (int v = 0; v < G->n(); ++v) { // per ogni vertice
        G->set_mark(v, UNVISITED); // setto ogni vertice come non visitato
    }

    for (int v = 0; v < G->n(); ++v) {
        if (G->get_mark(v) == UNVISITED) {
            dfs_visit(G, v);
        }
    }
}

// exercise