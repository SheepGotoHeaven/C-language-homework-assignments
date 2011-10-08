#include <stdio.h>
#include <stdlib.h>

struct node
{
  int value;
  struct node *next;
};


struct node *insert(struct node *first, int num);


int main()
{

  int i;

  struct node *first = NULL;

  first = insert(first, 5);

  first = insert(first, 2);

  first = insert(first, 1);

  while(first->next != NULL)
    {
      printf("%d\n", first->value);
      first=first->next;
    }
  if(first != NULL)
  printf("%d\n", first->value);

  return 0;
}


struct node *insert(struct node *first, int num)
{

  struct node *new_node = malloc(sizeof(struct node));
  struct node *cur;
  struct node *prev = malloc(sizeof(struct node));

  new_node->value = num;

  cur = first;

  if(first != NULL)
    {
      while(num > cur->value && cur != NULL)
      {
        prev = cur;
        cur = cur->next;
      }

  new_node->next = cur;
  prev->next = new_node;

  if(new_node->value <= first->value)
    first = new_node;
    }

  else
    {
      first = new_node;
      new_node->next = NULL;
    }

  return first;
}
