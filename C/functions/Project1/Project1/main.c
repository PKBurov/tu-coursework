#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


////////////////////////  9. Добавяне на нов възел в сортиран списък;

struct node 
{
	int data;
	struct node* next;
};
// Тук, има недостатък, предвидено е да работи с предварително създаден поинтер към head_ref, за да може да влияе на head;
void sorted_insert(struct node** head_ref, struct node* new_node)
{
	struct node* current;

	// за края на head
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		//намиране на полето преди да въведем новата стойност
		current = *head_ref;
		while (current->next != NULL &&
			current->next->data < new_node->data)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}
///////////////////////////////////////////////////////////////////////////////


/////////////////////////////  8. Сортиране на списък по даден критерий.

void search()
{
	char *arr;
	int flag = 0;
	arr = (char*)malloc(20);
	printf("Input car brand  : \n \n");
	gets(arr);
	struct cars *temp;
	temp = (struct cars*)malloc(sizeof(struct cars));
	temp = head;
	while (temp != NULL)
	{
		if (!(strcmp(temp->brand, arr))) {
			printf("ID: %s  color: %s  ob: %.2f   brand: %s price : %.2lf  \n \n", temp->ID, temp->color, temp->ob, temp->brand, temp->price);
			flag = 1;
		}
		temp = temp->next;
	}
	if (flag == 0) printf("Can't find brand - %s \n \n", arr);
}
////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////  7.Създаване на списък от тестов или двоичен файл;

while ((read = getline(&line, &len, fp)) != -1)
{
	struct node *n = malloc(sizeof(*n));
	n->name = strdup(line); // копираме
	n->next = head;
	head = n;
}

/////////////////////////////////////////////////////



///////////////////////////////////// 6. Запис на списък в текстов файл или двоичен

struct Node {
	char *name;
	int age;
	struct Node *next;
};

struct Node * petRecord;
struct Node * newRecord;

void writeToFile()
{
	FILE * fptr;
	fptr = fopen("petnames.txt", "w");
	struct Node * iterator = petRecord;

	if (fptr == NULL)
	{
		printf("Error\n");
	}

	else
	{
		while (iterator != NULL)
		{
			fprintf(fptr, "\nPet Name: %s\nAge: %d\n", iterator->name, iterator->age);
			iterator = iterator->next;
		}
	}

	fclose(fptr);
}


//////////////////////////////////////////////////////////////////



//////////////////////////////////////// 5. Изтриване а списък;

struct Node
{
	int data;
	struct Node* next;
};

/* Function to delete the entire linked list */
void deleteList(struct Node** head_ref)
{
	/* deref head_ref to get the real head */
	struct Node* current = *head_ref;
	struct Node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	/* deref head_ref to affect the real head back
	   in the caller. */
	*head_ref = NULL;
}


///////////////////////////////////////////////////////////////


////////////////////////////////////////////////// 4.Преброяване на възлите на списък;

struct Node
{
	int data;
	struct Node* next;
};

/* Counts no. of nodes in linked list */
int getCount(struct Node* head)
{
	int count = 0;  // Initialize count 
	struct Node* current = head;  // Initialize current 
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

///////////////////////////////////////////////////////////////////


//////////////////////////////////////// 3. Търсене на възел в списък по конкретна стойност на поле.

bool search(struct Node* head, int x)
{
	struct Node* current = head;  // Initialize current 
	while (current != NULL)
	{
		if (current->key == x)
			print("key");
			return true;
		current = current->next;
	}
	return false;

////////////////////////////////////////////////////////////


/////////////////////////// 2. Извеждане на възел от списък -от начало , края , конкретна стойност






	////////////////////////// 1. Въвеждане на нов възел в списък: - в началото, края,  пред или след указан възел;