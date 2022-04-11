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

    template <class T>
    void remove(T c, std::vector<T> &list) {
        list.erase(std::remove(list.begin(), list.end(), c), list.end());
    }

    template <class T>
    std::vector<T> remove_all(std::vector<T> to_remove, std::vector<T> list) {
        for (auto c : to_remove) {
            remove(c, list);
        }
        return list;
    }

    template <class T>
    std::vector<T> unique_union(std::vector<T> list1, std::vector<T> list2) {
        std::vector<T> list;
        for (auto c : list1) {
            list.push_back(c);
        }
        for (auto c : list2) {
            list.push_back(c);
        }
        sort(list.begin(), list.end());
        list.erase(unique(list.begin(), list.end()), list.end());
        return list;
    }
}

#endif