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
    long i0;
    long i1;
    long i2;
    long i_med;
    if ((hi-lo+1) <= 1) {
        return;
    }
    i0 = lo;
    i1 = (hi-lo)/2+lo;
    i2 = hi;
    if (a[i1] <= a[i0] && a[i0] <= a[i2]) i_med = i0;
    if (a[i2] <= a[i0] && a[i0] <= a[i1]) i_med = i0;
    if (a[i0] <= a[i1] && a[i1] <= a[i2]) i_med = i1;
    if (a[i2] <= a[i1] && a[i1] <= a[i0]) i_med = i1;
    if (a[i0] <= a[i2] && a[i2] <= a[i1]) i_med = i2;
    if (a[i1] <= a[i2] && a[i2] <= a[i0]) i_med = i2;
    long temp = a[lo];
    a[lo] = a[i_med];
    a[i_med] = temp;
    p = partition(a, lo, hi);
    quicksort_recurse(a, lo, p-1);
    quicksort_recurse(a, p+1, hi);
}

void quicksort(int *a, long n) {
    quicksort_recurse(a, 0, n-1);
}
