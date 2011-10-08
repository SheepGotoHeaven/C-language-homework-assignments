#include <stdio.h>

void selection_sort(int n, int array[]);
//declares function for later use

int main()
{
  int i, array_size;


  printf("Enter number of elements: ");
  scanf("%d",&array_size);

  int a[array_size];

  printf("Enter array: ");

  for(i=0; i<array_size; i++)
    scanf("%d",&a[i]);
  //reads a list of numbers from user and puts them in an array

  selection_sort(array_size, a);
  //calls selection sort () to sort array

  printf("Sorted array: ");

  for(i=0; i<array_size; i++)
    printf("%d ",a[i]);
  printf("\n");
  //prints sorted array
  return 0;
}

void selection_sort(int n, int array[])
{
  int big, i;

  if(n==0)
    return;
  //if the first parameter is 0, then the size of the array is 0 and the 
  //function terminates    

   big=array[0];
   //initializes 'big' value to the first array entry

   for(i=1; i<n; i++)
     {
       if(array[i]>big)
	 big=array[i];
     }
   //finds largest number in array and makes big = largest value

   for(i=0; i<n; i++)
     {
       if(array[i]==big)
       {
	 array[i]=array[n-1];
	 array[n-1]=big;
	 break;
       }
     }
   //swaps position of largest value and last value in array
   selection_sort(n-1, array);
   //function calls self recursively to sort the remaining
   //numbers of the array.  By decrementing n by 1, we ensure that the largest
   //value at the end will go untouched, while the remaining
   // values will be sorted.  When n reaches 0, the function terminates.
}
