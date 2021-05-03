/*
    digita password con offuscamento
    spicoli piersilvio
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main()
{
  int ch;
  char pword[BUFSIZ];
  int i = 0;

  puts ("Enter your password");
  fflush(stdout);

  while ((ch = getch()) != EOF
          && ch != '\n'
          && ch != '\r'
          && i < sizeof(pword) - 1)
  {
    if (ch == '\b' && i > 0)
    {
      printf("\b \b");
      fflush(stdout);
      i--;
      pword[i] = '\0';
    }
    else if (isalnum(ch))
    {
      putchar('*');
      pword[i++] = (char)ch;
    }
  }

  pword[i] = '\0';

  printf ("\nYou entered >%s<", pword);

  return 0;
}
