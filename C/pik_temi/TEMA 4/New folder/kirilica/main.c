
#include <stdio.h>
#include <conio.h>
#include <memory.h>
#include <windows.h>

#include "cyrilic_kbd.h"

int main(void)
{


  unsigned int i;
  unsigned char line[256];

	i=GetConsoleOutputCP();
  i=SetConsoleCP(1251);
  i=SetConsoleOutputCP(1251);
	i=GetConsoleOutputCP();
//---------------------
  for (i=32;i<256;i++)
  {
    printf("\nsimbol ->%c - 0x%02X - %03d",i,i,i);
  }
  printf("\n\ntype text:\n");
  gets(line);
  printf("\n\nread text->%s\n",line);
//  cyr_lat_toupperCP1251(line);
	cyr_lat_tolowerCP1251(line);
  printf("\nlower text text->%s\n",line);
  cyr_lat_toupperCP1251(line);
	printf("\n upper text text->%s\n",line);
  return 0;
}

