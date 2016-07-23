#include "sort.h"
void merge(int *a, long m, long n) {
    int *x;
    long i;
    long l;
    long r;
    x = (int *) malloc(sizeof(int) * n);
    l = 0;
    r = m;
    for (i = 0; i < n; i++) {
        if (l == m) {
            x[i] = a[r++];
        } else if(r == n) {
            x[i] = a[l++];
        } else if (a[l] < a[r]) {
            x[i] = a[l++];
        } else {
            x[i] = a[r++];
        }
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}

void merge_sort(int *a, long n) {
    long m;
    if (n < 2) {
        return;
    }
    m = n/2;
    merge_sort(a, m);
    merge_sort(a+m, n-m);
    merge(a, m, n);
}
