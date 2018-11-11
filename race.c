//David Vargas Puga
#include <stdio.h>
#include <stdlib.h>
#include "racer.h"
#include "race.h"

/* function prototypes */ 
race * create_race(int max_it);
int add_racer(race * rec, racer rcr);
int calc_min_age(race * rec);
int calc_max_age(race * rec);
double calc_avg_age(race * rec);
int delete_racer(race * rec, int racer_num);
void print_race(race * rec);
void free_race(race * rec);

/* creates a race object with max_it amount of racers
 */
race *create_race(int max_it)
{
    race * rce = malloc(sizeof(race)); //allocates memory for the race object
    rce->num_racers = 0; //defaults the number of racers
    //if number passed is greater than 0, set maximum amount of racers to number passed
    if(max_it > 0)
        rce->max_racers = max_it;
    //if number passed is negative, sets maximum amount of racers to 20
    else
        rce->max_racers = 20;
    rce->racers = malloc(rce->max_racers * sizeof(racer)); //allocates memory for maximum amount of racers
    return rce;
}

/* adds a racer to the race
 */
int add_racer(race * rec, racer rcr)
{
    //if race is at max, cannot add racer
    if(rec->num_racers == rec->max_racers)
    {
        printf("Cannot add another racer to race. Maximum capacity has been reached.\n");
        return -1;
    }
    //else, if bib number passed does not match any bib numbers from race, sets racer object in position num_racers in the racers array
    else
    {
        int i;
        int check_bib_number = 1;
        for(i = 0; i < rec->num_racers; i++)
        {
            if(rec->racers[i].bib_number  == rcr.bib_number)
            {
                check_bib_number = 0;
            }
        }

        if(check_bib_number)
        {
            rec->racers[rec->num_racers] = rcr;
            (rec->num_racers)++;
        }
        return 0;
    }
}

/* deletes racer from race
 */
int delete_racer(race * rec, int racer_num)
{
    //intializes variables:
	int i;
	int j;
    //if the amount of racers in race is 0 or less, print racer not found, not deleted
	if(rec->num_racers <= 0 )
	{
		printf("Racer number %d not found. Did not delete\n", racer_num);
		return -1;
	}
    
    //if racer is found, shift all the racers right of found racer to the left
	for(i = 0; i < rec->num_racers; i++)
	{
		if(rec->racers[i].bib_number == racer_num)
		{
			for(j = i; j < rec->num_racers - 1; j++)
			{
				rec->racers[j] = rec->racers[j+1];
			}
			(rec->num_racers)--;
			return 0;
		}

	}
	printf("Racer number %d not found. Did not delete\n", racer_num); //if no racer found, print that it was not deleted
	return -1;

}

/* calculates the maximum age of all racers
 */
int calc_max_age(race * rec)
{
	int i, max_age;
    if(rec->num_racers == 0)
        max_age = 0;
    else
        max_age = rec->racers[0].age;
	for(i = 0; i < rec->num_racers; i++)
	{
		if(rec->racers[i].age > max_age)
		{
			max_age = rec->racers[i].age;
		}
	}
	return max_age;
}

/* calculates the minimum age of all racers
 */
int calc_min_age(race * rec)
{
	int i, min_age;
    if(rec->num_racers == 0)
        min_age = 0;
    else
        min_age = rec->racers[0].age;
	for( i = 0; i < rec->num_racers; i++)
	{
		if(rec->racers[i].age < min_age)
		{
			min_age = rec->racers[i].age;
		}
	}
	return min_age;
}

/* calculates the average age of all racers
 */
double calc_avg_age(race * rec)
{
	int i;
	double avg_age, total_sum = 0;
    if(rec->num_racers == 0)
    {
        avg_age = 0;
        return avg_age;
    }
    else
        avg_age = rec->racers[0].age;
	for(i=0;i < rec->num_racers; i++)
	{
		total_sum += rec->racers[i].age;
	}
	avg_age = total_sum / (double) rec->num_racers;
	return avg_age;
}

/* prints all of the racers in the race and the average, minimum, and maximum ages
 */
void print_race(race * rec)
{
	int i;
    printf("Race:\n");
	for(i = 0; i < rec->num_racers; i++)
	{
		print(rec->racers[i]);
	}
    printf("Racer ages youngest: %d yo, oldest: %d yo, average age: %.2f\n\n", calc_min_age(rec), calc_max_age(rec), calc_avg_age(rec));
}

/* frees memory for race passed in
 */
void free_race(race * rec)
{
	free(rec->racers);
	free(rec);
}
