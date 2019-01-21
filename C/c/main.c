#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct cars{
    char ID[20];
    char color[50];
    double ob;
    char brand[20];
    double price;
    struct cars*next;
};
struct cars* head=NULL;
struct cars*current=NULL;
void start();
void add();
void search();
void del();
void list();
void ShowAll();
void End();

int main()
{



/* char ID[20];
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
    fclose(fp);



*/



    int choice=0;

    for(;;){
    printf(".:: MENU ::.\n");
    printf("0. Pokaji vsichki klienti zapisani vyv faila  \n");
    printf("1. Vyvejdane na danni za nova kola. \n");
    printf("2. Tyrsene i izvejdane na kola po marka. \n");
    printf("3. Iztrivane na kola ot spisyka. \n");
    printf("4. Spisyk na koli s po golqma cena ot srednata.\n");
    printf("5. Izhod. \n");


 do{
    printf("Vyvedete svoq izbor: ");
    scanf("%d",&choice);
    fflush(stdin);
    } while(!(choice>=0 && choice<=5));
      printf("%d \n",choice);

    //    ShowAll();
    switch(choice)
    {
        case 0:
        {
            start();

            ShowAll();
            head=NULL;
            break;

        }
        case 1:
        {
            start();
            add();
          //  ShowAll();
            End();
            head=NULL;
            break;
        }
        case 2:
        {   start();
            search();
            head=NULL;
            break;
        }
        case 3:
        {   start();
            del();
            End();
            head=NULL;
            break;
        }
        case 4:
        {   start();
            list();
            head=NULL;
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
void start(){
    FILE *fp;
    int i;
    int flag;
    if((fp=fopen("cars","rb"))==NULL){
        printf("Error open file!");
        exit(0);
    }

while(1){
        if(fread(&flag, sizeof(int), 1, fp)!=1)
            {
                printf("Error reading1");

                exit(4);
            }
            if (flag==-1)
            break;

            struct cars *temp=(struct cars*)malloc(sizeof(struct cars));
            if(head==NULL)
            {
                head=temp  ;
                current=head;
                current->next=NULL;
            }
            else
            {
            current->next=temp;
            current=temp;
            current->next=NULL;
            }
          /*  if(fread(&j,sizeof(int),1,fp)!=1){
                printf("error");
                exit (19);
                }*/
            if((fread(temp->ID,flag,1,fp))!=1){
                printf("error");
                exit (20);
                }
            if((fread(&i,sizeof(int),1,fp))!=1){
                printf("error");

                exit (21);
                }
            if((fread(temp->color,i,1,fp))!=1){
                printf("error");
                exit (22);
                }
            if((fread(&temp->ob,sizeof(double),1,fp)!=1)){
                printf("error");
                exit(23);
            }
            if((fread(&i,sizeof(int),1,fp))!=1){
                printf("error");

                exit (21);
                }
            if((fread(temp->brand,i,1,fp))!=1){
                printf("error");
                exit (25);
                }

            if((fread(&temp->price,sizeof(double),1,fp)!=1)){
                printf("error");
                exit(24);
            }


        }
fclose(fp);
}
void add(){

    struct cars *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    struct cars *newEl;
    newEl=(struct cars*) malloc(sizeof(struct cars));
    printf("Enter the new ID ");
    scanf("%s",newEl->ID);
    printf("Enter the new color ");
    scanf("%s",newEl->color);
    printf("Enter the new ob ");
    scanf("%lf",&newEl->ob);
    printf("Enter the new brand ");
    scanf("%s",&newEl->brand);
    printf("Enter the new price ");
    scanf("%lf",&newEl->price);
    newEl->next=NULL;
    temp->next=newEl;
    printf("\nAdd new client : SUCCESSFUL\n\n");
}
void search(){
char *arr;
int flag=0;
arr=(char*)malloc(20);
    printf("Input car brand  : \n \n");
    gets(arr);
struct cars *temp;
temp=(struct cars*)malloc(sizeof(struct cars));
temp=head;
while(temp!=NULL)
{
  if(!(strcmp(temp->brand,arr))){
    printf("ID: %s  color: %s  ob: %.2f   brand: %s price : %.2lf  \n \n", temp->ID, temp->color, temp->ob, temp->brand,temp->price);
    flag=1;
  }
  temp=temp->next;
}
if(flag==0) printf("Can't find brand - %s \n \n",arr);
}
void del(){
    struct cars* prev_item=head;
	struct cars* curr_item=head;
	int f=0;
    char *arr;
    arr=(char*)malloc(20);
    printf("Input car ID : \n");
    gets(arr);
	while(curr_item!=NULL)
	{
		if(strcmp (curr_item->ID, arr) == 0)
		{
			if(curr_item == head)
			{
				head = head->next;
				prev_item = head;
				f=1;
			}
			else
            prev_item->next = curr_item->next;
			free(curr_item);
			curr_item = prev_item;
		}
		prev_item = curr_item;
		if(f == 0)
			curr_item=curr_item->next;
		f=0;
	}
}
void list(){

struct cars*temp;
double sr=0;
int br=0;
temp=head;
char *arr;
arr=(char*)malloc(20);
printf("Input car brand : \n");
gets(arr);
while(temp!=NULL){
    sr=sr+temp->price;
    br++;
    temp=temp->next;
    }
    sr=sr/br;
    printf("cars price > %.2lf are :\n",sr);
    temp=head;
while(temp!=NULL){
    if(temp->ob>sr)
        if(strcmp (temp->brand, arr) == 0)
         printf("ID: %s  color: %s  ob: %.2f   brand: %s price : %d  \n \n", temp->ID, temp->color, temp->ob, temp->brand,temp->price);
    temp=temp->next;
    }
}
void ShowAll(){

      struct cars* temp;
      for(temp=head; temp!=NULL; temp=temp->next)
      {
                printf("ID: %s  color: %s  ob: %.2f   brand: %s price : %.2f  \n \n", temp->ID, temp->color, temp->ob, temp->brand,temp->price);
      }
}
void End(){
    FILE *fp;
    int flag=-1;
    if((fp=fopen("cars","wb"))==NULL){
        printf("Error open file!");
        exit(0);
    }
    struct cars *temp;
    temp=head;
    int j;
    int i;
    int k;
    while(temp!=NULL){
        j=strlen(temp->ID);j++;
        i=strlen(temp->color);i++;
        k=strlen(temp->brand);k++;
        if(fwrite(&j,sizeof(int),1,fp)!=1){
           printf("Error");
           exit(1);
        }
       if(fwrite(temp->ID,j,1,fp)!=1){
            printf("Error");
            exit(1);
       }
       if(fwrite(&i,sizeof(int),1,fp)!=1){
            printf("Error");
            exit(1);
       }
        if(fwrite(temp->color,i,1,fp)!=1){
            printf("Error");
            exit(1);
        }
       if(fwrite(&temp->ob,sizeof(double),1,fp)!=1){
            printf("Error");
            exit(1);
       }
       if(fwrite(&k,sizeof(int),1,fp)!=1){
           printf("Error");
           exit(1);
        }
       if(fwrite(temp->brand,k,1,fp)!=1){
            printf("Error");
            exit(1);
       }
        if(fwrite(&temp->price,sizeof(double),1,fp)!=1){
            printf("Error");
           exit(1);
        }
        temp=temp->next;
    }
     if(fwrite(&flag,sizeof(int),1,fp)!=1){
            printf("Error");
           exit(1);
        }
    fclose(fp);
}
