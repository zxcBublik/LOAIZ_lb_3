#include "Header.h"
struct node_stack* head_stack = NULL;
struct node_stack* last_stack = NULL;

struct node_stack* get_struct_second(void) {
    struct node_stack* pointer = NULL;
    char s[256];
    if ((pointer = (node_stack*)malloc(sizeof(struct node_stack))) == NULL) {
        printf("������ ��� ������������� ������\n");
        exit(1);
    }
    printf("������� �������� �������: \n");
    scanf("%s", s);
    if (*s == 0) {
        printf("������ �� ���� �����������\n");
        return NULL;
    }
    strcpy(pointer->inf, s);
    pointer->next = NULL;

    return pointer; // ���������� ��������� �� ��������� �������
}


/* ���������������� ���������� � ���� �������� (� ������) */
void spstore_stack() {
    struct node_stack* pointer = NULL;
    pointer = get_struct_second();
    if (head_stack == NULL && pointer != NULL) { // ���� ������ ���, �� ������������� ������ ������
        head_stack = pointer;
    }
    else if (head_stack != NULL && pointer != NULL) { // ������ ��� ����, �� ��������� � �����
        pointer->next = head_stack;
        head_stack = pointer;
    }
    return;
}

/* �������� ����������� ������ */
void review_stack(void) {
    struct node_stack* struc = head_stack;
    if (head_stack == NULL) {
        printf("������ ����\n");
    }
    while (struc) {
        printf("��� - %s\n", struc->inf);
        struc = struc->next;
    }
}

/* �������� �������� � ������ �����*/
void del_stack() {
    if (head_stack == NULL) {
        printf("������ ����\n");
        return;
    }
    struct node_stack* struc = head_stack;
    head_stack = head_stack->next;
    free(struc);
    cout << "�������� ������� ���������!\n";
}