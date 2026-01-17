#ifndef STRUCTS
#define STRUCTS

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

typedef struct Task {
    char *info;
    List *tags;
} Task;

typedef struct Flags {
    int command;
    int flag2;
    int flag3;
} Flags;

#endif
