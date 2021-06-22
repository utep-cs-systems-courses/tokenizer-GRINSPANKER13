#include <stdio.h>

int main()
{
  char input[100];
  while(1)
    {
      printf("$ ");
      fgets(input, 100, stdin);
      if (input[0] == 'q' & input[1] == 'u' & input[2] == 'i' & input[3] == 't')
	goto done;
      printf("%s", input);
    }
 done:
  return 0;
}
