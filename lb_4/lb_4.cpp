#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
struct Node* CreateTree(Node* root, Node* r, int data);
void print_tree(struct Node* r, int l);
void find_el(struct Node* root, int data, int* count);
void find_el_depth(struct Node* root, int data, int* count, int depth);
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
int count_enter = 0;
bool start = 1;
short repeat;
int vazhno;
struct Node* root;
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int D;
	root = NULL;
	cout << "0 - в дереве нет повторов, 1 - есть\n";
	cin >> repeat;
	switch (repeat) {
	case 1:
		break;
	case 2:
		break;
	}
	cout << "Начало построения дерева\n------------------------\n";
	while (start)
	{
		cout << "Введите число:\n";
		cin >> D;
		if (D == -1)
		{
			cout << "Построение дерева окончено\n\n";
			start = 0;
		}
		else
			root = CreateTree(root, root, D);
	}
	print_tree(root, 0);
	short end = 1;
	int number, count = 0;
	while (end != 0) {
		cout << "найти элемент - 1, 0 - завершить\n";
		cin >> end;
		switch (end) {
		case 1:
			cout << "Введите число для поиска:\n";
			cin >> number;
			find_el(root, number, &count);
			if (count == 0) {
				cout << "Совпадений нет\n";
			}
			else {
				cout << "Найдено " << count << " совпадений.\n";
				int count_2 = 0, depth = 0;
				find_el_depth(root, number, &count_2, depth);
				cout << "Глубина входа 1-ого элемента: " << vazhno << '\n';
				if (count_2 > 1) {
					cout << "Глубина входа последнего элемента: " << count_enter << '\n';
				}
				count_enter = 0;
				vazhno = 0;
				count = 0;
			}
			break;
		}
	}
	return 0;
}
void find_el_depth(struct Node* root, int data, int* count, int depth) {
	if (root == NULL)
		return;
	if (root->data == data) {
		*count += 1;
		if (*count == 1) {
			vazhno = depth;
		}
		count_enter = depth;
	}
	if (data < root->data) {
		find_el_depth(root->left, data, count, ++depth);
	}
	else {
		find_el_depth(root->right, data, count, ++depth);
	}
}
void find_el(struct Node* root, int data, int* count) {
	if (root == NULL)
		return;
	if (root->data == data) {
		*count += 1;
	}
	if (data < root->data) {
		find_el(root->left, data, count);
	}
	else {
		find_el(root->right, data, count);
	}
}
struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) {
			return r;
		}
		if (data < root->data)	root->left = r;
		else root->right = r;
		return r;
	}
	if (repeat == 0) {
		int cnt = 0, tmp;
		do {
			find_el(root, data, &cnt);
			if (cnt > 1) {
				cout << "Каждый элемент дерева должен быть уникальным!\n";
				cout << "Введите число:\n";
				cin >> data;
				if (data == -1) {
					start = 0;
					cnt = 0;
					count_enter = 0;
					break;
				}
				cnt = 0;
				count_enter = 0;

				continue;
			}
		} while (cnt != 0);
	}
	if (data != -1) {
		if (data < r->data)
			CreateTree(r, r->left, data);
		else
			CreateTree(r, r->right, data);
	}


	return root;
}
void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->left, l + 1);
	for (int i = 0; i < l; i++)
	{
		cout << " ";
	}
	cout << r->data << '\n';
	print_tree(r->right, l + 1);
}
