#ifndef STRUCTS
#define STRUCTS

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

typedef struct Idea {
    char *text;
    char *fmt_text;
    List *tags;
} Idea;

typedef struct Flags {
    int push;
    int read;
    char *idea;
} Flags;

#endif
