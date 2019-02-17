// ------------ file my_func.c ----------------------------
#define _CRT_SECURE_NO_WARNIGNS
#include <string.h>
#include "my_functions_automat.h";

int delimiters_word[] = { '"', '\'', ' ', ',', '.', '?', '!', ':', ';', '/', '\\', '*',
'<', '>', '(', ')', '{', '}', '[', ']', '\n', '\t', EOF, 0 };

int delimiters_sent[] = { '.','?','!', EOF, 0 };


int is_delimiter(int *delimiters, int c)
{
	int i = 0;
	while (delimiters[i])
	{
		if (c == delimiters[i++])
			return 1; //--- символът с е разделител ---
	}
	return 0;
}

//--------------------------------------------------

FILE *get_name_file(char *name_file, char *mode, char *text)
{
	FILE *fp;
	int err;

	do
	{
		printf("\nВъведете име на файла %s:", text);
		err = scanf("%s", name_file);
	} while (err != 1);

	if ((fp = fopen(name_file, mode)) == NULL)
	{
		printf("\nФайлът <%s> Не може да се отвори - error No % d !!!\n", name_file, errno);
		printf("ГРЕШКА No %d %s", errno, strerror(errno));
		system("pause");
	}
	else
	{
		printf("\nФайлът <%s> е отворен успешно за обработка !\n\n", name_file);
		system("pause");
	}
	return fp;
}

//-----------------------------------------------------------
s_word compute_word(int c,      //--- текущ символ, които се анализира ---
	char *word,   //--- символен масив за отделяне на дума
	s_word status //--- текущ статус на автоматната функция
)
{
	static int ind = 0;
	char ch = c;

	if (status == end_word)
	{
		status = none;
		ind = 0;
	}
	switch (status)
	{
	case none:
		if (!is_delimiter(delimiters_word, ch))
		{
			status = in_word;
			word[ind++] = c;
		}
		break;

	case in_word:
		if (is_delimiter(delimiters_word, ch))
		{
			status = end_word;
			word[ind] = 0;
		}
		else
		{
			word[ind++] = c;
		}
	}
	return status;
}
//-----------------------------------------------------------

int words(FILE *fp_out, FILE *fp_in)
{
	rewind(fp_in);
	int c, br_word = 0;
	s_word status = none;
	char word[256];
	
	do
	{
		c = fgetc(fp_in);
		status = compute_word(c, word, status);
		if (status == end_word)
		{
			br_word++;
			fprintf(fp_out,"\n word -> %s", word);
		}
	} while (c != EOF);
	return br_word;
}


s_sent compute_sent(int c,      //--- текущ символ, които се анализира ---
	char *sent,   //--- символен масив за отделяне на дума
	s_sent status //--- текущ статус на автоматната функция
)
{
	static int ind = 0;
	char ch = c;

	if (status == end_sent)
	{
		status = none1;
		ind = 0;
	}
	switch (status)
	{
	case none1:
		if (!is_delimiter(delimiters_sent, ch))
		{
			status = in_sent;
			sent[ind++] = c;
		}
		break;

	case in_sent:
		if (is_delimiter(delimiters_sent, ch))
		{
			status = end_sent;
			sent[ind] = 0;
		}
		else
		{
			sent[ind++] = c;
		}
	}
	return status;
}

int sents(FILE *fp_out,FILE *fp_in)
{
	int c, br_sent = 0;
	s_sent status = none;
	char sent[256];
	rewind(fp_in);
	do
	{
		c = fgetc(fp_in);
		status = compute_sent(c, sent, status);
		if (status == end_sent)
		{
			br_sent++;
			printf("\n sent -> %s", sent);
		}
	} while (c != EOF);
	return br_sent;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

s_conts compute_conts(int c,      //--- текущ символ, които се анализира ---
	char *word,   //--- символен масив за отделяне на дума
	s_conts status //--- текущ статус на автоматната функция
)
{
	static int ind = 0;
	char ch = c;

	if (status == end_conts)
	{
		status = none2;
		ind = 0;
	}
	switch (status)
	{
	case none2:
		if (!is_delimiter(delimiters_sent, ch))
		{
			status = in_conts;
			word[ind++] = c;
		}
		break;

	case in_conts:
		if (is_delimiter(delimiters_sent, ch))
		{
			status = in_conts;
			word[ind] = 0;
		}
		else
		{
			word[ind++] = c;
		}
		if (is_delimiter > 0 || is_delimiter < 9)
		{
			status = in_digit;
			word[ind++] = c;
		}
		else
		{
			word[ind++] = c;
		}
		if (is_delimiter == '+' || is_delimiter == '-')
		{
			status = in_sign;
			word[ind] = 0;
		}
		else
		{
			word[ind++] = c;
		}
	case in_sign:
		if (in_sign < 0 || in_sign > 9)
		{
			status == in_digit;
			word[ind++] = c;
		}
		else if (in_sign == is_delimiter)
		{
			status == is_delimiter;
		}
		else
		{
			status == none;
			word[ind++] = c;
		}

	}
	return status;
}

int conts(FILE *fp_out, FILE *fp_in)
{
	int c, br_con_st = 0;
	s_conts status = none;
	char conts[256];
	rewind(fp_in);
	do
	{
		c = fgetc(fp_in);
		status = compute_sent(c, conts, status);
		if (status == end_conts)
		{
			br_con_st++;
			printf(fp_out,"\n sent -> %s", conts);
		}
	} while (c != EOF);
	return br_con_st;
} //tova e