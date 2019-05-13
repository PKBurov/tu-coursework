#include"Header.h"

int main()
{
	/*char ID[20];
	char color[50];
	char brand[20];
	double ob,price;
	int i,j,k;
	int flag=-1;
	FILE *fp;
	fp=fopen("cars","wb");
	printf("Enter the new ID ");
	scanf("%s",ID);
	j=strlen(ID);j++;
	printf("Enter the new color ");
	scanf("%s",color);
	i=strlen(color);i++;
	printf("Enter the new ob ");
	scanf("%lf",&ob);
	 printf("Enter the new brand ");
	scanf("%s",brand);
	k=strlen(brand);k++;
	printf("Enter the new price ");
	scanf("%lf",&price);
	fwrite(&j,sizeof(int),1,fp);
	fwrite(ID,j,1,fp);
	fwrite(&i,sizeof(int),1,fp);
	fwrite(color,i,1,fp);
	fwrite(&ob,sizeof(double),1,fp);
	fwrite(&k,sizeof(int),1,fp);
	fwrite(brand,k,1,fp);
	fwrite(&price,sizeof(double),1,fp);
	fwrite(&flag,sizeof(int),1,fp);
	fclose(fp);*/

	//tuka az praveh neshto;


	struct student *head = NULL;
	struct student *current = NULL;

	int choice = 0;

	for (;;)
	{

		printf(".:: MENU ::.\n");
		printf("0. Pokaji vsichki studenti zapisani vyv faila  \n");
		printf("1. Vyvejdane na danni za nov student \n");
		printf("2. Tyrsene i izvejdane na student po familno ime. \n");
		printf("3. Iztrivane na student po faculteten nomer. \n");
		printf("4. Izvejdane na spisyk s studenti ot predvaritelno izbrana grupa po azbuchen red.\n");
		printf("5. Izhod. \n");


		do
		{
			printf("Vyvedete svoq izbor: ");
			scanf("%d", &choice);
			fflush(stdin);
		} while (!(choice >= 0 && choice <= 5));
		printf("%d \n", choice);

		//    ShowAll();
		switch (choice)
		{
		case 0:
		{
			/*start();*/

			show_all();
			head = NULL;
			break;

		}
		case 1:
		{
			/*start(head);
			add(head);*/
			end();
			head = NULL;
			break;
		}
		case 2:
		{
			/*start();
			search();*/
			head = NULL;
			break;
		}
		case 3:
		{
			/*start();
			del();*/
			end();
			head = NULL;
			break;
		}
		case 4:
		{
			/*start();*/
			list_by_alpha();
			head = NULL;
			break;
		}
		case 5:
		{
			exit(5);
		}
		}

	}
	return 0;
}