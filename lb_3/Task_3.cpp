#include "Header.h"
struct node_stack* head_stack = NULL;
struct node_stack* last_stack = NULL;

struct node_stack* get_struct_second(void) {
    struct node_stack* pointer = NULL;
    char s[256];
    if ((pointer = (node_stack*)malloc(sizeof(struct node_stack))) == NULL) {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }
    printf("Введите название объекта: \n");
    scanf("%s", s);
    if (*s == 0) {
        printf("Запись не была произведена\n");
        return NULL;
    }
    strcpy(pointer->inf, s);
    pointer->next = NULL;

    return pointer; // возвращаем указатель на созданный элемент
}


/* Последовательное добавление в стек элемента (в начало) */
void spstore_stack() {
    struct node_stack* pointer = NULL;
    pointer = get_struct_second();
    if (head_stack == NULL && pointer != NULL) { // если списка нет, то устанавливаем голову списка
        head_stack = pointer;
    }
    else if (head_stack != NULL && pointer != NULL) { // список уже есть, то вставляем в конец
        pointer->next = head_stack;
        head_stack = pointer;
    }
    return;
}

/* Просмотр содержимого списка */
void review_stack(void) {
    struct node_stack* struc = head_stack;
    if (head_stack == NULL) {
        printf("Список пуст\n");
    }
    while (struc) {
        printf("Имя - %s\n", struc->inf);
        struc = struc->next;
    }
}

/* Удаление элемента с начала стека*/
void del_stack() {
    if (head_stack == NULL) {
        printf("Список пуст\n");
        return;
    }
    struct node_stack* struc = head_stack;
    head_stack = head_stack->next;
    free(struc);
    cout << "Удаление успешно завершено!\n";
}