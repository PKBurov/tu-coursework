//#include <visual_2013.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "my_func.h"
#include <stdbool.h>

//--------------------------------------------------------------------------------------------------------

FILE *get_name_file(char *name_file, char *mode, char *text)
{
	FILE *fp;
	int err;

	do
	{
		printf("\nВъведете име на файла %s:", text);
		err = scanf("%s", name_file);
	} while (err != 1);

	if ((fp = fopen(name_file, mode)) == NULL)
	{
		printf("\nФайлът <%s> Не може да се отвори - error No % d !!!\n", name_file, errno);
		printf("ГРЕШКА No %d %s", errno, strerror(errno));
		system("pause");
	}
	else
	{
		printf("\nФайлът <%s> е отворен успешно за обработка !\n\n", name_file);
		system("pause");
	}
	return fp;
}
//-------------------------------------------------------------------------------------------------------- Y
void print_text_file()
{
	FILE *fp = NULL;
	char name_file[256], ch;
	if ((fp = get_name_file(name_file, "rt", "за четене")) != NULL)
	{
		while (1)
		{
			ch = fgetc(fp);
			if (ch == EOF)
				break;
			fputc(ch, stdout);
			printf(" ");
		}
	}
	system("pause");
	fclose(fp);
}
//-------------------------------------------------------------------------------------------------------- Y

short count_symbols(FILE *fp_in, FILE *fp_out)
{
	rewind(fp_in);
	short ascii_table[256] = { 0 }, ascii_count = 0, m = 0, i = 0;
	while ((ascii_count = fgetc(fp_in)) != EOF)
		ascii_table[ascii_count]++;

	for (int i = 32; i < 256; i++)
		if (ascii_table[i] != 0)
		{
			fprintf(fp_out, "%c\t%d\t%x\t%d\n", i, i, i, ascii_table[i]);

		}


	return 0;
}
//-------------------------------------------------------------------------------------------------------- Y
short count_chosen_symbol(FILE *fp_in, char *ch)
{
	rewind(fp_in);
	int characters = 0, count_letter = 0;
	float occurrence;
	char up_case, lw_case = 'a';
	
	printf("Въведете символа който искате да бъде открит: ");fflush(stdin);
	_getche(lw_case);

	up_case = toupper(lw_case);

	while ((ch = fgetc(fp_in)) != EOF)
	{
		characters++;

		if (ch == lw_case)
		{
			count_letter++;
		}
	}
	if (characters != 0)
	{
		occurrence = (float)count_letter / characters;
	}
	else
	{
		printf("Файлът не съдържа символи!!");
	}

	printf("\nСимволът който избрахте в файла, се намира '%.3f' на брой пъти!\n",occurrence);
}
//-------------------------------------------------------------------------------------------------------- Y
void change_symbol(FILE *fp_in, FILE *fp_out)
{
	rewind(fp_in);
	
	char str1[] = "a";
	char str2[] = "b";
	char next;
	
	printf("Въведете избрания от вас символ за размяна:"); fflush(stdin); fflush(stdin);
	scanf("%s",&str1);

	printf("\nВъведете с кой символ да извършите размяната:");fflush(stdin);
	scanf("%s",&str2);

	char ch1 = str1[0];
	char ch2 = str2[0];

	for (; (next = fgetc(fp_in)) != EOF;)
	{
		printf("ch1=%c", ch1);
		printf("ch2=%c", ch2);
		printf("next=%c", next);


		if (next == ch1) next = ch2;
		if (fputc(next, fp_out) == EOF)
		{
			printf("Error - in file writing");
			return;
		}
	}
	printf("\nФайлът бе записан коректно!");
	_getch();

	fclose(fp_out);
}
//-------------------------------------------------------------------------------------------------------- Y
int max_min_numbers(FILE *fp_in)
{
	rewind(fp_in); 
	int num = 0;
	char str[100];
	int max = 0, min = 2400000;

	while (fscanf(fp_in, "%s", str) != EOF)
	{
		if ((digits_only(str)) == true) // function za da opredelim dali v niza ima samo chisla, nai dolu, izpolzvam macro isdigit
		{
			num = atoi(str);
			if (num > max)
				max = num;
			if (num < min)
				min = num;
		}
	}
	printf("Here are the max %d and min %d values!\n", max, min);
}
//-------------------------------------------------------------------------------------------------------- Y само с числа
void write_numbers_of_interval(FILE *fp_in, FILE *fp_out)
{
	rewind(fp_in);
	int a, b;
	int count_symbol_place = 0;
	short ascii_table[256] = { 0 }, ascii_count = 0, m = 0, i = 0;
	

	printf("Въведете долна граница=");
	scanf("%d", &a);
	do
	{
		printf("Въведете горна граница=");
		scanf("%d", &b);
	} while (a >= b);

	while ((ascii_count = fgetc(fp_in)) != EOF)
	{
		if (count_symbol_place >= a && count_symbol_place <= b)
		{
			ascii_table[ascii_count]++;
		}
		count_symbol_place++;
	}
	for (int i = 48; i < 58; i++)
		if (ascii_table[i] != 0)
		{
			fprintf(fp_out, "%c\t%d\t%x\t%d\n", i, i, i, ascii_table[i]);

		}
	return 0;
}
//-------------------------------------------------------------------------------------------------------- Y грешни интервали, мисля;
float average_of_numbers(FILE *fp_in)
{
	int n = 0, S = 0, num = 0, overflow;
	char str[100];
	while (fscanf(fp_in, "%s", str) != EOF)
	{
		num = atoi(str);
		if (errno == 34)
		{
			printf("\n Препълване при четене!");
			system("pause");
			exit(1);
		}
		S = sum_average(S, num, &overflow);
		if (overflow == 1)
		{
			printf("\n Препълване при добавяне!");
			system("pause");
			exit(1);
		}
		n++;
	}
	if (ferror(fp_in))
	{
		printf("Грешка при четене!");
		system("pause");
		exit(1);
	}

	return (float)S / n;
}
//-------------------------------------------------------------------------------------------------------- Y Само с числа
int sum_average(int S, int num, int *overflow)
{

	int no_overflow = 1;
	S = S + num;
	_asm
	{
		jno NO_OVERFLOW
		mov no_overflow, 0
		NO_OVERFLOW:
	}
	if (no_overflow == 0)
	{
		*overflow = 1;
	}
	else
		*overflow = 0;
	return S;
}
//-------------------------------------------------------------------------------------------------------- Y
void change_negative_numbers(FILE *fp_in, FILE *fp_out)//function
{
	rewind(fp_in);

	int in_number = false; // flag for checking 
	int ch; // Changed to int since EOF is

	while ((ch = fgetc(fp_in)) != EOF)
	{
		// Check for '-' followed by digit
		if (ch == '-')
		{
			// Peek ahead
			ch = fgetc(fp_in);
			if (isdigit(ch)) 
			{
				// It is a number. Write 0 and set flag
				fputc('0', fp_out);
				in_number = true;
			}
			else 
			{
				// Not a number write back '-' and peeked char
				fputc('-', fp_out);
				if (EOF != ch) fputc(ch, fp_out);
			}
		}
		// Only write non-digits or when not reading a negative number
		else if (!isdigit(ch) || !in_number) 
		{
			fputc(ch, fp_out);
			in_number = false;
		}
	}
}
//-------------------------------------------------------------------------------------------------------- Y
int digits_only(const char *s)
{
	while (*s) 
	{
		if (isdigit(*s++) == 0) 
			return 0;
	}
	return 1;
}
//-------------------------------------------------------------------------------------------------------- Y Добавена от мен за проверка на низ