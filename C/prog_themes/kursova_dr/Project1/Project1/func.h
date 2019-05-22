#include <stdio.h>
typedef struct student {

	char student_first_name[20];
	char student_sur_name[20];
	char student_familly_name[20];

	int faculty_number[10];
	char faculty[20];
	char major[20];
	int group;
	int year;
}STD;

typedef struct node {
	STD st;
	struct node *next;
}node;

node * make_lst(node * head, FILE *f);
void prt(node *crnt);
node * free_m(node *crnt);
node * search(node * crnt, char*t);
void delete(node * crnt, node * prev);
node * add(node * head);
void search_list(node * crnt, char*t);
node **make_ar(node *head, node **ps);
void sort_by_alpha(node **ph);
void bubbleSort(struct Node *start);