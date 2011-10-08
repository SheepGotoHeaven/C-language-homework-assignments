#include <stdio.h>
#define SHIFT 6
//sets SHIFT as easily adjustible parameter

int main()
{
  int i=1;
  char ch=0;

  printf("Enter Plain text: ");
  //prompts user to enter the text they wish to encode

  while(ch != '\n')
    //loop continues until end of line is read
    {
      if(i%6==0)
	{
	  printf(" ");
	  i=i+1;
	}
      //puts a space if i is divisible by 6, and then increments i so that ist is no longer divisible by 6
      //so after first 5 chars are read, a space is put and i goes to 7, then 5 more chars are read, and i=12
//and the process repeats
      else
	//whenever i%6!=0
	{
	  scanf("%c",&ch);
	  //next character of user input line is read
	  if(ch>='A' && ch<='Z')
	    //checks if character falls between A and Z alphabetically
	    {
	      if(ch+SHIFT>'Z')
		ch=ch-26+SHIFT;
	      else
		ch=ch+SHIFT;
	      //shifts the letter the appropriate number of letters over
	      //if the ltter would be pushed "past the end" of the alphabet, 26 is subtracted
	      //so that it "loops back around" to A, and then goes on.
	      printf("%c",ch);
	      i=i+1;
	      //prints the new "shifted" character and increments i.
	    }
	  else if(ch>='a' && ch<='z')
	    //if ch is not between A and Z, checks for it to be between a and z
	    {
	      if(ch+SHIFT>'z')
		ch=ch-26+SHIFT;
	      else
		ch=ch+SHIFT;
	      //shifts letter appropriately as detailed in above comments
	      printf("%c",ch);
	      i=i+1;
	      //prints new shifted character, and increments i
	    }
	  else;
	  //if the scanned character is not a letter, nothing is done and the loop reiterates
	}
    }
  //two above brackets end the "if(i%6==0)'s else statement tree and the loop.

  printf("\n");
  //moves on to next line so that the new command line isn't on the same line as the output.
  return 0;
}
