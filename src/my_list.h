#ifndef MY_LIST
#define MY_LIST

#include "structs.h"

List *List_init();
void List_append(List *list, void *info);
void List_insert(List *list, void *info, int index);
void List_print(List *list);
void List_free(List *list);
void List_remove(List *list, int index);
void *List_get(List *list, int index);

#endif
