/* This program takes 3 arguments: The name of a .jpg file to be analyzed, the file that the histogram data will be written to,    *
 * and the number of bins that the data should be sorted into.  The file is decompressed, and then scanned pixel-by-pixel for the  *
 * intensities of the three component colors (red green and blue) in each pixel.  Each pixel is then placed into a bin based on its*
 * combination of intensity levels.  The number of bins is a user-given argument, and they are of equal size.  Color intensities   *
 * range from 0 to 255, so the size of the bins is {int (265/bin_size)}.  On a final note, the file must be linked to a            *
pre-decompressed jpeg.o file supplied by another coder in order for the load_jpg function to work.                                 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jpeg.h"
//include directives add the stdio, stdlib, and math libraries to our disposal, as well as the instructor-supplied jpeg.h header file.

#define COLORS 3
//macro definition for number of colors used.

unsigned int *compute_histogram(unsigned char *pixels, int width, int height, int bins_per_color);
void write_histogram(int *histogram, int bins_per_color, char *file_name);
void deallocate();
unsigned char *get_pixels(char *filename, int *width, int *height);
//function prototype declarations.

int main(int argc, char *argv[])
{
  int *width, *height, bins;
  unsigned int *histogram;
  unsigned char *pixels;  

  width=calloc(1,sizeof(int));
  height=calloc(1,sizeof(int));
  //designates memory to be used to store width and height of photo

  bins=argv[3][0]-48;
  //finds the integer value of the number of bins entered at the command line, assuming use of the ascii charcter set

  pixels =  get_pixels(argv[1], width, height);
  //calls function get_pixels to extract pixel data from the photo file given at the command line.  stores data in pixels variable

  histogram = compute_histogram(pixels, *width, *height, bins);
  //calls compute_histogram to use pixel data to calculate histogram'

  write_histogram(histogram, bins, argv[2]);
  //writes formatted results of histogram data to and output file.

  deallocate();
  //releases memory used by compute_histogram
  return 0;

}

unsigned int *compute_histogram(unsigned char *pixels, int width, int height, int bins_per_color)
{
  int i, j, count=0, bin_size=256/bins_per_color;
  unsigned int *histogram;
  unsigned char blue, green, red;

  histogram=calloc(pow(bins_per_color,COLORS), sizeof(unsigned int));
  //allocates memory for histogram data

  if(bins_per_color%2==0)
    //checks for divisibility by 2 of the command-line-entered number of bins.

    {
      for(i=0; i<height*width; i++)
	//for each pixel
	{
	  	  red=*pixels++;
	          green=*pixels++;
	          blue=*pixels++;
   		  pixels++;
		  //takes information or red, green and blue intensities for the current pixel, 
		  //and then increments pixel's memory location again in order to skip the alpha channel
	for(j=1; j<=bins_per_color; j++)
	  {
	    if(blue >= j*bin_size)
	      count++;

	    if(green >= j*bin_size)
	      count+=bins_per_color;

	    if(red >= j*bin_size)
	      count+=pow((double) bins_per_color,2);
	  }
	//increments count for each time that a color "goes up" a bin size in accordance with how much weight that color's number carries
	histogram[count]++;
	//adds count of 1 pixel to the proper bin

	    count=0;
	    //resets count of next iteration
	}
    return histogram;
    //returns pointer to histogram data
    }
  else
    return NULL;
}



void write_histogram(int *histogram, int bins_per_color, char *file_name)
{
  int i;
  FILE *fp;

  if((fp=fopen(file_name, "w")) != NULL)
    //opens file(name supplied by command line
    {
      for(i=1; i<=pow(bins_per_color,COLORS); i++)
	{
	  fprintf(fp, "%d, ", histogram[i-1]);
	  if(i%bins_per_color==0 && i != 0)
	    fprintf(fp, "\n");

	  if(i%(int)pow(bins_per_color,2)==0 && i != 0)
	    fprintf(fp, "\n");
	}
}
  //prints histogram data to output file
  close(fp);
  //closes file after use
}

void deallocate(unsigned int *histogram)
{
    free(histogram);
}
//frees memory used by compute_histogram


unsigned char *get_pixels(char *filename, int *width, int *height)
{
  int bytes, i;
  FILE *fp;
  unsigned char *pixels;

  bytes = loadJPG(filename, "info.out");
  //decompresses picture

  pixels=calloc(bytes, sizeof(unsigned char));
  //allocates space for pixel data

  if((fp=fopen("info.out","rb"))!=NULL)
    //opens file created by loadjpg
    {
      fread(width, sizeof(int), 1, fp);
      fread(height, sizeof(int), 1, fp);
      fread(pixels, sizeof(unsigned char), bytes, fp);	  
    }	
  //reads width and height from the info file, then alll pixel data
  else
    printf("fail");
    fclose(fp);
    //closes file after use
    return pixels;
    //returns pointer to pixel data
}



