#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#define DELTA 10 /* брой елементи, с които се увеличава масива при липса на място */

int *create_dyn_arr(FILE *fp, int *n)
{
	int *ptr = 0; /* Указател към цял тип за организиране на масива */
	FILE *fp = NULL; /* Указател за връзка с файл */
	int i = 0, size = 0, num = 0, digit;
	/* i – индекс; size -размер ма масива; num – брой на елементите му; digit – число за вмъкване; */
	if ((fp = fopen("test.txt", "r")) == NULL) { /* Отваряне на текстов файл за четене*/
		printf("Cannot open file.\n"); return 2;
	}
	while (fscanf(fp, "%d", &digit) == 1) /* Начало на цикъл за четене на числата от файла */ {
		//ptr = include(digit, ptr, &size, &num);
		if (ptr == NULL)
		{
			printf("Memory allocation error!");
			fclose(fp);
			return 1;
		}
		return ptr;
	}

	//------------------------------------------------------func

	int* include(int digit, int *p, int *sizeAd, int *nm)
	{
		int *tmp;
		if (!(p))
		{
			*sizeAd = DELTA;
			if ((p = (int *)malloc((*sizeAd) * sizeof(int))) == NULL)		/* Динамично начално заделяне на памет за масива */
			{
				return p;
			}
		}

		if (*nm < *sizeAd)
		{
			p[(*nm)++] = digit;
		}
		else
		{
			*sizeAd += DELTA;
			tmp = (int *)realloc(p, (*sizeAd) * sizeof(int));	 /* разширяване на масива */

			if (tmp != NULL)
			{
				p = tmp;
				p[(*nm)++] = digit;
			}
			else
			{
				ree(p);
				p = NULL;
			}
		}
		return p;
	}