#include "Header.h"

STD *start(STD *head) {
//	struct student *head = NULL;
	struct student *current = NULL;

	FILE *fp;
	int i = 0;
	int flag;
	if ((fp = fopen("student", "rb")) == NULL) {
		printf("Error open file!");
		exit(0);
	}

	while (1) {
		if (fread(&flag, sizeof(int), 1, fp) != 1)
		{
			printf("Error reading1");

			exit(4);
		}
		if (flag == -1)
			break;

		struct student *temp = (struct student*)malloc(sizeof(struct student));

		if (head == NULL)
		{
			head = temp;
			current = head;
			current->next = NULL;
		}
		else
		{
			current->next = temp;
			current = temp;
			current->next = NULL;
		}
		if ((fread(temp->student_first_name, i, 1, fp)) != 1) {
			printf("error");
			exit(19);
		}
		if ((fread(temp->student_sur_name, i, 1, fp)) != 1) {
			printf("error");
			exit(20);
		}
		if ((fread(temp->student_familly_name, i, 1, fp)) != 1) {
			printf("error");
			exit(21);
		}
		if ((fread(&temp->faculty_number, sizeof(int), 1, fp)) != 1) {
			printf("error");
			exit(22);
		}
		if ((fread(&i, sizeof(int), 1, fp)) != 1) {
			printf("error");
			exit(23);
		}
		if ((fread(temp->faculty, i, 1, fp)) != 1) {
			printf("error");
			exit(24);
		}
		if ((fread(&temp->group, sizeof(int), 1, fp) != 1)) {
			printf("error");
			exit(25);
		}
		if ((fread(&i, sizeof(int), 1, fp)) != 1) {
			printf("error");
			exit(26);
		}
		if ((fread(temp->major, i, 1, fp)) != 1) {
			printf("error");
			exit(27);
		}
		if ((fread(&temp->year, sizeof(int), 1, fp) != 1)) {
			printf("error");
			exit(28);
		}
		if ((fread(&i, sizeof(int), 1, fp)) != 1) {
			printf("error");
			exit(29);
		}
	}
	fclose(fp);
	return head;
}
STD	*add(STD *head) //////// за разделение на фамилия;
{
//	struct student *head = NULL;
	struct student *current = NULL;

	struct student *temp;
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	struct student *new_student;
	new_student = (struct student*) malloc(sizeof(struct student));

	printf("Enter the new students first name "); //trqbva nqkak da cheta space'sovete;
	scanf("%s", new_student->student_first_name);

	printf("Enter the new students surname name "); //trqbva nqkak da cheta space'sovete;
	scanf("%s", new_student->student_sur_name);

	printf("Enter the new students last name "); //trqbva nqkak da cheta space'sovete;
	scanf("%s", new_student->student_familly_name);

	printf("Enter the new student faculty number ");
	scanf("%d", new_student->faculty_number);

	printf("Enter the new students faculty ");
	scanf("%s", new_student->faculty);

	printf("Enter the new students group ");
	scanf("%d", &new_student->group);

	printf("Enter the new students major ");
	scanf("%s", &new_student->major);

	printf("Enter the new students year ");
	scanf("%d", &new_student->year);

	new_student->next = NULL;
	temp->next = new_student;
	printf("\nAdd new student : SUCCESSFUL\n\n");

	return head;
}
STD	*del(STD *head)
{
	struct student *current = NULL;

	struct student* prev_item = head;
	struct student* curr_item = head;

	int f = 0;
	int *arr;
	arr = (int*)malloc(8);
	printf("Input students faculty number : \n");
	gets(arr);
	while (curr_item != NULL)
	{
		if ((curr_item->faculty_number == arr) == 0)
		{
			if (curr_item == head)
			{
				head = head->next;
				prev_item = head;
				f = 1;
			}
			else
				prev_item->next = curr_item->next;
			free(curr_item);
			curr_item = prev_item;
		}
		prev_item = curr_item;
		if (f == 0)
			curr_item = curr_item->next;
		f = 0;
	}
	return head;
}
STD ** make_arrey(STD*head, STD**ps)
{
	//struct student *head = NULL;
	struct student *current = NULL;

	STD *crnt; 
	STD **p;
	int number = 0;
	

	for (crnt = head; crnt; crnt = crnt->next)  // преброяване на възлите

	number++; // добавяне на последниявъзел
	number++;

	ps = (STD **)malloc(number * sizeof(STD*)); // създаване на масив от указатели към структури
	if (ps == NULL)
	{
		printf("No memory!\n"); exit(1);
	}
	for (p = ps, crnt = head; crnt; crnt = crnt->next) // прехвърляне на възлите в масива
		*p++ = crnt;
	*p = NULL;
	return ps;

}
void sort_arrey(STD **ph)
{

	/*int ok; STD **p; STD *hlp;
	do
	{
		ok = 1;
		for (p = ph; *(p + 1); p++) 
		{
			if (((*p)->STD) > ((*(p + 1))->prs.n))
			{
				hlp = *p;
				*p = *(p + 1);
				*(p + 1) = hlp;
				ok = 0;
			}
		}
	} while (!ok);*/
}
void search() // фамилно име(проблем)
{
	struct student *head = NULL;
	struct student *current = NULL;

	char *arr;
	int flag = 0;
	arr = (char*)malloc(20);
	printf("Input students Familly name: \n \n");
	gets(arr);		// redovna greshka
	struct student *temp;
	temp = (struct student*)malloc(sizeof(struct student));
	temp = head;
	while (temp != NULL)
	{
		if (!(strcmp(temp->student_familly_name, arr))) {
			printf("  Student First name: %s Student Surname: %s Student Familly name: %s	Faculty Number: %d	Fculty: %s  Group: %d  Major: %s Year : %d  \n \n", temp->student_first_name, temp->student_sur_name, temp->student_familly_name, temp->faculty_number, temp->faculty, temp->group, temp->major, temp->year);
			flag = 1;
		}
		temp = temp->next;
	}
	if (flag == 0) printf("Can't find student - %s \n \n", arr);
}
void list_by_alpha()  // po azbuchen red na imenata
{
	struct student *head = NULL;
	struct student *current = NULL;

	struct student*temp;
	temp = head;
	int arr;
	arr = (int*)malloc(2);
	printf("Input students group : \n");
	gets(arr);

	while (temp != NULL) {

		if (temp->group == arr)
			printf("  Student First name: %s Student Surname: %s Student Familly name: %s	Faculty Number: %d	Fculty: %s  Group: %d  Major: %s Year : %d  \n \n", temp->student_first_name, temp->student_sur_name, temp->student_familly_name, temp->faculty_number, temp->faculty, temp->group, temp->major, temp->year);
		temp = temp->next;
	}
}
void show_all()
{
	struct student *head = NULL;
	struct student *current = NULL;

	struct student* temp;
	for (temp = head; temp != NULL; temp = temp->next)
	{
		printf("  Student First name: %s Student Surname: %s Student Familly name: %s	Faculty Number: %d	Fculty: %s  Group: %d  Major: %s Year : %d  \n \n",temp->student_first_name, temp->student_sur_name, temp->student_familly_name, temp->faculty_number, temp->faculty, temp->group, temp->major, temp->year);
	}
}
void end()
{
	struct student *head = NULL;
	struct student *current = NULL;

	FILE *fp;
	int flag = -1;
	if ((fp = fopen("student", "wb")) == NULL) {
		printf("Error open file!");
		exit(0);
	}
	struct student*temp;
	temp = head;
	int j;
	int p;
	int z;
	int x;
	int i;
	int k;
	while (temp != NULL) {
		j = strlen(temp->faculty_number); j++;
		p = strlen(temp->student_first_name); p++;
		z = strlen(temp->student_sur_name); z++;
		x = strlen(temp->student_familly_name); x++;
		i = strlen(temp->faculty); i++;
		k = strlen(temp->major); k++;
		
		if (fwrite(&j, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->faculty_number, j, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		////////////////////
		if (fwrite(&p, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->student_first_name, p, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		//////////////////////
		if (fwrite(&z, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->student_first_name, z, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		///////////////////////////
		if (fwrite(&x, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->student_first_name, x, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		///////////////////////
		if (fwrite(&i, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->faculty, i, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}////////////////////////
		if (fwrite(&temp->group, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(&k, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}//////////////////////////
		if (fwrite(temp->major, k, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(&temp->year, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}//////////////////////////
		temp = temp->next;
	}
	if (fwrite(&flag, sizeof(int), 1, fp) != 1) {
		printf("Error");
		exit(1);
	}
	fclose(fp);
}