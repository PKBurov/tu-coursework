#include <stdlib.h>
#include <stdio.h>
typedef struct {
         int  age; 
         char name[20]; 
}inf;
int main(int argc, char *argv[]){
   char m[]="Satelit",*p=m;
   int x,y; 
   char *ar[]= {"Ivan","Kostadin","Rositsa"};
   inf st[] = {{13,"Leon"}, {25,"Plamen"}};
   x=0x92;y=2;x<<=1;y>>=1;printf("1:%x %x\n",x,y);
   x=0x22;printf("2:%x %x %x\n",x|3,x&3,x^3);   
   x=0x11; y=1;printf("3:%x\n", x&(~y));
   printf("4: %c %c %s\n", *(m+1), *m+1, m+1);
   printf ("5: %c %s\n", p[3],p+3);  
   printf ("6: %s  %s \n", *(ar+1), *ar+1);
   printf("7: %c %c\n", **(ar+1), *(*ar+1));
   printf("8: %d  %s \n",st[0].age, st[1].name+1);
   printf("9: %d %s \n",(st+1)->age,st->name+2);
   printf("10:%c %c %c\n",*(st->name),*((st+1)->name),*(st->name+1));
   system("pause");
   return 0;
}
