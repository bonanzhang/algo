#ifndef LOCAL_MINIMUM_H
#define LOCAL_MINIMUM_H
//function to find a local minimum from a grid of distinct numbers
//local minimum is a number that is less than its 4 neighbors
//or 2 or 3 neighbors if it's on the edges or corners.
//the grid has size nxn
//divide and conquer algorithm to achieve O(n) comparisons
//recurrence should be in the form T(n) = aT(n/b) + O(n^d)
//a=1, b=2, d=1, which is case 2 of the Master Theorem (1 < 2^1)
#include <stdio.h>
#include <stdlib.h>
void find_local_minimum(int *a, long n, long *r, long *c);
#endif // LOCAL_MINIMUM_H
