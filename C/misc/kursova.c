#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void AddNewFirm();
void InsertInList(char IDnumber[], char nameFirm[], char nameBranch[], double income, double debts, int employees);
void PrintDataFirmByName();
void DeleteFirm();
void DeleteElement(int position);
void SortByName();
int UniqueNumber(char UN[]);

struct firms
{
	char IDnumber[13];
	char nameFirm[50];
	char nameBranch[30];
	double income;
	double debts;
	int employees;
	struct firms *link;
};
struct firms *root=NULL;
struct firms *current;

int main()
{
    /*char fileName[20];
    printf("Enter file name from which u want to read the list: ");
    gets(fileName);
    	FILE*fp;
	struct firms current;
    if((fp=fopen(fileName,"rb"))==NULL)
    {
        printf("Error opening file!");
        return;

    }

	while(1)
	{
		if(fread(&current,sizeof(current),1, fp)!=1)
		{
			printf("Error reading file!");
			return 0;
		}

		InsertInList(current.IDnumber, current.nameFirm, current.nameBranch, current.income, current.debts, current.employees);

	}
	fclose(fp);
	*/
	menu();


return 0;
}
void menu()
{
    int choise;
	printf("\n\nChoose an option\n");
	printf("1. Add a new firm\n");
	printf("2.See information about a firm\n");
	printf("3.Firms sorted by name\n");
	printf("4.Delete a firm with a certain amount of debt\n");
	printf("5.Exit\n");
	scanf("%d", &choise);
	switch (choise)
	{
		case 1:
		{
			AddNewFirm();
			menu();
			break;

		}
		case 2:
		{
			PrintDataFirmByName();
			menu();
			break;
		}
		case 3:
		{
			SortByName();
			menu();
			break;
		}
		case 4:
		{
			DeleteFirm();
			menu();
			break;
		}
		case 5:
		{
			printf("Bye");
			exit(1);

		}

	}

}

void AddNewFirm()
{
	struct firms add;
	printf("\nEnter ID number of the firm: ");
	scanf("%s", add.IDnumber);
	if(UniqueNumber(add.IDnumber)==1)
	{
		printf("Please enter exavtly 12 characters which are unique ");
		AddNewFirm();
	}
	else
	{
	printf("\nEnter name of firm:");
	scanf("%s", add.nameFirm);
	printf("\nEnter name of branch: ");
	scanf("%s", add.nameBranch);
	printf("\nEnter income of the firm: ");
	scanf("%lf", &add.income);
	printf("\nEnter debts of the firm: ");
	scanf("%lf",&add.debts);
	printf("\nEnter number of employees: ");
	scanf("%d", &add.employees);
	InsertInList(add.IDnumber, add.nameFirm, add.nameBranch, add.income, add.debts, add.employees);
	}

}
int UniqueNumber(char UN[])
{
	struct firms *p;
	p=root;
	int a=0;
	if(strlen(UN)!=12)
		a=1;
	else
	{
	while(p!=NULL)
	{
		if(strcmp(p->IDnumber, UN)==0)
			a=1;
		p=p->link;
		}
     }
	return a;
}
void InsertInList(char IDnumber[], char nameFirm[], char nameBranch[], double income, double debts, int employees)
{
	struct firms *temp=(struct firms*) malloc(sizeof(struct firms));
	strcpy(temp->IDnumber, IDnumber);
	strcpy(temp->nameFirm, nameFirm);
	strcpy(temp->nameBranch, nameBranch);
	temp->income = income;
	temp->debts= debts;
	temp->employees=  employees;
	if(root==NULL)
	{
		root=temp;
		current=root;
		current->link=NULL;
	}
	else
	{
		current->link=temp;
		current=current->link;
		current->link=NULL;
	}
	}
void PrintDataFirmByName()
{
	struct firms *p;
	p=root;
	char nameFirm[50];
	printf("Enter name of firm you search: ");
	scanf("%s", nameFirm);
	while(p!=NULL)
	{
		if(strcmp(p->nameFirm, nameFirm)==0)
		{
			printf("ID number of the firm:%s\n", p->IDnumber);
			printf("Name of the firm: %s\n", p->nameFirm);
			printf("Branch: %s\n", p->nameBranch);
			printf("Income: %0.2lf\n", p->income);
			printf("Debts of the firm: %0.2lf\n", p->debts);
			printf("number of employees: %d\n", p->employees);
		}
		p=p->link;
	}
}

void DeleteFirm()
{
	struct firms *d;
	d=root;
	double sumd;
	int position=0;
	printf("Enter the debt's sum: ");
	scanf("%lf", &sumd);
	while(d!=NULL)
	{
		position++;
		if(sumd<d->debts)
		{
			DeleteElement(position);
			printf("\nDelete done!");
			position--;
		}
		d=d->link;
	}
}

void DeleteElement(int position)
{
	struct firms *temp=root;
	struct firms *temp1;
	int i=0;
	if(position>1)
	{
		for(i=0; i<position-2;i++)
		{
			temp=temp->link;

		current=temp->link;
		temp1=current;
		current=current->link;
		temp->link=current;
		free(temp1);
		}
	}
	else if(position==1)
	{
		temp1=root;
		root=root->link;
		free(temp1);
	}

}

void SortByName()
{
	//temp1-current, temp2-next, temp3-previous, temp4-end, temp5-temporary//
	struct firms *temp1,*temp2,*temp3,*temp4,*temp5, *p;
    temp4=NULL;
    while(temp4!=root->link)
    {
        temp3=temp1=root;
        temp2=temp1->link;
        while(temp1!=temp4)
        {
            if(strcmp(temp1->nameBranch,temp2->nameBranch)>0)
            {
				if(temp1==root)
                {
                    temp5=temp2->link;
                    temp2->link=temp1;
                    temp1->link=temp5;
                    root=temp2;
                    temp3=temp2;
                }
                else
                {
				temp5=temp2->link;
                temp2->link=temp1;
                temp1->link=temp5;

                temp3->link=temp2;
                temp3=temp2;
                }

			}
                else
                {
                    temp3=temp1;
                    temp1=temp1->link;
                }
                temp2=temp1->link;
                if(temp2==temp4)
                {
                    temp4=temp1;
                }
            }
	}
	p=root;
		while(p!=NULL)
	{
			printf("ID number: %s\n", p->IDnumber);
			printf("nameFirm: %s\n", p->nameFirm);
			printf("Branch: %s\n", p->nameBranch);
			printf("Income: %0.2lf\n", p->income);
			printf("Debts: %0.2lf\n", p->debts);
			printf(" Employess: %d\n\n\n\n", p->employees);
			p=p->link;
	}
}
