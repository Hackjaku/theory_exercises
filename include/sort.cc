#include "sort.h"

// caso peggiore: n^2, quando le chiavi sono in ordine inverso
// caso migliore: n, quando le chiavi sono gia' ordinate
// caso medio: n^2 (sarebbe n^2/2, ma il tasso di crescita non dipende dalle costanti)

template <typename T>
void insertion_sort(T array[], int n) {
    for (int i = 1; i < n; ++i) { // parto dal secondo elemento e vado fino alla fine
        for (int j = i; (j > 0) && (array[j] < array[j - 1]); --j) { // parto dall'elemento corrente e mi sposto verso l'inizio
            swap(array, j, j - 1);
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
                swap(array, j, j - 1);
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
            swap(array, i, lowindex);
        }
    }
}

template <typename T>
void insertion_sort_increment(T array[], int n, int incr) {
    for (int i = incr, i < n; i += incr) { // parto dal primo incremento ed aggiungo ogni volta
        for (int j = i; (j >= incr) && (array[j] < array[j - incr]); j -= incr) { // confronto gli elementi distanti un incremento, andando indietro
            swap(array, j, j - incr);
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

template <typename T>
int find_pivot(T array[], int i, int j) {
    return (i + j) / 2;
}

template <typename T>
int partition(T array[], int l, int r, T pivot) {
    do {
        while (a[++l] < pivot); // salgo con l fino ad un valore maggiore di pivot
        while ((r != 0) && (array[--r] > pivot)); // scendo con r fino ad un valore minore di pivot

        // swap
        swap(array, l, r);
    } while (l < r); // fin quando gli indici non si incrociano

    // effettuo l'ultimo swap per rimettere a posto il valore scambiato "di troppo"
    swap(array, l, r);
    return l;
}

template <typename T>
void quicksort(T array[], int i, int j) {
    if (j < i) {
        return; // la lista e' troppo piccola
    }

    int pivot_index = find_pivot(array, i, j);
    int k = partition<T>(array, i - 1, j, array[j]); // k e' l'indice dell'elemento a sinistra della partizione eseguita

    swap(array, i, j); // scambio l'elemento in posizione i con quello in posizione j

    quicksort(array, i, k - 1);
    quicksort(array, k + 1, j);
}

// in pratica ogni volta dimezzo l'array che viene dato in pasto alla funzione
// che a sua volta dimezza l'array e verifica l'ordinamento delle due meta'

// applicando la ricorsione arrivo ad array con un elemento, che sono ordinati
// al termine della prima ricorsione avro' array con due elementi, che vengono grazie al posizionamento

// continuando il processo avro' sempre array ordinati a confronto, in modo che il primo elemento di ogni
// array sia sempre il minimo

template <typename T>
void merge_sort(T array[], T temp[], int left, int right) {
    int mid = (left + right) / 2;
    if (left == right) {
        return;
    }

    // prima chiamo la ricorsione nelle due metà
    merge_sort<T>(A, temp, left, mid);
    merge_sort<T>(A, temp, mid + 1, right);

    // copio la porzione di array in temp, da destra a sinistra
    for (int i = left; i <= right; ++i) {
        temp[i] = array[i];
    }

    // preparo due cursori, uno sx che parte dall'inizio e uno dx che parte da metà
    int i1 = left, i2 = mid + 1;
    for (int curr = left; curr <= right; ++curr) { // scorro tutto l'array
        if (i1 == mid + 1) { // se il cursore di sx e' arrivato a meta' ho esaurito la prima parte di array
            array[curr] = temp[i2++]; // quindi tutto quello che e' rimasto e' nella seconda porzione di array
        } else if (i2 == right) { // se il cursore di dx e' arrivato alla fine ho esaurito la seconda parte di array
            array[curr] = temp[i1++]; // quindi inserisco i valori della prima parte
        } else if (temp[i1] < temp[i2]) { // sono ancora nella situazione in cui entrambe le porzioni hanno valori
            array[curr] = temp[i1++]; // se quello a sx e' minore, inserisco questo e avanzo il cursore di sx
        } else { // altrimenti inserisco il valore di dx e avanzo il cursore di dx
            array[curr] = temp[i2++];
        }
    }
}

template <typename T>
void heap_sort(T array[], int n) {
    T mval;
    max_heap<T> H(array);
    for (int i = 0; i < n; ++i) {
        H.removemax(mval);
    }
}