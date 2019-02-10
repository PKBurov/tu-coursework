#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "my_functions_automat.h"

//------------- менюта -----------------------
char *txt_menu_g[] =
{
	  "PROGRAM TEXT FILE:",
		"Select an input file",
		"Compute words",
		"Compute sents",
		"Compute for Long constant",
		"......",
		"Exit",
		NULL
};

void empty_function(int mode)
{
	printf("\n\n Empy Function !!! -  actual mode %d\n\n   Press any key to continue !!!\n\n", mode);
	_getch();
}
//--------------------------------------------

int main()
{
	int mode; 
	short flag1 = 0, flag2 = 0;
	FILE *fp_in = NULL, *fp_out = NULL;
	char name_file[256], name_out[256];
	//------------------------------------------------------
	unsigned long br_words = 0, br_sents = 0, br_conts = 0;
	//------------------------------------------------------------------------
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	do
	{
		mode = menu(txt_menu_g);
		switch (mode)
		{
			case 1:
			system("cls");
			if ((fp_in = get_name_file(name_file, "rt", "за четене")) != NULL)
				flag1 = 1;
			if ((fp_out = get_name_file(name_out, "wt", "за запис")) != NULL)
				flag2 = 1;
			break;
			//--------------------------------------------------------------------------------------------------
			case 2: if (flag1 == 0 && flag2 == 0){
			printf("\nНе сте отворили файл за обработка или файлът за запис!\n"); 
			printf("\n");
			system("pause");
			break;
			}
			br_words = words(fp_in, fp_out);
			if (br_words)
			fprintf(fp_out,"\n\n Computed %d word/s in to file: %s\n\n", br_words, name_file);
			fclose(fp_out);
			break;
			//--------------------------------------------------------------------------------------------------
			case 3: if (flag1 == 0 && flag2 == 0){
			printf("\nНе сте отворили файл за обработка или файлът за запис!\n");
			printf("\n");
			system("pause");
			break;
			}
			br_sents = sents(fp_in, fp_out);
			if (br_sents)
			fprintf(fp_out,"\n\n Computed %d sentence/s in to file: %s\n\n", br_sents, name_file);
			fclose(fp_out);
			break;
			//--------------------------------------------------------------------------------------------------
			case 4: if (flag1 == 0 && flag2 == 0){
			printf("\nНе сте отворили файл за обработка или файлът за запис!\n");
			printf("\n");
			system("pause");
			break;
			}
			br_conts = conts(fp_in,fp_out);
			if (br_conts)
			fprintf(fp_out,"\n\n Computed %d sentence/s in to file: %s\n\n", br_conts, name_file);
			fclose(fp_out);
			break;
			//--------------------------------------------------------------------------------------------------
			case 5: if (flag1 == 0 && flag2 == 0){
			printf("\nНе сте отворили файл за обработка или файлът за запис!\n");
			printf("\n");
			system("pause");
			break;
			}
			empty_function(mode);
			break;
		}
	} while (mode != 6);
	_fcloseall();
}//---------------------------------End of program----------------------------------