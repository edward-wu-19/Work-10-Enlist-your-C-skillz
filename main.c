#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "main.h"


int main() {
    newlines(1);

    struct course *systems;
    systems = make_course("Systems", 30, 5);

    printf("courses in backwards order:\n");

    print_course(systems);

    int i;
    srand(time(NULL));

    struct course *first = systems;

    for (i = 1; i < 8; i++){

        char name[4] = {(char)(65 + rand() % 26), (char)(65 + rand() % 26), (char)(65 + rand() % 26), '\0'};

        first = insert_front(first, name, rand() % 50, rand() % 1000);
 
        print_course(first);
    }

    newlines(2);

    printf("The schedule is as follows:\n");

    print_list(first);

    int course_TBR = first -> next_course -> next_course -> next_course -> id;

    // ======================
    printf("Removing the course with ID %d\n", course_TBR);

    struct course * holder1 = remove_course(first, course_TBR);

    printf("New schedule:\n");

    print_list(first);
    // ======================
    printf("Removing the Systems course \n");

    struct course * holder2 = remove_course(first, 5);

    printf("New schedule:\n");

    print_list(first);
    // ======================
    printf("Removing the course with ID %d: (which is impossible because all the IDs are taken mod 1000\n", 1001);

    struct course * holder3 = remove_course(first, 1001);

    printf("New schedule:\n");

    print_list(first);

    free_list(first);
    //=================================
    return 0;
}

void newlines(int n){
    int i;
    for (i = 0; i < n; i++){
        printf("\n");
    }
}

struct course *make_course(char course_name[20], int course_size, int course_id){
    struct course *n = malloc(sizeof(struct course));
    strncpy(n->name, course_name, sizeof(n->name));
    n->students = course_size;
    n->id = course_id;
    n->next_course = 0;
    return n;
}


void print_course(struct course *s){
    printf("The %s course (ID: %d) has %d students.\n", s->name, s->id,  s->students);
}

void print_list(struct course *s){
    while (s != 0){
        print_course(s);
        s = s->next_course;
    }
    newlines(2);
}


struct course * insert_front(struct course *s, char name[20], int students, int id){
    struct course *n = make_course(name, students, id);
    n->next_course = s;
    return n;
}


struct course * free_list(struct course *s){
    struct course *tmp = s;
    while (s != 0){
        free(s);
        s = s->next_course;
    }
    return tmp;
}

struct course * remove_course(struct course *front, int course_code){
    struct course *temp = front, *prev;
 
    if (temp != NULL && temp->id == course_code) {
        front = temp->next_course;
        free(temp);
        return front;
    }

    while (temp != NULL && temp->id != course_code) {
        prev = temp;
        temp = temp->next_course;
    }
 
    if (temp != NULL){
        prev->next_course = temp->next_course;
        free(temp);
    }

    return front;
}