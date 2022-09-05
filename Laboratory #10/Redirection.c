/*---------------------------------------*/
/* Natalia Perez                         */
/* Redirection.c                         */

#include "lab9_10.h"

void Redirection(int argc, char *argv[])
{
    int OutLoc = 0;
    int InLoc = 0;
    int i;

    for(i = 0; i < argc; i++)
    {
	if(strcmp(argv[i], ">") == 0)
	{
	    if(OutLoc != 0)
	    {
	        fprintf(stderr, "Cannot output to more than one file.\n");
	        _exit(EXIT_FAILURE);
	    }
	    else if(i == 0)
	    {
		fprintf(stderr, "No command entered.\n");
		_exit(EXIT_FAILURE);	
	    }
	    OutLoc = i;
	}
        else if(strcmp(argv[i], "<") == 0)
	{
	    if(InLoc != 0)
	    {
	        fprintf(stderr, "Cannot input from more than one file.\n");
		_exit(EXIT_FAILURE);
	    }
	    else if(i == 0)
	    {
		fprintf(stderr, "No command entered.\n");
		_exit(EXIT_FAILURE);
	    }
	    InLoc = i;
	}
    }
    if(OutLoc != 0)
    {
	if(argv[OutLoc + 1] == NULL)
	{
	    fprintf(stderr, "There is no file.\n");
	    _exit(EXIT_FAILURE);
	}
	int fd = open(argv[OutLoc + 1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if(fd == -1)
	{
	 
            perror("Error. Check the open.\n");
	    _exit(EXIT_FAILURE);
	}
	dup2(fd, 1);
	if(close(fd) == -1)
	{
	    perror("Close file error\n");
	    exit(EXIT_FAILURE);
	}
        argv[OutLoc] = NULL;
    }

    if(InLoc != 0)
    {
	if(argv[InLoc + 1] == NULL)
	{    
	    fprintf(stderr, "There is no file.\n");
	    _exit(EXIT_FAILURE);
        }
	int fd = open(argv[InLoc + 1], O_RDONLY);
	if(fd == -1)
	{
	    perror("Error. Check the open.\n");
	    _exit(EXIT_FAILURE);
	}
        dup2(fd, 0);
	if(close(fd) == -1)
	{
	    perror("Close file error.\n");
	    exit(EXIT_FAILURE);
	}   
        argv[InLoc] = NULL;
    }
}
