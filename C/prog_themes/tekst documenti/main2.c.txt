#include "Header.h"

char *txt_menu_g[] =
{
	"МЕНЮ:",
	"Създаване на речника.",
	"Извеждане на речника на екрана.",
	"Търсене на дума в речника.",
	"Сортиране на речника.",
	"Запис на речника.",
	"Зареждане на речника от текстови файл.",
	"Кодиране / Декодиране.",
	"Изход .",
	NULL
};

char *sub_menu_1[] =
{
	"Избор на файл за обработка:",
	"От клавиатурата до въвеждане на CTRL/Z.",
	"От текстови файл.",
	"Назад",
	NULL
};

char *sub_menu_2[] =
{
	"Избор на начин на сортировка:",
	"Сортиране по азбучен ред.",
	"Сортиране по честота (брой) на срещане на думата.",
	"Назад",
	NULL
};

char *sub_menu_3[] =
{
	"Избор на начин за записване:",
	"Всяка дума на нов ред и срещу нея честотата.",
	"Записване на бройката в отделен файл с разширение \".cnt\".",
	"Назад",
	NULL
};

char *sub_menu_4[] =
{
	"Кодиране / Декодиране :",
	"Кодиране.",
	"Декодиране.",
	"Назад",
	NULL
};

int main()
{
	char **words = NULL;
	int *count = NULL;
	int total = 0;

	int flag = 0; //ima li rechnik

	int choice; //glavnoto menu
	int mode1; //purvoto pod-menu
	int mode2; //vtoroto pod-menu
	int mode3; //tretoto pod-menu
	int mode4; //4etvurtoto pod-menu

	char fname[40]; //imeto na faila za chetene

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//system("COLOR 0A");
	do
	{
		choice = menu(txt_menu_g);
		switch (choice)
		{
		case 1:
			mode1 = menu(sub_menu_1);
			make_dict(&words, &count, &total, mode1, fname, &flag);
			break;

		case 2:
			if (flag != 1)
			{
				printf("\nРечникът не съществува!\n");
				_getche();
					break;
			}
			print_dict(words, count, total);
			_getch();
			break;

		case 3:
			if (flag != 1)
			{
				printf("\nРечникът не съществува!\n");
				_getche();
				break;
			}
			srch(words, count, total);
			_getch();
			break;

		case 4:
			if (flag != 1)
			{
				printf("\nРечникът не съществува!\n");
				_getche();
				break;
			}
			mode2 = menu(sub_menu_2);
			sort(words, count, total, mode2);
			_getch();
			break;

		case 5:
			if (flag != 1)
			{
				printf("\nРечникът не съществува!\n");
				_getche();
				break;
			}
			mode3 = menu(sub_menu_3);
			save(words, count, total,mode1, mode3, fname);
			_getch();
			break;

		case 6:
			load(&words, &count, &total, fname);
			flag = 1;
			mode1 = 2;
			_getche();
			break;

		case 7:
			if (flag != 1)
			{
				printf("\nРечникът не съществува\n");
				_getche();
				break;
			}
			mode4 = menu(sub_menu_4);
			code(words, count, total, mode4, fname);
			_getche();
			break;

		case 8:
			exit(1);
			break;

		default:
			_getch();
		}
		system("cls");
	} while (1);

	
	free(count);
	free(words);

	_getche();
	return 0;
}