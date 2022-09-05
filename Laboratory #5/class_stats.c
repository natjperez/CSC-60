// Natalia Perez
// Lab 5, class_stats function
/*-------------------------------------------------*/
/* This code will reside in a file class_stats.c   */
/* In a separate file from the other functions     */
#include "lab5.h"
void class_stats(int grades[], int number_of_grades, double *average, int distribution[])
{
     *average = 0;
     int position;
     int i;
     for(i = 0; i < DIST_SIZE; i++)
     {
         distribution[i] = 0;
     }
     for(i = 0; i < number_of_grades; i++)
     {   
         *average += grades[i];
         position = grades[i] / 10;   
         distribution[position] += 1;
     }

     *average = *average / number_of_grades;

     return;
}
/*-------------------------------------------------*/
