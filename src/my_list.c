#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

List *List_init() {
    List *list = calloc(1, sizeof(List));
    return list;
}

void List_append(List *list, void *info) {
    Node *current = list->head;

    if (!current) {
        list->head = calloc(1, sizeof(Node));
        list->head->data = info;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = calloc(1, sizeof(Node));

    current->next->data = info;
    return;
}

void List_insert(List *list, void *info, int index) {
    int current_index = 0;
    Node *current = list->head;
    
    if (!current) {
        list->head = calloc(1, sizeof(Node));
        list->head->data = info;
        return;
    }

    while (current->next && current_index < index - 1) {
        current = current->next;
        current_index++;
        
    }

    Node *new = calloc(1, sizeof(Node));
    new->data = info;
    
    if (index <= 0) {
        new->next = list->head;
        list->head = new;
    }
    else if (current->next) {
        new->next = current->next;
        current->next = new;
    }
    else {
        current->next = new;
    }
    return;
}

void *List_get(List *list, int index) {
    Node *current = list->head;
    if (!current) {
        return NULL;
    }
    int cur_index = 0;
    while (current && cur_index != index) {
        current = (current->next) ? current->next : NULL;
        cur_index++;
    }

    if (cur_index != index) {
        return NULL;
    }
    return current->data;
}

void List_print(List *list) {
    Node *current = list->head;
    while (current->next) {
        printf("(%s)->", current->data);
        current = current->next;
    }
    printf("(%s)\n", current->data);
    return;
}

void List_free(List *list) {
    Node *current = list->head;
    Node *prev = list->head;
    while (current->next) {
        current = current->next;
        free(prev);
        prev = current;
    }
    free(current);
    free(list);
    return;
}

void List_remove(List *list, int index) {
    int cur_index = 0;
    Node *current = list->head;
    if (!current) {
        return;
    }

    while (current->next && cur_index != index - 1) {
        current = current->next;
        cur_index++;
    } 
    
    if (cur_index != index - 1) {
        return;
    }

    if (!current->next) {
        return;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return;
}

List *List_cat(List *list1, List *list2) {
    Node *current = list2->head;
    if (list2->head == NULL) {
        return list1;
    }
    while (current) {
        List_append(list1, current->data);
        current = (current->next) ? current->next : NULL;
    }
    return list1;
}
