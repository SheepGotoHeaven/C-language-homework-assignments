#include <stdio.h>
#define N 10

void compute_union(int max_size, int set1[],int set2[], int set_union[]);

void compute_intersection(int max_size, int set1[], int set2[], int set_intersection[]);

int in(int max_size, int set[], int element);
//declares functions to be called later

int main (void)
{
  int size_a, size_b, i, num, a[N+1]={0};
  int uni[N+1], inter[N+1], b[N+1]={0};
  //declares variables and arrays.  all arrays begin full of 0's

  printf("Enter number of elements in set A: ");
  scanf("%d",&size_a);
  printf("Enter set A: ");

  for (i=0; i<size_a; i++)
    {
    scanf("%d",&num);
    a[num]=1;
    }
  //reads size and elements of first set from user
  //creates array with elements indexed from 0 to 10. If the set
  //contains a number, then that number's coresponding element
  //is set equal to 1.  otherwise it remains 0.

  printf("Enter number of elements in set B: ");
  scanf("%d",&size_b);
  printf("Enter set B: ");

  for (i=0; i<size_b; i++)
    {
      scanf("%d",&num);
	b[num]=1;
    }

  //reads size and elements of second set from user and creates array 
  //telling which numbers are in the set

  compute_union(N, a, b, uni);
  compute_intersection(N, a, b, inter);
  //computes union and intersection of the two sets by calling
  //functions

  printf("Union: ");

  for(i=0; i<=N; i++)
    {
      if(uni[i]==1)
	printf("%d ",i);
    }
  printf("\n");
  //prints union of the 2 sets

   printf("Intersection: ");

   for(i=0; i<=N; i++)
     {
       if(inter[i]==1)
         printf("%d ",i);
     }

   printf("\n");
   //prints intersection of the 2 sets
   return 0;
}



int in(int max_size, int set[], int element)
{
  if (set[element]==1)
    return 1;
  else
    return 0;
}
//tests whether the given element is in the given set.  If so, 
//returns 1 for true, or else returns 0 for false.

void compute_union(int max_size, int set1[], int set2[], int set_union[])
{
  int i;
  for (i=0; i<=max_size; i++)
    { if (in(N,set1,i) || in(N,set2,i))
      set_union[i]=1;
      else
	set_union[i]=0;
    }
}
//calls in() to check if each value from 0 to 10 is in set 1 or set 2.  if
//the value is in either set, it is also in the array set_union.

void compute_intersection(int max_size, int set1[], int set2[], int set_intersection[])
{
  int i;

  for (i=0; i<=max_size; i++)
    {
      if (in(N, set1, i) && in(N, set2, i))
	  set_intersection[i]=1;
	  else set_intersection[i]=0;
    }

}
//Uses in() to check for membership of numbers in sets 1 & 2.  if
//a number is common the both sets, it is places in the array set_intersection.
