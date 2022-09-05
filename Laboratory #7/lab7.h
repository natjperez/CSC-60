/*  Natalia Perez                           */
/*  lab7.h - Olympic woman's javelin throw  */

#define NCOMPETITORS 4
#define N_TRIES 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUT_FILENAME "lab7.txt"
//#define OUT_FILENAME "lab7sample.txt"

#define IN_FILENAME "lab7.dat"
//#define IN_FILENAME "lab7sample.dat"

// ADD YOUR TYPEDEF STRUCTS HERE
typedef struct
{
    double average_of_best_throws;
    double winning_throw;
}stats_t;

typedef struct
{
    char name[20];
    double tries[N_TRIES];
    double best_throw;
    double deviation;
}thrower_t;

/* FUNCTION PROTOTYPES */
/* get_data is a function to get and read data */
void get_data (char *filename,                        /* input  */ 
	       thrower_t throw_list[NCOMPETITORS] );  /* output */

/* open_out_file is a function to open the output file */
FILE * open_out_file (void);
		
/* get_stats is a function to do figure the best throw for each      */
/* thrower, compute the all-over average of the best throws, and     */
/* find the longest throw  on the track and each thrower's deviation */
/* from that winning long throw                                      */
void get_stats(thrower_t throw_list[NCOMPETITORS], /* in & out       */
 	       stats_t *throw_stats);                  /* output     */

				
/*  print_all is a function to print things out.
    all of its arguments are input  */
void print_all(FILE * out_file,
               thrower_t throw_list[NCOMPETITORS],
               stats_t *throw_stats);				 
         
