//Monica Perea
//Sources: GeeksforGeeks pointer in C, Stack Overflow, and Claude ai

#include <stdio.h>   // printf
#include <stdlib.h>  // malloc, free , atoi (ASCII to integer)

#include "array.h"  // Array Structure

void output_array(Array *a); //Prints all the values in the array
void shift_array(Array *a); // Shifts values one position to the left
Array *average_adjacent(Array *a);


int main(int argc, char **argv)  // int argc (# of arguments), Arry if strings
                                 // (char **argv) for each of arguments
{
  Array *a1; //to the main array
  Array *a2; //pointer to the average adjacent array
  

  if (argc != 2)  // checks if the number of arguments is not equal to 2
  {
    printf("Please enter the size of the array.\n");
    // prints the usage message with the program name and expected argument
    return 1;
  }

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

    shift_array(a1);

    a2 = average_adjacent(a1); //"Takes a1, sends it to the average_adjacent function,
                              //and save the new array it give as a2
    output_array(a2);

    free(a1->data);  // frees the original array
    free(a1);  

    free(a2->data);  // frees the averaged array
    free(a2);  
    
        return 0;
  }
  //Function 1
  void output_array(Array *a) {

    int i;

    for (i = 0; i < a->size; i++) {
      printf("%f ", a->data[i]);  // prints the value of the i`th element of the
                                  // data member of the Array structure
    }
    printf("\n"); 

  }
  //Function 2
void shift_array(Array *a) {
  int i;
  double first;

  first = a->data[0];  // Save the first value

  for (i = 0; i < a->size - 1; i++) {
    a->data[i] = a->data[i + 1];
  }
  a->data[a->size - 1] = first; // Move the first value to the last position

}

//Function 3
Array *average_adjacent(Array *a) {

  int i;
  Array *a2;
  a2 = (Array *)malloc(1 * sizeof(Array));  // Allocate memory for the new array
  a2->size = a->size/2;
  a2->data = (double *)malloc(a2->size * sizeof(double));  // Allocate memory for the data member

  for (int i = 0; i < a2->size; i++) {
    a2->data[i] = (a->data[i * 2] + a->data[i * 2 + 1]) / 2.0;
  }

  return a2; //return new array
}



