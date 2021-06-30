#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *list = malloc(sizeof(List));
  list->root = 0;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  Item *item = malloc(sizeof(Item));
  item->str = copy_str(str, strlen(str));
  if (list->root == 0)
    {
      // List is empty
      item->id = 1;
      item->next = 0;
      list->root = item;
    } else {
    // List isn't empty
    Item *p = list->root;
    while(p->next != 0)
      {
	p = p->next;
      }
    item->id = p->id + 1;
    p->next = item;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  // Invalid id or empty list.
  if (id < 1 || list->root == 0)
    return 0;

  Item *item = list->root;
  while(item->id != id)
  {
    // Reached the end of the list.
    if(item->next == 0)
      return 0;

    item = item->next;
  }
  // Found the id.
  return item->str;
}

/* Print the entire contents of the list. */
void print_history(List *list) {
  if (list->root == 0)
    {
      printf("There is no history to display.\n");
    }
  else
    {
      Item *item = list->root;
      while (item != 0)
	{
	  printf("%d: %s\n", item->id, item->str);
	  item = item->next;
	}
    }
}

/* Free the items. */
void free_items(Item *item) {
  if (item != 0)
    {
      if (item->next != 0)
	free_items(item->next);
      free(item->str);
      free(item);
    }
}

/* Free the history list and the strings it references. */
void free_history(List *list) {
  if (list->root != 0)
    {
      free_items(list->root);
      free(list);
    }
}
