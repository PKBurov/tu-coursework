#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define QSIZE 5

typedef struct
{
	int data[QSIZE];
	int head;
	int tail;
}Queue;

void display(Queue*Q);
void display(Queue*Q);
void init(Queue*Q);
void enquene(Queue*Q, int element);

int main ()
{
	Queue que;
	int element;
	init(&que);
	while (!full(&que))
	{
		printf("Enter number:");
		scanf_s("%d", &element);
		enquene(&que, element);
		display(&que);
	}
	printf("Queue is full!!\n");

	while (!empty(&que))
	{
		element == dequeue(&que);// Вадим един по един елементите
		printf("dequence element %d\n", element);// Казваме кой елемент докато не се изпразни
		display(&que);
	}
	
	printf("Queue is empty!\n");
	return 0;
}

void init(Queue*Q)
{
	Q->head = Q->tail = 0;
}

void enquene(Queue*Q, int element)
{
	Q->data[Q->tail++] = element;
}

int dequeue(Queue*Q)
{
	return Q->data[Q->head++];
}

int full(Queue*Q)
{
	if (Q->tail == QSIZE)
	{
		return 1;
	}
	return 0;
}

int empty(Queue*Q)
{
	if (Q->tail == Q->head)
	{
		return 1;
	}
	return 0;
}

void display(Queue*Q)
{
	int i = Q->tail;
		while (i>=Q -> head)
		{
			printf("%d", Q->data[i--]);
			printf("\n");
		}
}