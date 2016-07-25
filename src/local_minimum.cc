#include "local_minimum.h"
int is_local_minimum(int *a, long n, long r, long c) {
    int good_up;    //r-1
    int good_down;  //r+1
    int good_left;  //c-1
    int good_right; //c+1
    good_up    = r > 0   ? a[r*n+c] < a[(r-1)*n+c] : 1;
    good_down  = r < n-1 ? a[r*n+c] < a[(r+1)*n+c] : 1;
    good_left  = c > 0   ? a[r*n+c] < a[r*n+(c-1)] : 1;
    good_right = c < n-1 ? a[r*n+c] < a[r*n+(c+1)] : 1;
    return good_up && good_down && good_left && good_right;
}
void find_local_minimum(int *a, long n, long &r, long &c) {
    for (long i=0; i<n*n; i++) {
        r = i/n;
        c = i%n;
        if (is_local_minimum(a, n, r, c)) {
            break;
        }
    }
}
