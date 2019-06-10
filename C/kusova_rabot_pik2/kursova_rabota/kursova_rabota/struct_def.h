//------------------------Дефиниране на структори-------------------с
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person
{
	char full_name[30];	// Цялото име на студента
	char faculty[8];	// Факултет
	char major[20]; // Специалност

	int group;	// Ще трябва проверка за единично въведено число;
	int study_year; // Курс
	int fac_num; // Фак. Номер

	struct person *next;

}person;

struct person *head = NULL;
struct person *current = NULL;
