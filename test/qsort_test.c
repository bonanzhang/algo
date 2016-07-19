#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"
#define SMALL_BUFFER_SIZE 256
int main() {
    char buf[SMALL_BUFFER_SIZE];
    int *a;
    long n;
    long i;
    n = atol(fgets(buf, SMALL_BUFFER_SIZE, stdin));
    a = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        fgets(buf, SMALL_BUFFER_SIZE, stdin);
        a[i] = atol(buf);
    }
    quicksort(a, n);
    for (i = 1; i < n; i++) {
        if (a[i-1] > a[i]) return -1;
    }
    free(a);
    return 0;
}
