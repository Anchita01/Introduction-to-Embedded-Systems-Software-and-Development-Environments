/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */

#include <stdio.h>
#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/*static function to swap two unsigned int values*/
static void swap32(unsigned char* a, unsigned char* b)
{
	unsigned char temp = *a;
	*a = *b;
	*b = temp;
}

/**void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

	print_statistics(test,SIZE);
}**/


/*function to print the statistics of an array*/
void print_statistics(unsigned char* arr, unsigned int size)
{
	printf("\nUnsorted Array:\n");
	print_array(arr,size);

	printf("\n\nMedian of the given array = %d\n",find_median(arr, size));

	printf("\nMean of the given array = %f\n",find_mean(arr, size));

	printf("\nMaximum value in the given array = %d\n", find_maximum(arr, size));

	printf("\nMinimum value in the given array = %d\n", find_minimum(arr, size));

	sort_array(arr,size);
	printf("\nSorted Array:\n");
	print_array(arr,size);
}

/*function to print array elements with positions*/
void print_array(unsigned char* arr, unsigned int size)
{
	#ifdef VERBOSE
	for(unsigned char i=0; i<size; i++)
	{
		printf("arr[%i]=%i,\t",i,arr[i]);
	}
	#endif
}

/*function to find the median of an array*/
unsigned char find_median(unsigned char* arr, unsigned int size)
{
	unsigned char median = 0, rem = 0;
	sort_array(arr, size);
	rem = size%2;
	if(rem != 0)	//odd number of elements in array
	{
		median = arr[size/2];
	}
	else		//Even number of elements in array
	{
		median = ( arr[size/2] + arr[(size/2) - 1])/2;
	}	
	return median;
} 

/*function to find the mean of an array*/
float find_mean (unsigned char* arr, unsigned int size){
  float mean = 0;
  for (int i=0; i<size; i++){
    mean = mean + arr[i] /* *(array + i) */;
  }
  mean = mean / ((float) size); //must type cast one of the two integers to float for accurate calculation.
  return mean;
}	

/*function to return maximum value of an array*/
unsigned char find_maximum(unsigned char* arr, unsigned int size)
{
	unsigned char max = 0;
	sort_array(arr, size);
	max = arr[0];
	return max;
}	

/*function to return minimum value of an array*/
unsigned char find_minimum(unsigned char* arr, unsigned int size)
{
	unsigned char min = 0;
	sort_array(arr, size);
	min = arr[size-1];
	return min;
}	

/*function to sort an array in descending order*/
void sort_array(unsigned char* arr, unsigned int size)
{
	for(unsigned char i=0; i<size; i++)
	{
		for(unsigned char j = i+1; j<size; j++)
		{
			if(arr[i]<arr[j])	//comparing the array elements.
			{
				swap32(&arr[i], &arr[j]);	//swap the array elements.
			}
		}
	}
}	
/* Add other Implementation File Code Here */
