#include "Header.h"
char *txt_menu_g[] =
{
	"Програмно меню:",
	"Избор на входен файл",
	"Преброяване на думите.",
	"Записване на думите във файл.",
	"Преброяване на изреченията.",
	"Записване на изреченията във файл.",
	"Разпознаване на С константи.",
	"Разпознаване на реални константи.",
	"Проверка за валидна Windows директория.",
	"Изход.",
	NULL
};

int main()
{
	int mode = 0, choice = 0;
	int flag = 0;
	FILE *fp_in = NULL, *fp_out = NULL;

	char name_file[256], name_out[256], path[256];
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("COLOR 0A");
	do
	{
		mode = menu(txt_menu_g);
		switch (mode)
		{
		case 1:
			printf("\nНапишете името на файла: ");
			scanf("%s", name_file);
			if ((fp_in = fopen(name_file, "r")) == NULL)
			{
				printf("\nГрешка: няма отворен файл !!!\n");
				_getch();
			}
			else
			{
				printf("\nOK - Файлът %s е отворен!\n", name_file);
				flag = 1;
				_getch();
			}
			break;

		case 2:
			if (flag == 0)
			{
				printf("\nМоля изберете файл !!!");
				_getch();
				break;
			}
			printf("\n Броят на думите е %d", words(fp_in));
			_getch();
			break;

		case 3:
			if (flag == 0)
			{
				printf("\nМоля изберете файл !!!");
				_getch();
				break;
			}
			printf("\nНапишете името на файла за записване на думите: ");
			scanf("%s", name_out);

			fp_out = fopen(name_out, "w");
			copy_words(fp_in, fp_out);
			printf("\nГотово !!!");
			_getch();
			break;

		case 4:
			if (flag == 0)
			{
				printf("\nМоля изберете файл !!!");
				_getch();
				break;
			}
			printf("\n Броят на изреченията е %d", sentences(fp_in));
			_getch();
			break;

		case 5:
			if (flag == 0)
			{
				printf("\nМоля изберете файл !!!");
				_getch();
				break;
			}
			printf("\nНапишете името на файла за записване на изреченията: ");
			scanf("%s", name_out);

			fp_out = fopen(name_out, "w");
			copy_sentences(fp_in, fp_out);
			printf("\nГотово !!!");
			_getch();
			break;

		case 6:
			if (flag == 0)
			{
				printf("\nМоля изберете файл !!!");
				_getch();
				break;
			}
			int_constant(fp_in);
			_getche();
			break;

		case 7:
			if (flag == 0)
			{
				printf("\nМоля изберете файл !!!");
				_getch();
				break;
			}
			real_constant(fp_in);
			_getche();
			break;

		case 8:
			printf("Въведете директория за проверяване: ");
			scanf("%s", path);
			if (valid_directory(path))
				printf("Въведената директория е валидна.\n");
			else
				printf("Въведената директория е не валидна.\n");
			_getche();
			break;

		case 9:
			exit(1);
			break;
		default:
			printf("\nНевалиден избор !!!\n");
			_getch();
		}
		system("cls");
	} while (1);

	fclose(fp_out);
	fclose(fp_in);
	return 0;
}