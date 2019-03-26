#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[30];
	int facNum;
	double GPA;
} student;

typedef struct Node{
	student data;
	struct Node* next;
} node;

int menu(){
	int i;

	printf("1. Enter new student\n");
	printf("2. Print all students\n");
	printf("3. Delete all student\n");
	printf("4. Get average GPA for all students\n");
	printf("5. EXIT\n");

	do{
		printf("Select option: ");
		fflush(stdin);
		scanf("%d", &i);
	}while(i < 1 || i > 5);

	return i;
}

void initStudent(student* newStudent){


	printf("\nEnter name: ");
	fflush(stdin);
	gets(newStudent->name);
	printf("Enter fac num: ");
	scanf("%d", &newStudent->facNum);
	printf("Enter GPA: ");
	fflush(stdin);
	scanf("%lf", &newStudent->GPA);

}

void addNode(node** head){
	node* temp = (node*)malloc(sizeof(node));

	initStudent(&temp->data);
	temp->next = (*head);
	*head = temp;

	printf("\nNew student added successfully!\n");
}

void printStudent(student data){
	printf("Name: %s\n", data.name);
	printf("Fac num: %d\n", data.facNum);
	printf("GPA: %.2lf\n", data.GPA);
}

void printNode(node* head){
	int i = 1;

	if(!head){
		printf("List is empty!\n");
		return;
	}

	while(head){
		printf("\nStudent %d\n", i++);
		printStudent(head->data);

		head = head->next;
	}
}

void deleteNode(node** head){
	node* temp;

	while(*head){
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}

	printf("List deleted successfully!\n");
}

void getGPA(node* head){
	int i = 0;
	double sum = 0;

	if(!head){
		printf("List is empty!\n");
		return;
	}

	while(head){
		sum += head->data.GPA;
		head = head->next;
		++i;
	}

	printf("\nAverage GPA of all %d student: %.2lf\n", i, sum / i);
}

int main(){
	node* head = NULL;

	while(1){
		system("cls");
		switch(menu()){
			case 1: addNode(&head);
				break;
			case 2: printNode(head);
				break;
			case 3: deleteNode(&head);
				break;
			case 4: getGPA(head);
				break;
			case 5:
				return 0;
		}
		system("pause");
	}

}