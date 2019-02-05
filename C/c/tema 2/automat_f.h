int words(FILE *);
int sentences(FILE *);
void copy_words(FILE *, FILE *);
void copy_sentences(FILE *, FILE *);
int valid_directory(char *);
int forbidden_symbols(char);
void real_constant(FILE *);
void int_constant(FILE *);
int is_delimiter(char);