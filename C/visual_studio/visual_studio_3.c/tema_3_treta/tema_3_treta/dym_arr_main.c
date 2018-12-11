#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "menu.h"
#include "my_func.h"

//------------- менюта ------------------------------------
char *txt_menu[] =
{
	"-----ПРОГРАМА ТЕКСТОВ ФАЙЛ-----",
	"Избор на входен файл за обработка.................................",
	"Показване съдържанието на текстов файл............................",
	"Четене от текстов файл на цели числа и запис в динамичен масив, като се следи за препълване",
	"Показване на екрана съдържанието на масива........................",
	"Намиране на минималното и максималното числа в масива.............",
	"Изчисляване на средно-аритметичната стойност на числата в масива..",
	"Намиране сумата и броя на числата в зададен интервал от масива....",
	"Сортиране на числата от масива във възходящ ред...................",
	"Изход.............................................................",
	NULL
};

//----------------------------------------------------------------------
int main()
{
	short mode, flag1 = 0, flag2 = 0, count = 0;
	FILE *fp = NULL;
	char name[256], ch = 0;
	int *ptr = NULL, n = 0, max = 0, min = 0, S = 0;
	float average = 0;
	//------------------------------------------------------
	//	unsigned long br_words=0;
	//-------------------------------------------------------

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	do
	{
		system("cls");
		mode = menu(txt_menu);
		switch (mode)
		{
			//-------------------------------------------------------------------------------------------------
		case 1:
			system("cls");
			if ((fp = get_name_file(name, "rt", "за четене")) != NULL)
				flag1 = 1;
			break;
			//----------------------------------------------------------------------------------------------
		case 2:	print_text_file(); break;
		case 3:if ((ptr = create_dyn_arr(fp, &n)))
		{
			printf("\nСъздаен е динамичен масив!");
			flag2 = 1;
			system("pause");
			break;
		}
			   else
			printf("\nНе сте създали динамичен масив!"); system("pause");
			break;
		case 4:if (flag2 == 0)
		{
			printf("\nНе сте създали динамичен масив!"); system("pause");
			break;
		}
			   output(ptr, n); system("pause");
			   break;
		case 5:if (flag2 == 0)
		{
			printf("\nНе сте създали динамичен масив!"); system("pause");
			break;
		}
			   max = max_min_numbers(ptr, n, &min);
			   printf("\nmax=%d\tmin=%d", max, min);
			   system("pause");
			   break;
		case 6:if (flag2 == 0)
		{
			printf("\nНе сте създали динамичен масив!"); system("pause");
			break;
		}
			   average = average_array(ptr, n);
			   printf("\nСредно-аритметичното на =%f", average);
			   system("pause");
			   break;
		case 7:if (flag2 == 0)
		{
			printf("\nНе сте създали динамичен масив!"); system("pause");
			break;
		}
			   count = sum_and_number_of_interval(ptr, n, &S);
			   printf("\nсума=%d\tброй=%d", S, count);
			   system("pause");

			   break;
		case 8: if (flag2 == 0)
		{
			printf("\nНе сте създали динамичен масив!"); system("pause");
			break;
		}
				sort_array(ptr, n);
				break;
		}
	} while (mode != 9);
	_fcloseall();
}
