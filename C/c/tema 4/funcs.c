#include "Header.h"

void make_dict(char ***words, int **count, int *X, int mode, char fname[],int *K)
{
	char line[256];
	char input[25];
	char *temp;

	int i=0, k=0;
	int flag = 0;
	int exists = 0;
	
	char **temp2 = NULL;
	int *temp3;
	int temp4 = 0;

	FILE *fp;

	switch (mode)
	{
	case 1:
		printf("\nВъведете текст-а и за край натистнете CTRL/Z:\n");
		temp3 = (int*)malloc((1)*sizeof(int));
		while ((gets(line) != NULL))
		{
			temp = strtok(line, " ,./\n\t?!:;\\<>\'-\"()&%#*+[]{}=");

			while (temp != NULL)
			{

				strcpy(input, temp);
				temp = strtok(NULL, " ,./\n\t?!:;\\<>\'-\"()&%#*+[]{}=");
				temp2 = (char **)realloc(temp2, (temp4 + 1) * sizeof(char *));
				temp3 = (int  *)realloc(temp3, (temp4 + 1)*sizeof(int));
				if (flag == 0)
				{
					temp3[temp4] = 1;
					temp2[temp4++] = _strdup(input);
					flag = 1;
				}
				else
				{
					for (k = 0; k<temp4; k++)
					{
						if ((strcmp(input, temp2[k])) == 0)
						{
							temp3[k]++;
							exists = 1;
						}
					}

					if (exists == 0)
					{
						temp3[temp4] = 1;
						temp2[temp4++] = _strdup(input);
					}
				}
				exists = 0;
			}
		}

		*words = temp2;
		*count = temp3;
		*X = temp4;
		*K=1;
		break;

	case 2:
		printf("Въведете файл за четене: ");
		scanf("%s", fname);

		if ((fp = fopen(fname, "r")) == NULL)
		{
			printf("\nФайлът \"%s\" не може да се отвори !", fname);
			_getche();
			return;
		}
		else
		{
			temp3 = (int*)malloc((1)*sizeof(int));
			while ((fgets(line, sizeof(line), fp) != NULL))
			{
				temp = strtok(line, " ,./\n\t?!:;\\<>\'-\"()&%#*+[]{}=");

				while (temp != NULL)
				{

					strcpy(input, temp);
					temp = strtok(NULL, " ,./\n\t?!:;\\<>\'-\"()&%#*+[]{}=");
					temp2 = (char **)realloc(temp2, (temp4 + 1) * sizeof(char *));
					temp3 = (int  *)realloc(temp3, (temp4 + 1)*sizeof(int));
					if (flag == 0)
					{
						temp3[temp4] = 1;
						temp2[temp4++] = _strdup(input);
						flag = 1;
					}
					else
					{
						for (k = 0; k < temp4; k++)
						{
							if ((strcmp(input, temp2[k])) == 0)
							{
								temp3[k]++;
								exists = 1;
							}
						}

						if (exists == 0)
						{
							temp3[temp4] = 1;
							temp2[temp4++] = _strdup(input);
						}
					}
					exists = 0;
				}
			}

			*words = temp2;
			*count = temp3;
			*X = temp4;
			*K=1;
			break;
		}
			fclose(fp);
	default:
		break;
	}
	
}

void print_dict(char **words, int *count, int strcount)
{
	int i;

	for (i = 0; i<strcount; i++)
	{
		printf("%s - %d\n", words[i], count[i]);
	}
}

void srch(char **words, int *count, int strcount)
{
	char search[20];
	int i;
	int flag = 0;

	printf("\nВъведете дума за търсене: ");
	scanf("%s", search);

	for (i = 0; i<strcount; i++)
	{
		if (strcmp(search, words[i]) == 0)
		{
			if (count[i] != 1)
				printf("\nДумата \"%s\" се повтаря %d пъти.\n", words[i], count[i]);
			else
				printf("\nДумата \"%s\" се повтаря %d път.\n", words[i], count[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("\nДумата \"%s\" не съществува в речника!\n", search);
}

void sort(char **words, int *count, int strcount, int mode2)
{
	int i, j;
	char temp[30];
	int temp2;

	switch (mode2)
	{
	case 1:
		for (i = 1; i < strcount; i++)
		{
			for (j = 1; j < strcount; j++)
			{
				if (strcmp(words[j - 1], words[j]) > 0)
				{
					strcpy(temp, words[j - 1]);
					strcpy(words[j - 1], words[j]);
					strcpy(words[j], temp);

					temp2 = count[j - 1];
					count[j - 1] = count[j];
					count[j] = temp2;
				}
			}
		}
		break;

	case 2:
		for (i = 1; i < strcount; i++)
		{
			for (j = 1; j < strcount; j++)
			{
				if (count[j - 1] < count[j])
				{
					strcpy(temp, words[j - 1]);
					strcpy(words[j - 1], words[j]);
					strcpy(words[j], temp);

					temp2 = count[j - 1];
					count[j - 1] = count[j];
					count[j] = temp2;
				}
			}
		}
		break;
	default:
		break;
	}
}

void save(char **words, int *count, int strcount,int mode1, int mode3, char f[])
{
	int i;
	char fname[50];
	char fcount[50];

	FILE *fp; //izhoden fail s dumite
	FILE *fc; //izhoden fail s broikata

	printf("\nВъведете името на файла за записване на речника:");
	scanf("%s", fname);

	fp = fopen(fname, "w");

	if (mode1 == 1)
		fprintf(fp, "Rechnika e suzdaden pri vuvejdane ot klaviaturata\n");
	else
		fprintf(fp, "Rechnika e suzdaden ot fail \"%s\"\n", f);

	switch (mode3)
	{
	 case 1:
		for (i = 0; i < strcount; i++)
			fprintf(fp, "%s - %d\n", words[i], count[i]);
		fclose(fp);
		break;
	 case 2:
		 strcpy(fcount, fname); 

		 if (strchr(fcount, '.'))
			 strcat(fcount, ".cnt");

		fc = fopen(fcount, "w");
		for (i = 0; i < strcount; i++)
		{
			fprintf(fp, "%s\n", words[i]);
			fprintf(fc, "%d\n", count[i]);
		}
		fclose(fp);
		fclose(fc);

	 case 3:
		 break;
	}
	printf("\nГотово!");

}

void load(char ***words, int **count, int *X, char fname[])
{
	char line[256];
	char input[25];
	int i=0, k=0;
	int flag = 0;
	int exists = 0;
	char *temp;

	char **temp2 = NULL;
	int *temp3;
	int temp4 = 0;

	FILE *fp;

	printf("Въведете файл за четене: ");
	scanf("%s", fname);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		printf("\nФайлът \"%s\" не може да се отвори !", fname);
		return;
	}

	temp3 = (int*)malloc((1)*sizeof(int));
	while ((fgets(line, sizeof(line), fp) != NULL))
	{
		temp = strtok(line, " ,./\n\t?!:;\\<>\'-\"()&%#*+[]{}=");

		while (temp != NULL)
		{

			strcpy(input, temp);
			temp = strtok(NULL, " ,./\n\t?!:;\\<>\'-\"()&%#*+[]{}=");
			temp2 = (char **)realloc(temp2, (temp4 + 1) * sizeof(char *));
			temp3 = (int  *)realloc(temp3, (temp4 + 1)*sizeof(int));
			if (flag == 0)
			{
				temp3[temp4] = 1;
				temp2[temp4++] = _strdup(input);
				flag = 1;
			}
			else
			{
				for (k = 0; k<temp4; k++)
				{
					if ((strcmp(input, temp2[k])) == 0)
					{
						temp3[k]++;
						exists = 1;
					}
				}

				if (exists == 0)
				{
					temp3[temp4] = 1;
					temp2[temp4++] = _strdup(input);
				}
			}
			exists = 0;
		}
	}

	*words = temp2;
	*count = temp3;
	*X = temp4;
	printf("Готово!");
}

void code(char **words, int *count, int strcount, int mode4, char fp[])
{
     int i;
     int k;
	 int l;

     char fo[50];
     char dc[50];
     char *temp;
     char line[256];
     char input[25];
     char *copy;
     
     FILE *fin;
     FILE *fout;
     FILE *decode;
     
    if((fin=fopen(fp,"r"))==NULL)
     {
       printf("\nФайлът \"%s\" не може да се отвори!",fp);
       _getche();
       return;
     }
     
     switch(mode4)
     {
       case 1:
          
          printf("\nВъведете файл за записване на кодирания текст: ");
           scanf("%s",fo);
           fout=fopen(fo,"w");  
            
         while ((fgets(line, sizeof(line), fin) != NULL))
          { 
              copy=_strdup(line);
              temp = strtok(line, " ,./\n\t?!:;\\<>\'-\"()&%#*+[]{}="); 
                while (temp != NULL)
                 {
                    strcpy(input, temp);
                  
                             for (i = 0; i<strcount; i++)
	                          {
                                if((strcmp(input,words[i]))==0)
	                            {
                                 fprintf(fout,"%d%c",i,copy[temp-line+strlen(temp)]);
                                 if(is_delimiter((copy [temp-line+strlen(temp)+1] )))
								   fprintf(fout,"%c",copy[temp-line+strlen(temp)+1]);
	                             break;
                                }
                              }
                        temp = strtok(NULL, " ,./\n\t?!:;\\<>\'-\"()&%#*+[]{}=");        
                 } 
          }  
          
          fclose(fout);
          fclose(fin);
            break;
            
       case 2:
            printf("\nВъведете файл за декодиране: ");
             scanf("%s",dc);
            if((decode=fopen(dc,"r"))==NULL)
              {
                printf("Файлът \"%s\" не може да се отвори!",dc);
                _getche();
                return;
              }
            printf("\nВъведете файл за записване на декодирането:");
             scanf("%s",fo);
             
             fout=fopen(fo,"w");
             
             while (fgets(line,sizeof(line),decode)!=NULL)
              {
				 l = strlen(line);
                for(i=0;i<l;i++)
                 {
                     if(isdigit(line[i]))
                      {                
                        for (k = 0; k<strcount; k++)
                         {    
                            if(line[i] == k+48)
                            {
                               fprintf(fout,"%s",words[k]);
                               break;
                             }
                         }  
                      } 
                     else
                       fprintf(fout,"%c",line[i]);
                 }    
              }
          fclose(fout);
          fclose(fin); 
          fclose(decode);
            break;
       case 3:
            break;      
                  
     }
printf("\nГотово");
}

int is_delimiter(int c)
{
	int i = 0;
	int delimiter_word[] = { '"', '\'', ' ', ',', '.', '?', '!', ':', ';', '/', '\\', '*',
		'<', '>', '(', ')', '{', '}', '[', ']', '\n', '\t', EOF, 0 };

	while (delimiter_word[i])
	{
		if (c == delimiter_word[i++])
			return 1;
	}
	return 0;
}