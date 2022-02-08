#include "strlib.h"   

int my_strlen(const char *str) 
{
  
  int i=0;

  while(str[i] != '\0')
  {
    i++;
  }
  return i;
}

int my_strcmp(const char *str1,const char *str2)
{ 
  int i=0;
  while((str1[i] != '\0' && str2[i] != '\0') && str1[i] == str2[i])
  {
    i++;
  }
  if(str1[i] == str2[i])
  {
    return 0; 
  }
  else
  {  
    return (str1[i] - str2[i]);
  }
}
