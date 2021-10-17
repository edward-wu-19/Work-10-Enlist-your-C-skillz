#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct class {char name[20]; int students; int id; struct class *next_class;};
struct class * make_class(char class_name[20], int class_size, int class_id);
void print_class(struct class *s);

void print_list(struct class *s);
struct class * insert_front(struct class *s, char name[20], int students, int id);
struct class * free_list(struct class *s);


int main() {
    struct class *systems;
    systems = make_class("Systems", 30, 5);

    printf("Classes in backwards order:\n");

    print_class(systems);

    int i;
    srand(time(NULL));

    struct class *first = systems;

    // Creating 7 classes
    for (i = 1; i < 8; i++){

        char name[4] = {(char)(65 + rand() % 26), (char)(65 + rand() % 26), (char)(65 + rand() % 26), '\0'};

        first = insert_front(first, name, rand() % 50, rand() % 1000);
 
        print_class(first);
    }

    printf("\n\nThe schedule is as follows:\n");

    print_list(first);

    free_list(first);

    return 0;
}

struct class *make_class(char class_name[20], int class_size, int class_id){
    struct class *n = malloc(sizeof(struct class));
    strncpy(n->name, class_name, sizeof(n->name));
    n->students = class_size;
    n->id = class_id;
    n->next_class = 0;
    return n;
}


void print_class(struct class *s){
    printf("The %s class (ID: %d) has %d students.\n", s->name, s->id,  s->students);
}

void print_list(struct class *s){
    while (s != 0){
        print_class(s);
        s = s->next_class;
    }
}


struct class * insert_front(struct class *s, char name[20], int students, int id){
    struct class *n = make_class(name, students, id);
    n->next_class = s;
    return n;
}


struct class * free_list(struct class *s){
    struct class *tmp = s;
    while (s != 0){
        free(s);
        s = s->next_class;
    }
    return tmp;
}