#include <stdio.h>
#define N 100


int main(void)
{
  int a[N+1], i, j;

  for (i=0; i<=N; i++)
    a[i]=1;
  //fills array of size N+1 with ones.  For this program, 
  //all array elements are initially assumed to be prime.  
  //All elements of value 1 are considered prime, while 
  //elements with value 0 are considered composite.

  for(j=2; j<=N; j++)
    {
      if (a[j]==1)
	{
	  for (i=j+1; i<=N; i++)
	    {
	      if (i % j == 0)
		a[i] = 0;
	    }
	}
    }
  //for each element of the array, if the element has value 1,
  //check if any of the following elements are divisible by the current
  //element.  If so, then they are not prime and their value becomes 0.


  printf("All primes between 2 and %d are: ", N);

  for (i=2; i<=N; i++)
    {
    if (a[i]==1)
      printf("%d ",i);
    }
  printf("\n");
  //prints values of all array subscripts whose elements are 1 (and
  //therefore prime)
  
return 0;
}
