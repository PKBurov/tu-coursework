#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

FILE *get_name_file(char *name_file, char *mode, char *text)
{
	FILE *fp;
	int err;
 
	do
	{
		printf("\nВъведете име на файла %s:",text);
		err= scanf("%s", name_file);
	}while(err!=1);

	if ((fp=fopen(name_file,mode))==NULL)
	{
		printf("\nФайлът <%s> Не може да се отвори - error No % d !!!\n",name_file,errno);
		printf("ГРЕШКА No %d %s",errno,strerror( errno ));
		system("pause");
	}
	else
	{
		printf("\nФайлът <%s> е отворен успешно за обработка !\n\n", name_file);
		system("pause");
	}
	return fp;
}
//---------------------------------------------------------------------------------------------------------------
void print_text_file()
{
	FILE *fp=NULL;
	char name_file[256],ch;
	if((fp = get_name_file(name_file, "rt", "за четене"))!=NULL)
	{
		while(1)
		{
			ch=fgetc(fp);
			if(ch==EOF)
				break;
			fputc(ch,stdout);
		}
	}
	system("pause");
	fclose(fp);
}
//----------------------------------------------------------------------------------------
int* include(int digit, int* ptr, int *sizeAd, int* num)
{
    int *tmp;
    if(!(ptr)){
        *sizeAd=DELTA;
        if((ptr=(int *)malloc((*sizeAd)*sizeof(int)))==NULL){
        return ptr;
        }
    }
    if(*num<*sizeAd)
        {ptr[(*num)++]=digit;}
    else {
        *sizeAd+=DELTA;
        tmp=(int *)realloc(ptr,(*sizeAd)*sizeof(int));
        if(tmp!=NULL)
            {ptr=tmp; ptr[(*num)++]=digit;}
        else {free(ptr); ptr=NULL;}
    }
    return ptr;
}
//-------------------------------------------------------------
void sort(int ptr[], int* num)
{
    int i, j, a;
    int n = num;

        for (i = 0; i <= (n-1) ; i++)
        {
            for (j = (i + 1); j < n; j++)
            {
                if (ptr[i] < ptr[j])
                {
                    a =  ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = a;
                }
            }
        }
	for(i=0; i<num; i++){printf(" %d", ptr[i]);} 
}
//--------------------------------------------------------------
void average(int *ptr, int*num)
{
	int countcount = num, countnum = 0, i=0;
	for (i = 0; i < (num); i++)
	{
		countnum += ptr[i];
	}
	printf("Средно-аритметичната стойност на числата в масива е: %f\n",(float) countnum / countcount);
}
//------------------------------------------------------------------
void interval(int *ptr, int*num)
{
	int maxv, minv, p, i, numc = 0, numcount = 0;
	printf("Въведи горна граница:\n");
	scanf("%d", &maxv);
	printf("Въведи долна граница:\n");
	scanf("%d", &minv);
	if (maxv < minv)
	{
		p = maxv;
		maxv = minv;
		minv = p;
	}
	for (i = 0; i < (num); i++)
	{
	    if(ptr[i]<maxv && ptr[i]>minv)
        {
			numc+=ptr[i];
			numcount++;
		}
	}
	printf("Сумата е: %d\n", numc);
	printf("Има %d числа в интервала.\n", numcount);
}
//-------------------------------------------------------------------------------