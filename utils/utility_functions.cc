#include "utility_functions.h"

template <typename T>
void swap(T array[], int i, int j) {
    T tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}