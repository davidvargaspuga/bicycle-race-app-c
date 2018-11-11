#ifndef RACE_H
#define RACE_H

#include "racer.h"

/* define receipt struct below */

//defines a race struct with typedef:
typedef struct {
racer * racers;
int num_racers;
int max_racers;
} race;

/* function prototypes - should match your .c implementations */
race * create_race(int max_it);
int add_racer(race * rec, racer rcr);
int calc_min_age(race * rec);
int calc_max_age(race * rec);
double calc_avg_age(race * rec);
int delete_racer(race * rec, int racer_num);
void print_race(race * rec);
void free_race(race * rec);

#endif
