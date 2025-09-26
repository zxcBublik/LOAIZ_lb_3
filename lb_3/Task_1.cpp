#include "Header.h"

struct node* head = NULL;
struct node* last = NULL;
int leight = 0;

struct node* get_struct(void) {
    struct node* p = NULL;
    char s[256];
    int prior;
    if ((p = (node*)malloc(sizeof(struct node))) == NULL) {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");
    scanf("%s", s);
    if (*s == 0) {
        printf("Запись не была произведена\n");
        return NULL;
    }
    cout << "Введите приоритет объекта:\n";
    cin >> prior;
    strcpy(p->inf, s);
    p->priority = prior;
    p->next = NULL;
    return p;
}
void spstore(void) {
    struct node* p = NULL;
    p = get_struct();
    if (head == NULL && p != NULL) {
        head = p;
        last = p;
    }
    else if (head != NULL && p != NULL) {
        if (p->priority > head->priority) {
            p->next = head;
            head = p;
            return;
        }
        struct node* struc = head;
        while (struc->next != NULL && struc->next->priority >= p->priority) {
            struc = struc->next;
        }
        p->next = struc->next;
        struc->next = p;
        if (p->next == NULL) {
            last = p;
        }
    }
}

void review(void) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
    }
    while (struc) {
        printf("Имя - %s\nПриоритетный номер - %d\n\n", struc->inf, struc->priority);
        struc = struc->next;
    }
}
struct node* find(char* name) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
    }
    while (struc) {
        if (strcmp(name, struc->inf) == 0) {
            return struc;
        }
        struc = struc->next;
    }
    printf("Элемент не найден\n");
    return NULL;
}

struct node* find_priority(int priority) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
    }
    while (struc) {
        if (struc->priority == priority) {
            return struc;
        }
        struc = struc->next;
    }
    printf("Элемент не найден\n");
    return NULL;
}


void del(char* name) {
    struct node* struc = head;
    struct node* prev = NULL;
    bool flag = 0;

    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    if (strcmp(name, struc->inf) == 0) {
        flag = 1;
        head = struc->next;
        free(struc);
        struc = head;
    }
    else {
        prev = struc;
        struc = struc->next;
    }

    while (struc) {
        if (strcmp(name, struc->inf) == 0) {
            flag = 1;
            if (struc->next) {
                prev->next = struc->next;
                free(struc);
                struc = prev->next;
            }
            else {
                prev->next = NULL;
                free(struc);
                return;
            }
        }
        else {
            prev = struc;
            struc = struc->next;
        }
    }
    if (flag == 0) {
        printf("Элемент не найден\n");
    }
}


void del_prior(int priority) {
    struct node* struc = head;
    struct node* prev = NULL;
    bool flag = 0;

    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    if (priority == struc->priority) {
        flag = 1;
        head = struc->next;
        free(struc);
        struc = head;
    }
    else {
        prev = struc;
        struc = struc->next;
    }
    while (struc) {
        if (priority == struc->priority) {
            flag = 1;
            if (struc->next) {
                prev->next = struc->next;
                free(struc);
                struc = prev->next;
            }
            else {
                prev->next = NULL;
                free(struc);
                return;
            }
        }
        else {
            prev = struc;
            struc = struc->next;
        }
    }
    if (flag == 0) {
        printf("Элемент не найден\n");
    }
}
