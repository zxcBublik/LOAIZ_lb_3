#include "Header.h"

struct node_queue* head_queue = NULL;
struct node_queue* last_queue = NULL;

struct node_queue* get_struct_queue(void) {
    struct node_queue* pointer = NULL;
    char s[256];

    if ((pointer = (node_queue*)malloc(sizeof(struct node_queue))) == NULL) {
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


/* Последовательное добавление в список элемента (в конец) */
void spstore_queue(void) {
    struct node_queue* pointer = NULL;
    pointer = get_struct_queue();
    if (head_queue == NULL && pointer != NULL) { // если списка нет, то устанавливаем голову списка
        head_queue = pointer;
        last_queue = pointer;
    }
    else if (head_queue != NULL && pointer != NULL) { // список уже есть, то вставляем в конец
        last_queue->next = pointer;
        last_queue = pointer;
    }
    return;
}

/* Просмотр содержимого списка */
void review_queue(void) {
    struct node_queue* struc = head_queue;
    if (head_queue == NULL) {
        printf("Список пуст\n");
    }
    while (struc) {
        printf("Имя - %s\n", struc->inf);
        struc = struc->next;
    }
}

/* Удаление элемента с начала очереди */
void del_queue() {
    if (head_queue == NULL) {
        printf("Список пуст\n");
        return;
    }
    struct node_queue* struc = head_queue;
    head_queue = head_queue->next;
    free(struc);
    cout << "Удаление успешно завершено!\n";
}