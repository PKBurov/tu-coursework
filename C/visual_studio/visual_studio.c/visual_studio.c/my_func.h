
#include <stdio.h>

short count_symbols(FILE *fp_in, FILE *fp_out);
FILE *get_name_file(char *name_file, char *mode, char *text);
void print_text_file();
short count_chosen_symbol(FILE *fp_in, char *ch);
void change_symbol(FILE *fp_in, FILE *fp_out);
int max_min_numbers(FILE *fp_in);
void write_numbers_of_interval(FILE *fp_in, FILE *fp_out);
float average_of_numbers(FILE *fp_in);
void change_negative_numbers(FILE *fp_in, FILE *fp_out);
int  sum_average(int S, int num, int *overflow);
