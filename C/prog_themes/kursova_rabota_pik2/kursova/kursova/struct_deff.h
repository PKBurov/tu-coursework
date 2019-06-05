#pragma once
typedef struct student {

	char student_first_name[20];
	char student_sur_name[20];
	char student_familly_name[20];

	int faculty_number[8];
	char faculty[20];
	char major[20];	
	int group;	
	int year; 

	struct student*next;
}STD;


