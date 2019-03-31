#include "stdio.h"
#include "conio.h"
#include <stdlib.h>
#include <string.h>
#include "dict_func.h"



char delimiters_word[]={' ',',','.','?','!',':',';','/','\\','*', '(',')','{','}','[',']','\n','\t',0};


int IsDelimiter(char *delimiters, char c)
{
  int i=0;
  while(delimiters[i])
  {
    if (c==delimiters[i++])
      return 1; //--- символът с е разделител ---
  }
  return 0;
}

//-----------------------------------------------------------
void ComputeWord(	int c,        //--- текущ символ, които се анализира ---
						char *word,   //--- символен масив за отделяне на дума
						int *ind,     //--- текуща позиция в думата
						int *status   //--- текущ статус на автоматната функция
						)
{
	char ch=c;
	if(*status==2) 
	{
		*status=0;
		*ind=0;
	} 
	switch (*status)
  {
		case 0:
	    if (!IsDelimiter(delimiters_word,ch))
			{
				*status=1;
				word[(*ind)++]=c;
        word[*ind]=0;
			}
   break;

   case 1:
    if( IsDelimiter(delimiters_word,ch ))
      *status=2;
    else
    {
			word[(*ind)++]=c;
      word[*ind]=0;
    }
  }
}
//-------------------------------------------------------------------------------------------------
void DeleteDictionary(char **dict, int *count_words, int index_dict)
{
  int c;
  if (dict) 
  {
    for(c=0; c<index_dict; c++) free(dict[c]);
    free (dict);
    free (count_words);
  }
}
//-------------------------------------------------------------------------------------------------
void PrintDictionary(char **dict, int index_dict, int *count_words, int status)
{
  int i;

  if( index_dict) printf("\n\n    РЕЧНИК:");
  for (i=0; i<index_dict;i++)
  {
    printf("\n%6d %s",count_words[i],dict[i]);
    if (i>0 && !(i%20) )
    {
      printf("\n\n Press ani key to continue !!!");
      getch();
    }
  }
  if(!index_dict)
    printf("\n\n  речникът е празен !!!\n\n");
  else
  {
    printf("\n\n    брой на думите в речника -> %d",index_dict);
    if(!status) printf(" - речника е недовършен - липса на достатъчнo ПАМЕТ !!!\n\n"); else printf("\n\n");
  }
}

//-------------------------------------------------------------------------------------------------
char ** MakeDictionary(FILE *fp, char **dict, int *size_dict, int *index, int **count_words, int *status)
{
	int c, br_word=0, ind=0;
  int sta=0;
	char word[256];
  int (*fff)(FILE *fp);
  char **work;
  //----------------------------------------------
  if (fp==stdin) fff=my_fgetc; else fff=fgetc;
  //----------------------------------------------
	rewind(fp);
  while ( (c=fff(fp)) !=EOF )
  {
     ComputeWord(c, word, &ind, &sta);
     
     if (sta==2)
     {
        br_word++;
        cyr_lat_toupperCP1251(word);
        if ( (work = AddToDictionary(dict, size_dict, index, count_words, word))==NULL)
        {
          *status=0; return dict;
        }
        else
        {
          *status=1; dict=work;
        }
     }
  }
 if (sta==1)
 {
   br_word++;
   cyr_lat_toupperCP1251(word);
    if ( (work = AddToDictionary(dict, size_dict, index, count_words, word))==NULL)
    {
      *status=0; return dict;
    }
    else
    {
       *status=1; dict=work;
    }
 }
 return dict;
}

//-------------------------------------------------------------------------------------------------
char ** AddToDictionary(char **dict, int *size_dict, int *index, int **count_words, char *word)
{ 
  int ind;
  char **work_dict;
  int *work_count_words;

  if (dict==NULL)
  {
    if( (work_dict=(char **)malloc(*size_dict*sizeof(char *))) == NULL)  return NULL; 
    dict=work_dict;
  }
  if (*count_words==NULL)
  {
     if((work_count_words=(int *) malloc(*size_dict*sizeof(int)))==NULL)return NULL;
    *count_words=work_count_words;
  }
  if ( (ind=FindInToDictionary(dict, *index, word)) != -1)
  {
    (*count_words)[ind]++;
	  return dict;
  }
  if ((dict[*index] = (char *) malloc(sizeof(char)*(strlen(word)+1)))== NULL) return NULL;
  strcpy(dict[*index],word);
  (*count_words)[*index]=1;
  (*index)++;
   if (*index==*size_dict)
   {
     *size_dict+=DELTA_SIZE;
      if ((work_dict = (char **)realloc(dict,*size_dict* sizeof(char *)))==NULL) return NULL;
      dict=work_dict;
      if ((work_count_words = (int *) realloc(*count_words, *size_dict*sizeof(int)))==NULL) return NULL;
      *count_words=work_count_words;
   }
  return dict;
}

//-------------------------------------------------------------------------------------------------
int FindInToDictionary(char **dict, int index_dict, char *word)
{
  int i;
  int flag=-1;
  for (i=0; i< index_dict; i++)
    if (strcmp(dict[i],word)==0)
		  return i;
	
	return -1;
}

//------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------
int my_fgetc(FILE *fp)
{
  int ch;
  ch=getche();
  if (ch==26) return EOF;
  if (ch=='\r')
  {
    printf("\n");
    ch='\n';
  }
  return ch;
}

//-----------------------------------------------------------------------------
void cyr_lat_toupperCP1251(unsigned char *line)
{
   int i, len;
   len=strlen(line);
   for(i=0; i<len; i++)
   {
     if(line[i]>=0xE0)
       line[i]=line[i]-0x20;
     else
       line[i]=(unsigned char)toupper(line[i]);
   }
}
//-------------------------------------------------------------------------------
void cyr_lat_tolowerCP1251(unsigned char *line)
{
   int i, len;
   len=strlen(line);
   for(i=0; i<len; i++)
   {
     if(line[i]>=0xC0 && line[i]<=0xDF)
       line[i]=line[i]+0x20;
     else
       line[i]=(unsigned char)tolower(line[i]);
   }
}
//-------------------------------------------------------------------------------------
FILE *GetNameFile(char *name_file, char *mode, char *text)
{
  FILE *fp;
  int err;
 
  do
  {
    printf("\nВъведете име на файла %s:",text);
	  err= scanf("%s", name_file);
	} while(err!=1);
	if ((fp=fopen(name_file,mode))==NULL)
	{
	  printf("\nФайлът <%s> не може да се отвори - error No % d !!!\n",name_file,errno);
	  printf("ГРЕШКА No %d %s",errno,strerror( errno ));
  }
	else
    printf("\nФайлът <%s> е отворен успешно за обработка !\n\n", name_file);
	return fp;
}

//------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------
void PrintErrors(int err, char *name_file, char *name_dict)
{
  switch(err)
  {
    case 0:
			printf("\n\nРечникът е зреден от файла <%s>, като е бил създаден от файла <%s> !\n ",name_dict, name_file);
    break;
    case 1:
  		printf("\n\nГРЕШКА - липсва името на изходния файл, от които е създаден речника !!!\n ");
    break;
    case 2:
								 printf("\n\nГРЕШКА при четене на текуща дума от речника");
    break;
    case 3:
		  printf("\n\nГРЕШКА - недостатъчна памет за възтановяване на речника !!!\n ");
    break;
  }
}
//------------------------------------------------------------------------------------------------
