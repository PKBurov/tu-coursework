#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cyr_lat_toupperCP1251(unsigned char *line)
{
   int i, len;
   len=strlen(line);
   for(i=0; i<len; i++)
   {
     if(line[i]>=0xE0)
       line[i]=line[i]-0x20;
     else
       line[i]=(unsigned char)toupper(line[i]);
   }
}
void cyr_lat_tolowerCP1251(unsigned char *line)
{
   int i, len;
   len=strlen(line);
   for(i=0; i<len; i++)
   {
     if(line[i]>=0xC0 && line[i]<=0xDF)
       line[i]=line[i]+0x20;
     else
       line[i]=(unsigned char)tolower(line[i]);
   }
}
