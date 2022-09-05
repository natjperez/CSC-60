/*---------------------------------------------------*/
/* Natalia Perez                                     */
/* Lab 4                                             */
/* Figure the area of a trapezoid using a data file  */

#include <stdio.h>
#include <stdlib.h>

#define IN_FILE_NAME "lab4.dat"
#define OUT_FILE_NAME "lab4.txt"

int main(void)
{
    double h, s1, s2, area;
    FILE *infile;
    FILE *outfile;

    infile = fopen("lab4.dat","r");
    if(infile == NULL)
    {
        printf("Error on fopen input file\n");
        exit(EXIT_FAILURE);
    }
    
    outfile = fopen("lab4.txt","w");
    if(outfile == NULL)
    {
        printf("Error on fopen output file\n");
        exit(EXIT_FAILURE);
    }

    fprintf(outfile, "\nNatalia Perez.  Lab 4. \n\n");
    fprintf(outfile, "Area of Trapezoid \n\n");
    fprintf(outfile, " Height      Side1       Side2         Area   \n");
    fprintf(outfile, "--------   ---------   ---------   ---------- \n");
    while((fscanf(infile,"%lf %lf %lf", &h, &s1, &s2)) == 3)
    {
        area = 1.0/2.0*h*(s1 + s2);
        fprintf(outfile, "%7.2f    %7.2f    %8.2f    %10.3f\n", h, s1, s2, area);
    }

    fprintf(outfile, "\n\n");
    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}
/*---------------------------------------------------*/
