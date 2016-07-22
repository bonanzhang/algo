#include "qsort.h"
long partition(int *a, long lo, long hi) {
    int p;
    int temp;
    long i;
    long j;
    p = a[lo];
    i = lo+1;
    for (j = lo+1; j <= hi; j++) {
        if (a[j] < p) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    temp = a[i-1];
    a[i-1] = a[lo];
    a[lo] = temp;
    return i-1;
}

void quicksort_recurse(int *a, long lo, long hi) {
    long p;
    if ((hi-lo) > 1) {
        p = partition(a, lo, hi);
        quicksort_recurse(a, lo, p-1);
        quicksort_recurse(a, p+1, hi);
    }
}

void quicksort(int *a, long n) {
    quicksort_recurse(a, 0, n-1);
}
