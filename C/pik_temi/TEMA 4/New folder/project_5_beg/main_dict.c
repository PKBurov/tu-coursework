
#include <stdio.h>
#include <conio.h>

#include <windows.h>

#include "menu.h"
#include "dict_func.h"


//------------- менюта -----------------------
char *txt_menu_g[]=
{
	  "Програма <РЕЧНИК>\n--------------------",
		"избор на вход за текста",
		"създване на речник на текста",
		"извеждане речника на екрана",
		"търсене на дума в речника",
		"сортиране на речника",
    "запис/зареждане на речник",
    "кодиране/декодиране на текста",
		"КРАЙ",
		NULL
};

char *txt_menu_1[]=
{
			"---ВХОДЕН ТЕКСТ---",
			"от клавиатура",
			"от текстови файл",
      "ОТКАЗ от избор",
      NULL
};

char *txt_menu_2[]=
{
   "ИЗБОР НА ТИПА СОРТИРОВКА:",
		"по азбучен ред",
		"по брой срещания на думата в текста",
    "ОТКАЗ от избор",
		NULL
};

char *txt_menu_3[]=
{
   "---ОБМЕН на РЕЧНИКА---",
		"запис във файл",
		"зареждане от файл",
    "ОТКАЗ от избор",
		NULL
};
char *txt_menu_4[]=
{
   "---ОБРАБОТКА---",
	"кодиране на текст",
	"декодиране на текст",
    "ОТКАЗ от избор",
	NULL
};

void empty_function (int mode)
{
  printf("\n\n    Празна функция !!! -  избран режим %d\n\n   за продължение - произволен клавиш !!!\n\n",mode);
  getch();  
}
//--------------------------------------------

int main()
{
	int mode, submenu, err;
	FILE *fp_in=NULL,        //--- файлов указател за входен файл ---
       *fp_dict=NULL,      //--- файлов указател за изходен файл на речника ---
       *pcode_file;        //--- файлов указател за кодирания файл ------------
	char name_file[256],name_dict[256], name_code[256];
  //------------------------------------------------------
	char **dict=NULL;        //---динамичен  масив от указатели за съхраняване думите на речника ---
  int *count_words=NULL;   //---динамичен int масив за броя на срещанията на думите в речника ----
  int size_dict=SIZE_DICT; //---текущ размер на речника --
  int index_dict=0;        //---актуален индекс за съхраняване на нова дума в речника -----------
	unsigned long br_words=0;
  int status;

//---------------------------------------
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
//---------------------------------------

  do
	{
	  mode=menu(txt_menu_g);
    switch (mode)
		{
	    case 1:
				{
          submenu=menu(txt_menu_1);
			    switch(submenu)
					{
			      case 1:
            fp_in = stdin;
				    printf("\nвход от КЛАВИАТУРА - за край Въведете - <cntrl/Z> !!!\n\n");
				    break;
			      case 2:
					  do
						{
						  printf("\nВъведете име на фаила за обработка:");
					    err= scanf("%s", name_file);
						} while(err!=1);
					  if ((fp_in=fopen(name_file,"rt"))==NULL)
						{
						  printf("\nФайлът <%s> не може да се отвори - error No % d !!!\n",name_file,errno);
						  printf("ERRROR No %d %s",errno,strerror( errno ));
						}
						else
              printf("\nФайлът <%s> е отворен успешно за обработка !", name_file);
				   break;
					}
	       break;
			 }
	    case 2:
        if (fp_in==NULL)
				  printf("\n    missing input file !!!");
				else
				{
					DeleteDictionary(dict,count_words, index_dict); dict=NULL; size_dict=SIZE_DICT; count_words=0;
					rewind(fp_in);
          dict=MakeDictionary(fp_in, dict, &size_dict, &index_dict, &count_words, &status);
				}
			break;

      case 3:
			  PrintDictionary(dict, index_dict, count_words, status);
			break;

	    case 4:
        empty_function (mode);      
			break;

	    case 5:
        empty_function (mode);      
			break;

	    case 6:
        empty_function (mode);      
			break;

	    case 7:
        empty_function (mode);      
			break;
    }
	}while (mode != 8);
}

