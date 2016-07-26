#include "dynamic_list.h"
void init_dynamic_int_list(dynamic_int_list *dl, long default_capacity) {
    if (dl->capacity > 0) {
        fprintf(stderr, "Cannot initialize dynamic_int_list, already initialized\n");
        return;
    }
    dl->size = 0;
    dl->capacity = default_capacity;
    dl->list = (int *) malloc(sizeof(int) * dl->capacity);
    if (dl->list == NULL) {
        fprintf(stderr, "Cannot initialize dynamic_int_list, malloc failed\n");
        dl->capacity = 0;
        return;
    }
}
void free_dynamic_int_list(dynamic_int_list *dl) {
    if (dl->list) {
        free(dl->list);
    }
    dl->size = 0;
    dl->capacity = 0;
}
void push_back_to_dynamic_int_list(dynamic_int_list *dl, int *elmt) {
    int *realloc_ptr;
    if (dl->size == dl->capacity) {
        dl->capacity = dl->capacity * 3 / 2;
        realloc_ptr = (int *) realloc(dl->list, sizeof(int) * dl->capacity);
        if (realloc_ptr == NULL) {
            fprintf(stderr, "Cannot push_back_to_dynamic_int_list, realloc failed\n");
            dl->capacity = dl->capacity * 2 / 3;
            return;
        } else {
            dl->list = realloc_ptr;
        }
    }
    dl->list[dl->size] = *elmt;
    dl->size++;
}
