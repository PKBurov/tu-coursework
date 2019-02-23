
#include <stdio.h>

typedef enum sta_word { none, in_word, end_word } s_word;
typedef enum sta_sent { none1, in_sent, end_sent } s_sent;
typedef enum sta_conts { none2, in_conts, end_conts, in_sign, in_digit, in_long } s_conts;

FILE *get_name_file(char *name_file, char *mode, char *text);

s_word compute_word(int c, char *word, s_word status);
int words(FILE *fp_out, FILE *fp_in);
s_sent compute_sent(int c, char *sent, s_sent status);
int sents(FILE *fp_out, FILE *fp_in);
s_conts compute_conts(int c, char *conts, s_conts status);
int conts(FILE *fp_out, FILE *fp_in);
