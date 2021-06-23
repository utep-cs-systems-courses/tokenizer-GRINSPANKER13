#include "tokenizer.h"

#define START 1
#define END 0

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  return (c == '\t' || c == ' ');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
  return (c != '\t' && c != ' ');
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str. Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str) {
  while (*str)
    {
      if (non_space_char(*str)) {
	return str;
      }
      else if (space_char(*str) && non_space_char(*(str+1))) {
	  return str+1;
      }
      str++;
    }
  return 0;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word) {
  while (*str)
    {
      if (non_space_char(*str) && (space_char(*(str+1)) || *(str+1) == 0)) {
	  return str+1;
      }
      str++;
    }
  return 0;
}

/* Counts the number of words in the string argument. */
int count_words(char *str) {
  int state = END;
  int word = 0;
  while(*str)
    {
      if(space_char(*str)) {
	state = END;
      }
      else if (state == END) {
	state = START;
	word++;
      }
      str++;
    }
  return word;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  if (len > 0)
    {
      char *p = (char *)malloc(len+1);
      strcpy(p,inStr);
      *(p+len) = 0;
      return p;
    }
  return 0;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {
  int wordCount = count_words(str);
  char *p = str;
  if (wordCount > 0)
    {
      char **token = malloc((wordCount+1)*sizeof(char *));
      for (int i = 0; i < wordCount; i++) {
	*(token+i) = copy_str(p, word_terminator(p) - p);
	p = word_start(word_terminator(p));
      }
      *(token+wordCount) = 0;
      return token;
    }
  return 0;
}


/* Prints all tokens. */
void print_tokens(char **tokens) {
  for (int i = 0; i < sizeof(tokens); i++) {
    printf("%d: %s\n", i, &(**(tokens+i)));
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {

}
