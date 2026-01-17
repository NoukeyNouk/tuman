#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "structs.h"
#include "my_list.h"
// typedef struct Node {
//     void *data;
//     struct Node *next;
// } Node;
//
// typedef struct List {
//     Node *head;
// } List;
//
// typedef struct Task {
//     char *info;
//     List *tags;
// } Task;
//
// typedef struct Flags {
//     int flag1;
//     int flag2;
//     int flag3;
// } Flags;

List *

Task *parse_task_string(const char *string) {
    Task *task = malloc(sizeof(Task));
    return task;
}

char *create_task_string(Task *task) {
    char *string = calloc(strlen(task->info) + 0x30, sizeof(char));
    printf("creating task string...\n");
    return string;
}

int write_into_fileBuffer(Task *task) {
    printf("writing into fileBuffer...\n");
    return 0;
}    

int push_buffer(List *buffer) {
    printf("pushing buffer...\n");
    return 0;
}

List *read_from_fileBuffer() {
    List *list = List_init();
    printf("reading from fileBuffer...\n");
    
    // char *

    return list;
}

int parse_cmd_args(int argc, char *argv[], Flags *cmd_flags) {
    printf("parsing cmd_flags...\n");

    if (argc == 1) {
        printf("usage: tuman [command] [flags]\n");
        printf("\ncommands:\n");
        printf("\tread\n");
        printf("\tpush\n");
        return 0;
    }

    if (strcmp(argv[1], "push") && argc == 3) {
           
    }
    else if (strcmp(argv[1], "read") && argc == 2) {

    }

    return 0;
}

int main(int argc, char *argv[]) {
    Flags cmd_flags;
    memset(cmd_flags, 0, sizeof(Flags));
    
    parse_cmd_args(argc, argv, &cmd_flags);

    if (cmd_flags.push) {

    }
    else if (cmd_flags.read) {

    }
        
    return 0;
}
