include <stdio.h>   // printf
#include <stdlib.h>  // malloc, free , atoi (ASCII to integer)

#include "array.h"  // Array Structure

void output_array(Array *a); //Prints all the values in the array
void shirt_array(Array *a); // Shifts values one position to the left
Array *average_adjacent(Array *a);


int main(int argc, char **argv)  // int argc (# of arguments), Arry if strings
                                 // (char **argv) for each of arguments
{
  Array *a1;  // initalizing created a pointer to an Array structure with *a1

  if (argc != 2)  // checks if the number of arguments is not equal to 2
  {
    printf("Please enter the size of the array.\n");
    // prints the usage message with the program name and expected argument
    return 1;

    a1 = (Array *)malloc(
        1 * sizeof(Array));  // malloc allocates memory for the Array structure
                             //(Array*) casts the allocated memory to a pointer
                             //of type Array

    a1->size = atoi(argv[1]);  // atoi converts the first command line argument
                               // to an integer and assigns it to the size
                               // member of the Array structure

    a1->data = (double *)malloc(
        a1->size *sizeof(double));  // malloc allocates memory for the data member

    for (int i = 0; i < a1->size; i++) {
      a1->data[i] =
          (double)(i + 1);  // assigns the value of i+1 to the i`th element of
                            // the data member of the Array structure
    }

    output_array(a1);
        return 0;
  }

  void output_array(Array *a) {


  }
  
void shirt_array(Array *a) {
  int i;
  double first;

  first = a->data[0];  // Save the first value

  for (i = 0; i < a->size - 1; i++) {
    a->data[i] = a->data[i + 1];
  }
  a->data[a->size - 1] = first; // Move the first value to the last position

}

Array *average_adjacent(Array *a) {

}



