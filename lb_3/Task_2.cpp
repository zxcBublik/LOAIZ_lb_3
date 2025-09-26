#include "Header.h"

struct node_queue* head_queue = NULL;
struct node_queue* last_queue = NULL;

struct node_queue* get_struct_queue(void) {
    struct node_queue* pointer = NULL;
    char s[256];

    if ((pointer = (node_queue*)malloc(sizeof(struct node_queue))) == NULL) {
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


/* ���������������� ���������� � ������ �������� (� �����) */
void spstore_queue(void) {
    struct node_queue* pointer = NULL;
    pointer = get_struct_queue();
    if (head_queue == NULL && pointer != NULL) { // ���� ������ ���, �� ������������� ������ ������
        head_queue = pointer;
        last_queue = pointer;
    }
    else if (head_queue != NULL && pointer != NULL) { // ������ ��� ����, �� ��������� � �����
        last_queue->next = pointer;
        last_queue = pointer;
    }
    return;
}

/* �������� ����������� ������ */
void review_queue(void) {
    struct node_queue* struc = head_queue;
    if (head_queue == NULL) {
        printf("������ ����\n");
    }
    while (struc) {
        printf("��� - %s\n", struc->inf);
        struc = struc->next;
    }
}

/* �������� �������� � ������ ������� */
void del_queue() {
    if (head_queue == NULL) {
        printf("������ ����\n");
        return;
    }
    struct node_queue* struc = head_queue;
    head_queue = head_queue->next;
    free(struc);
    cout << "�������� ������� ���������!\n";
}