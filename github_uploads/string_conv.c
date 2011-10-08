#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LEN 10

int main()
{
  int i, number=0, length;
  char num_string[MAX_LEN+1] = {0};

  printf("Enter positive integer: ");
  scanf("%s", num_string);

  for(length=0; num_string[length] != '\0'; length++);

  for(i=0; i<length; i++)
    number += pow(10,(double) i) * (num_string[length-i-1]-48);

  printf("Number is %d\n", number);

  return 0;
}
