#include <stdio.h>
#include <windows.h>
#include <conio.h>
int dostignal = 0;
//definirame funckciite
void menu();
void cfpf();
void cfpe();
char* FailVString(char *FileName, int numChars);
int countPrisvoqvane(char StringZapazvasht[5000]);
int CountOperators(char StringZapazvasht[5000]);
void cepf();
void cepe();
void clearInput();
//main funkciq v koqto se suzdava menuto i se izvikvat vsichki ostanali funkcii
int main()
{
	int izbor;
	/* bezkraen while cikul za da moje potrebitelqt da izpolzva programata mnogokratno pri otvarqne..
	cikulut shte spre pri 5, toest shte izleze ot programata */
	do
	{
		system("cls");
		menu();
		printf("Izberi opciq: ");
		scanf("%d", &izbor);

		if (izbor == 5)
			break;

		else if (izbor == 1)
		{
			clearInput();
			cfpf();
		}
		else if (izbor == 2)
		{
			clearInput();
			cfpe();
		}

		else if (izbor == 3)
		{
			clearInput();
			cepf();
		}
		else if (izbor == 4)
		{
			clearInput();
			cepe();
		}

		else {}

		clearInput(); //clear the input buffer in case of user entering a char for a izbor
	} while (1);

	return 0;
}


//funkciqta poluchava ime na faila i kolko znaka e samiqt fail. proverqva dali zavurshva s razshirenie .c i otvarq faila...sled tova
//go prochita red po red i zapisva cqlata informaciq v bufer koito posle se vrushta kato rezultat ot funkciqta
char* FailVString(char *FileName, int numChars)
{
	int i = 0;
	int lineNumber = 1;
	char fileData[100];
	char *StringNaDanniteOtFaila = malloc(sizeof(char) * (5000));
	FILE *fileIn;
	dostignal = 0;

	if ((FileName[numChars - 1] == 'c' || FileName[numChars - 1] == 'C') && FileName[numChars - 2] == '.')
	{

		fileIn = fopen(FileName, "r");
		if (fileIn == NULL)
		{
			printf("\nThe file cannot be open!\n");
		}
		printf("The information read from file is:\n");
		while (fgets(fileData, sizeof(fileData), fileIn) != NULL)
		{
			printf("%d:", lineNumber);
			i = 0;
			while (fileData[i] != '\0')
			{
				StringNaDanniteOtFaila[dostignal] = fileData[i];
				printf("%c", StringNaDanniteOtFaila[dostignal]);
				dostignal++;
				i++;
			}
			lineNumber++;
		}
		fclose(fileIn);
		StringNaDanniteOtFaila[dostignal] = '\0';

	}
	else
	{
		printf("Wrong input file!\n");
	}
	return StringNaDanniteOtFaila;
}
//otvarq fail koito potrebitelqt si izbira, prochita go, sled tova prochetenoto go obrabotva i izvejda rezultata v nov fail.
void cfpf()
{
	short i = 0;
	int prisvoqvane;
	int operatorite;
	int numChars = 0;
	char inFile[20];
	char outFile[20];
	char *pointerToData;

	FILE *fileOut;

	printf("Enter the name of the file you want to load: ");
	fgets(inFile, sizeof(inFile), stdin);
	inFile[strcspn(inFile, "\r\n")] = 0;

	printf("Enter the name of the file in which will save the result: ");
	fgets(outFile, sizeof(outFile), stdin);
	outFile[strcspn(outFile, "\r\n")] = 0;

	while (inFile[i] != '\0')
	{
		i++;
		numChars++;
	}

	fileOut = fopen(outFile, "w");

	pointerToData = FailVString(inFile, numChars);

	prisvoqvane = countPrisvoqvane(pointerToData);
	operatorite = CountOperators(pointerToData);
	fprintf(fileOut, "Prisvoqvaniqta sa:%d\nOperatorite sa:%d\n", prisvoqvane, operatorite);
	printf("You're done,please press enter!");

	fclose(fileOut);
}
//prochita fail i go obrabotva i rezultata izvejda na ekrana
void cfpe()
{
	short i = 0;
	int prisvoqvane;
	int operatorite;
	int numChars = 0;
	char inFile[20];
	char *pointerToData;

	printf("Enter the name of the file you want to load: ");
	fgets(inFile, sizeof(inFile), stdin);
	inFile[strcspn(inFile, "\r\n")] = 0;

	while (inFile[i] != '\0')
	{
		i++;
		numChars++;
	}

	pointerToData = FailVString(inFile, numChars);
	prisvoqvane = countPrisvoqvane(pointerToData);
	operatorite = CountOperators(pointerToData);
	printf("Prisvoqvaniqta sa:%d\n", prisvoqvane);
	printf("Operatorite sa:%d\n", operatorite);
}
//chrez while ((ch = getchar()) != EOF) se chete ot ekrana dokato na nov red ne se vuve ctrl+Z.. tova e znak za okazvane na tova che ne iskame da vuvejdame veche
//sled tova obrabotva napisanoto i izvvejda rezultata vuv fail
void cepf()
{
	int prisvoqvane;
	int operatorite;
	char outFile[20];
	char StringZapazvasht[200];
	FILE *fileOut;
	printf("Enter something on the keyboard:");
	printf("Enter something on the keyboard:");
	int ch;
	int i = 0;
	while ((ch = getchar()) != EOF)
	{
		StringZapazvasht[i] = ch;
		i++;
	}
	prisvoqvane = countPrisvoqvane(StringZapazvasht);
	operatorite = CountOperators(StringZapazvasht);
	printf("Enter the name of the file in which to save the result: ");
	fgets(outFile, sizeof(outFile), stdin);
	outFile[strcspn(outFile, "\r\n")] = 0;
	fileOut = fopen(outFile, "w");
	fprintf(fileOut, "Prisvoqvaniqta sa:%d\n", prisvoqvane);
	fprintf(fileOut, "Operatorite sa:%d\n", operatorite);
	printf("You are done,please press enter!\n");

	fclose(fileOut);
}
//chrez while ((ch = getchar()) != EOF) se chete ot ekrana dokato na nov red ne se vuve ctrl+Z.. tova e znak za okazvane na tova che ne iskame da vuvejdame veche
//sled tova obrabotva napisanoto i izvvejda rezultata na ekrana
void cepe()
{
	int prisvoqvane;
	int operatorite;
	char StringZapazvasht[2000];

	printf("Enter something on the keyboard:");
	int ch;
	int i = 0;
	while ((ch = getchar()) != EOF)
	{
		StringZapazvasht[i] = ch;
		i++;
	}
	prisvoqvane = countPrisvoqvane(StringZapazvasht);
	operatorite = CountOperators(StringZapazvasht);
	printf("\nPrisvoqvaniqta sa:%d\n", prisvoqvane);
	printf("\nOperatorite sa:%d\n", operatorite);

}
//funkciq koqto namira broqt na operatorite za logichesko i v programta
int countPrisvoqvane(char StringZapazvasht[5000])
{
	int counter = 0;
	int i = 0;
	while (i < dostignal || StringZapazvasht[i] != '\0')
	{
		if (StringZapazvasht[i] != '+' && StringZapazvasht[i] != '-'  && StringZapazvasht[i] != '*'  && StringZapazvasht[i] != '/'  &&
      StringZapazvasht[i] != '>'  &&  StringZapazvasht[i] != '<'    && StringZapazvasht[i] != '%'   && StringZapazvasht[i] != '!'  && StringZapazvasht[i] != '=' && StringZapazvasht[i + 1]  == '=')
		{
			counter++;
		}
		i++;
	}
	return counter;
}
//funkciq koqto namira broqt na operatorite za razklonenie v programta
int CountOperators(char StringZapazvasht[5000])
{
	int finalResult = 0;
	int i = 0;
	int flagDo = 0;
	int flag = 0;
	int whileCounter =0;
	int doWhileCounter =0;
	int ifCounter = 0;
	int ifElseCounter = 0;
	int switchCounter = 0;
	int forCounter = 0;
    int countinueCounter = 0;
    int breakCounter = 0;
	while (i < dostignal || StringZapazvasht[i] != '\0')
	{
	    if (StringZapazvasht[i]=='*')
	    {
	        do{
	            i++;
             }while(StringZapazvasht[i] != '*');

        }

	    if (StringZapazvasht[i]=='\"')
	    {
	        do{
                i++;
	        }while(StringZapazvasht[i] != '\"');
	    }


	    if (StringZapazvasht[i]=='/' && StringZapazvasht[i + 1]=='/')
	    {
	        do{
                i++;
	        }while(StringZapazvasht[i] != '\n');
	    }

	     if(StringZapazvasht[i - 1] == ' ' || StringZapazvasht[i - 1] == '\n')
        {


	    if (StringZapazvasht[i]== 'f' && StringZapazvasht[i + 1] == 'o' && StringZapazvasht[i+2]== 'r')
        {
            forCounter++;
        }

	    if (StringZapazvasht[i] =='w' && StringZapazvasht[i + 1] == 'h' && StringZapazvasht[i + 2] == 'i' && StringZapazvasht[i + 3] == 'l' && StringZapazvasht[i + 4] == 'e')
	    {
	        if(flagDo==0)
        {
            whileCounter++;
	    }
            else
        {
           flagDo=0;
        }
	    }

	    if (StringZapazvasht[i] == 'd' && StringZapazvasht[i + 1] == 'o')
        {
            flagDo=1;
            doWhileCounter++;
        }

		if (StringZapazvasht[i] == 'i'&& StringZapazvasht[i + 1] == 'f')
		{
			flag = 1;
			ifCounter++;
		}
		if (flag == 1 && StringZapazvasht[i + 1] == 'e'&&StringZapazvasht[i + 2] == 'l'&&StringZapazvasht[i + 3] == 's'&&StringZapazvasht[i + 4] == 'e')
		{
			ifCounter--;
			ifElseCounter++;
			flag = 0;
		}
        if (StringZapazvasht[i]=='s' && StringZapazvasht[i+1]=='w' && StringZapazvasht[i+2]=='i' && StringZapazvasht[i+3]=='t' && StringZapazvasht[i+4]=='c' && StringZapazvasht[i+5]=='h')
        {
            switchCounter++;
        }

        if(StringZapazvasht[i] =='c' && StringZapazvasht[i + 1] =='o' && StringZapazvasht[i + 2] =='n' && StringZapazvasht[i + 3] =='t' && StringZapazvasht[i + 4] =='i' && StringZapazvasht[i + 5] =='n' && StringZapazvasht[i + 6] =='u' && StringZapazvasht[i + 7] =='e')
        {
            countinueCounter++;
        }

        if (StringZapazvasht[i]=='b' && StringZapazvasht[i+1]=='r' && StringZapazvasht[i+2]=='e' && StringZapazvasht[i+3]=='a' && StringZapazvasht[i+4]=='k')
        {
            breakCounter++;
        }
        }


		i++;
	}
	finalResult = ifCounter + ifElseCounter + switchCounter + doWhileCounter + whileCounter + forCounter + countinueCounter + breakCounter;
	return finalResult;

}
//pokazva menuto
void menu()
{

	printf("Izberete edna ot opciite kato vuvedete suotvetnata cifra\n ");
    printf("1. Chetene ot fail i zapis vuv fail\n ");
	printf("2. Chetene ot fail i izvejdane na rezultata na ekrana\n ");
    printf("3. Chetene na programata ot klaviaturata i izvejdane vuv fail\n ");
    printf("4. Chetene na programata ot klaviaturata i izvejdane na ekrana\n ");
	printf("5. Exit\n");

}

//funkciq koqto chisti erana vseki put kogato bude izvikana

void clearInput() { while (getchar() != '\n'); }
