#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<stdbool.h>
#include "struct_def.h" //Проверете header файловете за съдържание
#include "function_s.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int choice = 0;

	for (;;) {

		printf(".:: MENU ::.\n");
		printf("1. Въвеждане на данни за нов студент.\n");
		printf("2. Търсене на студент по фамилно име.\n");
		printf("3. Изтриване на студент по факултетен номер.\n");
		printf("4. Извеждане на списък на студентите от зададена група, подредени по азбучен ред на имената.\n");
		printf("5. Izhod. \n");


		do
		{
			printf("Въведете своя избор: ");
			scanf_s("%d", &choice);
			fflush(stdin);
		} while (!(choice >= 1 && choice <= 5));

		printf("%d \n", choice); //избор
		
		switch (choice)
		{
		case 1:
		{
			start_file();
			add_student();
			head = NULL;
			break;
		}
		case 2:
		{
			start();
			search_student_by_faculty_number();
			end_of_program();
			head = NULL;
			break;
		}
		case 3:
		{
			start();
			del_student_by_faculty_name();
			end_of_program();
			head = NULL;
			break;

		}
		case 4:
		{
			start();
			list_student_sort_alph();
			end_of_program();
			head = NULL;
			break;
		}
		case 5:
		{
			exit(5);
		}
		}
	}
	return 0;
}