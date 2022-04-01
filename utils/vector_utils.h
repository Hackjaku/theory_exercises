#ifndef VECTOR_UTILS
#define VECTOR_UTILS

#include <vector>
#include <iostream>

namespace utils::vector {

    using namespace std;

    template <class T>
    bool contains(T i, std::vector<T> list) {
        auto it = find(list.begin(), list.end(), i);
        if (it != list.end()) {
            return true;
        } else {
            return false;
        }
    }

    template <class T>
    int index_of(T c, std::vector<T> list) {
        auto it = find(list.begin(), list.end(), c);
        if (it != list.end()) {
            return it - list.begin();
        } else {
            return -1;
        }
    }
}

#endif