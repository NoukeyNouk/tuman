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

void parse_fmt_text(Idea *idea) {
    printf("parsing fmt_text...\n");
    return;
}

void create_fmt_text(Idea *idea) {
    printf("creating fmt_text for idea...\n");
    return;
}

int write_into_fileBuffer(Idea *idea) {
    printf("writing into fileBuffer...\n");
    return 0;
}    

int push_ideas(List *buffer) {
    printf("pushing buffer...\n");
    return 0;
}

List *pull_ideas() {
    List *list = List_init();
    printf("Checking for ideas...\n");
    return list;
}

List *read_from_fileBuffer() { // returns List of idea_str
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
    }
    else if (strcmp(argv[1], "push") == 0 && argc == 3) {
        cmd_flags->push = 1;
        cmd_flags->idea = calloc(strlen(argv[2]) + 1, sizeof(char));
        strcpy(cmd_flags->idea, argv[2]);
    }
    else if (strcmp(argv[1], "read") == 0 && argc == 2) {
        cmd_flags->read = 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    Flags cmd_flags = {0};
    
    parse_cmd_args(argc, argv, &cmd_flags);

    if (cmd_flags.push) {
        Idea idea = {0};
        idea.text = cmd_flags.idea;
        List *ideas = List_init();
        List_append(ideas, &idea);

        printf("%s\n", idea.text);
        push_ideas(ideas);
    }
    else if (cmd_flags.read) {
        
    }
        
    return 0;
}
