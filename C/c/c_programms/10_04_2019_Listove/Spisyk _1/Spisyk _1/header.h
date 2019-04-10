typedef struct
{
	char name[30];
	int fn;
}STUDENT;
typedef struct item
{
	STUDENT s;
	struct item *next;
}NODE;