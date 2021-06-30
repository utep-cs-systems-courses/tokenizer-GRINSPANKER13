#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char input[100];
  char **token;
  List *list = init_history();
  while(1)
    {
      printf("Enter a string, or {!# for specific history, & for all history, or quit}.\n");
      printf("$ ");
      fgets(input, 100, stdin);
      if (input[0] == 'q' & input[1] == 'u' & input[2] == 'i' & input[3] == 't') {
	free_history(list);
	free_tokens(token);
	break;
      } else if (input[0] == '!') {
	input[0] = ' ';
	int id = atoi(input);
	char *str = get_history(list, id);
	printf("%d: %s\n", id, str);
      } else if (input[0] == '&') {
	print_history(list);
      } else {
	int inputSize = strlen(input);
	input[inputSize-1] = '\0';
	token = tokenize(input);
	print_tokens(token);
	add_history(list, input);
      }
    }
  return 0;
}
