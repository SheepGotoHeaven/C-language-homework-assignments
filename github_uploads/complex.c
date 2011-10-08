#include <stdio.h>
int main()
{
  float a,b,c,d,real,complex;
  int choice=1,skipprint=0;
  //declares variables for complex # parts, menu selection, and variable that tells
  //the program not to print the result if division by 0 is attempted.

  printf("\nComplex Number Calculator\n\n");

  while(choice != 0)
    {
      printf("Available options:\n0 - exit\n1 - add\n2 - subtract\n3 - multiply\n4 - divide\n\n");
      //prints menu

	printf("Your choice: ");
	scanf("%d",&choice);
	//takes user menu choice

	if(choice != 0)
	{
      printf("\nEnter number 1: ");
      scanf("%f+%fi",&a,&b);
      printf("Enter number 2: ");
      scanf("%f+%fi",&c,&d);
      //takes two complex numbers from user

      if(choice==1)
      {
	real = a+c;
	complex = b+d;
      }
      else if(choice==2)
      {
	real=a-c;
	complex=b-d;
      }

      else if(choice==3)
	{
	real=a*c-b*d;
      complex=a*d+b*c;
	}

      else if(choice==4)
	{if(c!=0 || d!=0)
	    {
           real=(b*d+a*c)/(c*c+d*d);
	  complex=(c*b-a*d)/(c*c+d*d);
	    }
	  //adds, subtracts, multiplies, or divides the numbers based on value of
	  // CHOICE, and if division by 0 is not attempted

	  else
	    {
      printf("\nError, division by zero is illegal\n\n");
      skipprint=1;
	    }
	  //if division by 0 is attempted, prints error message and sets skipprint = 1 so that
	  //result (which involves division by 0) will not be printed
	}
	}
	else
	  break;
	//breaks loop if choice == 0
if(choice != 0 && skipprint==0)
	   
 printf("\nResult: %f+%fi\n\n",real,complex);
 skipprint=0;
 //prints result if skipprint != 0, and then sets skipprint to 0 for next iteration
   }
  return 0;
}
