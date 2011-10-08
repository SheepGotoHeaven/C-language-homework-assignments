#include <stdio.h>
#include <stdlib.h>

int *create_array(int n);
void release_array(int *a);
int *insert(int *a, int n, int new_element);


int main()
{
  int i=1, j;
  int *a=create_array(1);

  a = insert(a,i,5);
  i++;
  a = insert(a,i,2);
  i++;
  a = insert(a,i,1);
  i++;
  a = insert(a,i,7);
  i++;
  a = insert(a,i,4);
  i++;
  a = insert(a,i,3);

  for(j=0; j<i; j++)
    printf("%d\n",a[j]);  

  release_array(a);

  return 0;
}  


int *create_array(int n)
{
  int *ptr;

  ptr = calloc(n,sizeof(int));

  return ptr;
}


void release_array(int *a)
{
free(a);
}

int *insert(int *a, int n, int new_element)
{
  int *first;
  int i=0,j=0;

  first = a;

  a = realloc(a,(n)*sizeof(int));

  for(i=0; i<n-1; i++)
    {
      if(a[i] == new_element)
        return first;
    }


  i = 0;

  while(i<n-1 && a[i] < new_element)
    i++;

  for(j=n-1; j>i; j--)
    a[j] = a[j-1];
 
  a[j] = new_element;

  return first;
}
