#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/* prints a line of 10 bytes (max) in hex with a space between each byte */
void print_bytes_hex(unsigned char *b, unsigned int nbytes)
{
  int i = 0;
  for(i =0; i < nbytes; i++)
  {
    printf("%02x ", b[i]);
  }
  printf(" ");
}

/* prints a line of 10 bytes (max) in as characters.
 * non-printable bytes are printed as the period character. */
void print_bytes_char(unsigned char *b, unsigned int nbytes)
{
  int i = 0;
  for(i =0; i < nbytes; i++)
  {
    if(isprint(b[i]))
    {
      printf("%c", b[i]);
    }
    else
    {
      printf(".");
    }
  }
  printf("\n");
}

int main()
{
  FILE *fp;
  size_t ret;
  size_t ret_char;
  int i, j=0;
  unsigned char temp[10];
  unsigned char temp_char[10];

  fp = fopen("ascii_chars.txt", "rb");

  printf("Offset              Bytes              Characters\n");
  printf("------  -----------------------------  ----------\n");

  while((ret = fread(temp, sizeof(*temp), 10, fp)))
  {
    printf("  %4d  ", j*10);
    print_bytes_hex(temp, ret);
    if(j == 12) printf("      ");
    print_bytes_char(temp, ret);
    j++;
  }

  return 0;
}
