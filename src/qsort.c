long partition(int *a, long lo, long hi) {
    int pivot;
    int temp;
    int i;
    int j;
    pivot = a[lo];
    i = lo - 1;
    j = hi + 1;
    while (1) {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i >= j) {
            return j;
        }
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void quicksort_recurse(int *a, long lo, long hi) {
    long p;
    if (lo < hi) {
        p = partition(a, lo, hi);
        quicksort_recurse(a, lo, p);
        quicksort_recurse(a, p+1, hi);
    }
}

void quicksort(int *a, long n) {
    quicksort_recurse(a, 0, n-1);
}
