// Natalia Perez
// get_stats function Lab 7
#include "lab7.h"

void get_stats(thrower_t throw_list[NCOMPETITORS], stats_t *throw_stats)
{
    throw_stats->average_of_best_throws = 0.0;
    throw_stats->winning_throw = 0.0;
    int r, c;
    for(r = 0; r < NCOMPETITORS; r++)
    {
        throw_list[r].best_throw = throw_list[r].tries[0];
        for(c = 1; c < N_TRIES; c++)
	{
	    if(throw_list[r].tries[c] > throw_list[r].best_throw)
	    {
	       throw_list[r].best_throw = throw_list[r].tries[c];
	    }
        }
	throw_stats->average_of_best_throws = throw_stats->average_of_best_throws + throw_list[r].best_throw;
	
	for(c = 0; c < N_TRIES; c++)
	{
	    if(throw_list[r].tries[c] > throw_stats->winning_throw)
	    {
	       throw_stats->winning_throw = throw_list[c].best_throw;
	    }
	}
    }
    throw_stats->average_of_best_throws = throw_stats->average_of_best_throws / N_TRIES;
    
    for(r = 0; r < NCOMPETITORS; r++)
    {
	throw_list[r].deviation = throw_stats->winning_throw - throw_list[r].best_throw;
    }

    return;
}
