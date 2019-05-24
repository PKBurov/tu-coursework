#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "menu.h"
#include "func.h"
char *txt_menu_g[] =
{
	"-----Поддържане на информация за студенти-----",
	"Нов файл..................................................................................",
	"Извеждане на съществуващ списък...........................................................",
	"Добавяне на нов студент в списака с информация за студен..................................",
	"Търсене на студент по фамилно име.........................................................",
	"Изтриване на студента по факултетен номер (№).............................................",
	"Извеждане на списък на студентите от зададена група, подредени по азбучен ред на имената..",
	"Изход...........................................",
	NULL
};
char *txt_menu2[] =
{
	"-----Поддържане на информация за студенти-----",
	"Създаване на нов файл.............................................................................",
	"Отваряне на съществуващ такъв.....................................................................",
	NULL
};
//----------------------------------------------------------

int main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	FILE *f;
	int index, i = 0,len;
	int chislo,flag=0;
	short mode, mode2;
	char znak;
	char name[50];
	char s[10];
	char t[20];
	int t2 = 0;
	STD p;
	node **p2, **ps1 = NULL;
	node *head = NULL;
	do{
		system("cls");
		mode = menu(txt_menu_g);
		switch (mode){

		case 1:
			mode2 = menu(txt_menu2);
			if (mode2 == 1){
				if ((f = fopen("student.dat", "wb")) != NULL)
				{
					do{
						printf("Факултетен номер на студента (№), за да прекратите въвеждането си, въведете символа '*':");
						do{
							scanf("%9s", p.faculty_number);
							len = strlen(p.faculty_number);
							if (!strcmp(p.faculty_number, "*"))break;
						} while (len != 9);
						if (!strcmp(p.faculty_number, "*"))break;
						printf("Първото име на студента:");
						scanf("%19s", p.student_first_name);
						printf("Презимето на студента:");
						scanf("%19s", p.student_sur_name);
						printf("Фамилното име на студента:");
						scanf("%19s", p.student_familly_name);
						printf("Име на факултета в които студента се обучава:");
						scanf("%19s", p.faculty);
						printf("Име на специалност в която се обучава:");
						scanf("%19s", p.major);
						printf("Ноемра на групата на студента:");
						scanf("%d", &(p.group));
						printf("Година на обучение на студента (курс) :");
						scanf("%d", &(p.year));
			

						fwrite(&p, sizeof(STD), 1, f);
						printf("Структурата е успешно записана във файла\n");
					} while (1);
					fclose(f);
					printf("Файлът беше създаден!(\n");

				}
				else
				{
					printf("Грешка при отваряне на файла!\n"); exit(1);
				}

				if (!(f = fopen("student.dat", "rb"))){
					printf("Грешка при отваряне на файла!\n"); exit(1);
				}
				if (ferror(f)) {
					printf("Грешка при отваряне на файла!\n");
					break;
				}
				head = make_lst(head, f);
				flag = 1;
				prt(head);
				break;
			}
			if (mode2 == 2)
			{
				printf("Напиши името на битовия файл\n");
				scanf("%s", name);
				if (!(f = fopen(name, "rb"))){
					printf("Грешка при отваряне на файла!\n"); exit(1);
				}
				head = make_lst(head, f);
				flag = 1;
				prt(head);
				if (ferror(f)) {
					printf("Грешка при четене на файла \n");
					break;
				}
				fclose(f);
				break;
			}
			else { printf("Пробвай с 1 или 2\n"); system("pause"); break; }
		case 2:
			if (flag == 1)
			{
				prt(head);
				system("pause");
			}
			break;
		case 3:
			if (flag == 1)
			{
				head = add(head);
				printf("Добавен");
				system("pause");
		    }
			break;
		case 4:
			if (flag == 1)
			{
				printf("Въведете ФАМИЛНОТО име на студента който бихте искали да видите:");
				fflush(stdin);
				scanf("%19s", t);
				search_list(head, t);
			}
			break;
		case 5:
			if (flag == 1) {
				printf("Въведете факултетния номер (№) на студента който желаете да изтриете от списака:");
				scanf("%9s", &s);
				head = search(head, s);
				break;
			}
			else
			{
				printf("Направи файл");
				system("pause");
			}
			break;
		case 6:
				printf("Въведете групата на студентите които бихте искали да видите:");
				fflush(stdin);
				scanf("%d", &t2);
				sort(head, t2);
				system("pause");
			break;
		}
		
	} while (mode!=7);
	head = free_m(head);
	return 0;
}
