#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int main()
{
  char input[100];
  while(1)
    {
      printf("$ ");
      fgets(input, 100, stdin);
      if (input[0] == 'q' & input[1] == 'u' & input[2] == 'i' & input[3] == 't')
	goto done;
      int inputSize = strlen(input);
      input[inputSize-1] = '\0';
      char **token = tokenize(input);
      print_tokens(token);
      free_tokens(token);
    }
 done:
  return 0;
}
