#include "sort.h"

// caso peggiore: n^2, quando le chiavi sono in ordine inverso
// caso migliore: n, quando le chiavi sono gia' ordinate
// caso medio: n^2 (sarebbe n^2/2, ma il tasso di crescita non dipende dalle costanti)

template <typename T>
void insertion_sort(T array[], int n) {
    for (int i = 1; i < n; ++i) { // parto dal secondo elemento e vado fino alla fine
        for (int j = i; (j > 0) && (array[j] < array[j - 1]); --j) { // parto dall'elemento corrente e mi sposto verso l'inizio
            T tmp = array[j]; // scambiando posizione se i due elementi sono in ordine inverso
            array[j] = array[j - 1];
            array[j - 1] = tmp;
        } // mi fermo quando l'elemento e' piu' grande di quello che lo precede
        // poi procedo con il prossimo elemento
    }
}


// questo algoritmo non dipende dai valori inseriti nell'array, ma solo dalla sua dimensione
// in tutti i casi richiede n^2 operazioni

template <typename T>
void bubble_sort(T array[], int n) {
    for (int i = 0; i < n - 1; ++i) { // parto dal primo elemento, fino alla fine
        for (int j = n - 1; j > i; --j) { // parto dalla fine, fino ad i
            if (array[j] < array[j - 1]) { // scambio se i due elementi sono in ordine inverso
                T tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
}

// questo algoritmo non dipende dai valori inseriti nell'array, ma solo dalla sua dimensione
// in tutti i casi richiede n^2 operazioni

template <typename T>
void selection_sort(T array[], int n) {
    for (int i = 0; i < n - 1; ++i) { // dall'inizio alla fine dell'array
        int lowindex = i; // parto prendendo l'elemento corrente come minore
        for (int j = n - 1; j > i; --j) { // parto dalla fine, fino ad i
            if (array[j] < array[lowindex]) {
                lowindex = j; // se trovo un elemento minore, lo prendo
            }
            // al termine del ciclo, lowindex e' l'indice dell'elemento minore e lo metto in posizione i
            T tmp = array[i];
            array[i] = array[lowindex];
            array[lowindex] = tmp;
        }
    }
}

template <typename T>
void insertion_sort_increment(T array[], int n, int incr) {
    for (int i = incr, i < n; i += incr) { // parto dal primo incremento ed aggiungo ogni volta
        for (int j = i; (j >= incr) && (array[j] < array[j - incr]); j -= incr) { // confronto gli elementi distanti un incremento, andando indietro
            T tmp = array[j]; // in caso li scambio
            array[j] = array[j - incr];
            array[j - incr] = tmp;
        }
    }
}

// se scelgo dei buoni incrementi, ho prestazioni migliori rispetto all'insertion sort originale
template <typename T>
void shell_sort(T array[], int n) {
    for (int i = n / 2; i > 2; i /= 2) { // parto dalla meta' e dimezzo ogni volta
        for (int j = 0; j < i; ++j) { // parto da zero ed arrivo fino ad i, uno alla volta
            insertion_sort_increment(array, n - j, i); 
        }
        insertion_sort_increment(array, n, 1);
    }
}