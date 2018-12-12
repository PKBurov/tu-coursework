#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define DELTA 10

FILE *get_name_file(char *name_file, char *mode, char *text);
void print_text_file();
void interval(int *, int*);
void average(int *, int*);
void sort(int ptr[] , int*);
int	 *include(int digit, int* ptr, int *sizeAd, int* num);