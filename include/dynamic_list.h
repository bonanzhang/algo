#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include <stdlib.h>
#include <stdio.h>
//a macro to do a generic type
#define DECLARE_DYNAMIC_LIST_WITH_TYPE(name)                                   \
typedef struct _dynamic_##name##_list {                                        \
    int * list;                                                                \
    long size;                                                                 \
    long capacity;                                                             \
} dynamic_##name##_list;                                                       \
void init_dynamic_##name##_list(dynamic_##name##_list *dl,                     \
                                long default_capacity);                        \
void free_dynamic_##name##_list(dynamic_##name##_list *dl);                    \
void push_back_to_dynamic_##name##_list(dynamic_##name##_list *dl, int *elmt);
//define a dynamic list with int, using a macro
DECLARE_DYNAMIC_LIST_WITH_TYPE(int)
#endif // DYNAMIC_LIST_H
