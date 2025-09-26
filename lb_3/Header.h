#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

struct node {
    char inf[256];
    int priority;
    struct node* next;
};
struct node_queue {
    char inf[256];
    struct node_queue* next;
};
struct node_stack {
    char inf[256];
    struct node_stack* next;
};
extern struct node* head;
extern struct node* last;
extern int leight;          

extern struct node_queue* head_queue;
extern struct node_queue* last_queue;

// Функции - приоритетная очередь 
struct node* get_struct(void);
void spstore(void);
void review(void);
struct node* find(char* name);
struct node* find_priority(int priority);
void del(char* name);
void del_prior(int priority);

// Функции - обычная очередь 
struct node_queue* get_struct_queue(void);
void spstore_queue(void);
void review_queue(void);
void del_queue(void); 


// Функции - стек 
struct node_stack* get_struct_stack(void);
void spstore_stack(void);
void review_stack(void);
void del_stack(void); 

