/* 
    Noah R.
    This code creates a text file that looks at another file and stores each paragraph number and how many words are in that paragraph.  
*/
#include <stdio.h>

int main()
{
  FILE *fp;
  FILE *counter;
  int c, i=0, j, k, store[16];

  fp = fopen("lorum.txt", "r");
  counter = fopen("count.txt", "w");
  
  for(j = 0; j < 16; j++)
  {
    store[j]=0;
  }
  
  while ((c = fgetc(fp)) != EOF)
  {
      if (c != '\n')
      {
        store[i]++;
      }
      else
      {
        i++;
      }  
  }

  for(k = 1; k < 17; k++)
  {
    fprintf(counter, "%d: %d\n", k, store[k-1]);
  }
  
  fclose(fp);
  fclose(counter);

  return 0;
}
