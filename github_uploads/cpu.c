//Simulates the actions of a CPU unit in a computer. Bits are stored in a "memory" array as strings.  The bit strings are loaded into the 
//instruction register in sequence, and then commands are executed based on the register's content
//There is also an accumulator (for keeping track of totals)

#include <stdio.h>
#include <string.h>
#define MEM_WIDTH 8
#define MEM_SIZE 32
#define OPCODE_SIZE 3
//macros including stdio and string libraries, as well as defining memory size
//of 32 addresses, 8 bits per address, and the OPCode size of 3.

int pc = 0, halt=0;
char ir[MEM_WIDTH+1];
char ac[MEM_WIDTH+1];
char memory[MEM_SIZE][MEM_WIDTH+1];
//declares global (external) variables for program counter,
// instruction register, accumulator, memory, and halt,
//which is used as a boolean variable.

void set_memory();
void read_memory();
void print_memory();
void dec2bin(int dec, char *bin);
int bin2dec(char *bin);
void execute();
//declares functions to be defined later.

int main(int argc, char *argv[])
{
  int i;

  if(argc==1)
    {
    printf("Argument required.  To use default memory, enter '0', to set\n your own memory, enter any other argument\n");
    return 0;
    }
  //if no argument is given in the command line, program prints error 
  //message and terminates

      if(strcmp(argv[1],"0") == 0)
    set_memory();
      //if argument given is 0, program calls set_memory() to run using
      //default memory settings

      else if(strcmp(argv[1],"0") != 0)
    read_memory();
      //if some nonzero argument is entered, program calls read_memory,
      //prompting the user to enter starting memory values
      //byte-by-byte

  while(pc<MEM_SIZE)
    {
  strcpy(ir, memory[pc]);
  pc++;
  execute();
  //loads memory next piece of memory into the IR, increments the PC, and 
  //executes the command found in the designated memory space.
  if(halt)
    break;
  //if the command executed in memory is the "halt" command, program stops
  //going through memory. 
    }

  printf("Memory:\n");
  print_memory();
  printf("Accumulator:\n");
  printf("%s\n",ac);
  //prints values in accumulator and memory
  return 0;
}

void set_memory()
{
  int i=16, j=0;

  strcpy(memory[0], "01101011");
  strcpy(memory[1], "10001101");
  strcpy(memory[2], "01001011");
  strcpy(memory[3], "01100001");
  strcpy(memory[4], "10100001");
  strcpy(memory[5], "01000001");
  strcpy(memory[6], "01101100");
  strcpy(memory[7], "11100001");
  strcpy(memory[8], "01001100");
  strcpy(memory[9], "00100000");
  strcpy(memory[10], "00000000");
  strcpy(memory[11], "00000000");
  strcpy(memory[12], "00000011");
  strcpy(memory[13], "00000010");
  strcpy(memory[14], "00000100");
  strcpy(memory[15], "00000101");
  //sets first 16 bytes of memory to specified addresses

  for(i=16; i<MEM_SIZE; i++)
    strcpy(memory[i], "00000000");
  //sets remaining addresses to the "00000000" byte.
}
  //this function sets the "default memory" when the user enters 0 for the
  //program argument



void read_memory()
{
  int i, j;

  for(i=0; i<MEM_SIZE; i++)
    {
      scanf("%s",memory[i]);
      if(strcmp(memory[i],"00000000")==0)
	break;
    }
  for(j=i; j<MEM_SIZE; j++)
    strcpy(memory[j], "00000000");

}
//this function reads the starting memory from the user, byte-by-byte
//until the user enters a "00000000" byte.  At that point, the rest of 
//memory is filled with "00000000" bytes.

void print_memory()
{
  int i;

  for(i=0; i<MEM_SIZE; i++)
    printf("%s\n",memory[i]);

}
//this function prints the contents of the memory array.
//main calls this function after execution has finished to display the 
//final memory values

void dec2bin(int dec, char *bin)
{
  int i=0;

  for(i=MEM_WIDTH-1; i>=0; i--)
    {
      if(dec%2==0)
	bin[i]='0';
      //if dec is divisible by 2, adds a 0 to the array.
      else if(dec==0)
	bin[i]='0';
      //adds a 0 to the array if dec is 0
      else
	bin[i]='1';
      //adds a 1 to the array if dec is not divisible by 2
      dec/=2;
      //halves dec in preperation for next loop iteration
     }
}
//this function converts a decimal integer to a binary 
//representation (character array of 0's and 1's) by
//accepting a string and an integer, then deviding by 2 and 
//concatenating the remainder.  The null character is already
//in the last position, because *bin is a string to begin with.


int bin2dec(char *bin)
{
  int i=0, total=0, j, x, z;

  z=strlen(bin);
  //z saves the length of the string bin.  This is important,
  //because as bin is incremented to check the next character,
  //the length of strlen(bin) is reduced.

  while(*bin != '\0')
    {
      //loop continues until end of string is reached
      if(*bin=='1')
	{
	  x=1;
	  for(j=0; j<z-i-1; j++)
	    x*=2;
	    total+=x;
	}
      //if the currently observed value of bin is the 1 character, then 
      //2^(length of the string-index of character-1).  Example:
      //if we are looking at the 3rd entry of bin[] (index 2), and
      //the string is 8 bits long, and we observe a 1, then we add 
      // 2^(8-2-1)=2^5=32 to our total.  This effectively converts
      //the string from binary into an integer.

      i++;
      bin++;
      //i and bin are incremented for the next loop iteration
    }
  bin-=i;
  //bin is reset to point at the first entry of the string.
  //not really necessary, but good coding practice to restore
  //defaults
  return total;
  //returns the integer representation of the original binary
  //number
}
//this funcion converts a string representing a binary number 
//into an integer.


void execute()
{
  int i, dec_op, dec_ac, dec_arg;
  char op[OPCODE_SIZE+1], arg[MEM_WIDTH+1-OPCODE_SIZE];
  //local vars declared

  for(i=0; i<OPCODE_SIZE; i++)
    op[i]=ir[i];
  op[i+1]='\0';
  //derives the OPCode from the first 3 bits in the IR, 
  //which is derived from the current memory address, and
  //puts a null character at the end of op[] so that it can
  // be used as a string in bin2dec.


  for(i=OPCODE_SIZE; i<MEM_WIDTH+1; i++)
    arg[i]=ir[i];
  //uses remaining 5 bits in memory to determine the 
  //binary representation of the argument to be executed.

  dec_op=bin2dec(op);
  dec_ac=bin2dec(ac);
  dec_arg=bin2dec(arg);
  //initializes the decimal representation of binary numbers op,
  //ac, and arg, for later convenience.

  if(dec_op==0)
    halt=1;
  //if the OPCode codes for 0, halt is made true, and execute is done.
  //this causes a reaction in main(), in that the loop that 
  //repeatedly checks memory for commands, executes, increments pc,
  //and checks again is broken.  Memory and AC are displayed, and 
  //main terminates.


  else if(dec_op==1)
   {
     if(dec_ac != 0)
       pc=dec_arg;
   }
  //performs JANZ for the OPCode 1.  Jumps PC to memory address
  //in argument.

  else if(dec_op==2)
   {
     strcpy(memory[dec_arg],ac);
   }
  //performs StAM. copies current AC value to memory
  //address as speicified by memory[dec_arg].


  else if(dec_op==3)
   {
     strcpy(ac, memory[dec_arg]);
   }
  //performs LdAM for OPCode 3.  Copies memory value
  //memory[dec_arg] into the AC.

  else if(dec_op==4)
   {
     dec_ac=dec_ac+bin2dec(memory[dec_arg]);
     dec2bin(dec_ac, ac);
   }
  //performs AddM for OPCode 4.  Adds the memory
  //at address arg to the AC. 

  else if(dec_op==5)
   {
     dec_ac+=dec_arg;
     dec2bin(dec_ac,ac);
   }
  //performs AddI for OPCode 5. Adds the argument to 
  //the AC.

  else if(dec_op==6)
   {
     dec_ac-=bin2dec(memory[dec_arg]);
     dec2bin(dec_ac,ac);
   }
  //performs SubM for OPCode 6.  Subtracts memory at
  //address arg from the AC.


  else if(dec_op==7)
   {
     dec_ac-=dec_arg;
     dec2bin(dec_ac,ac);
   }
  //performs SubI for OPCode 7.  Subtracts arg from the AC.
}
