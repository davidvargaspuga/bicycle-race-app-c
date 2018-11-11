#ifndef RACER_H
#define RACER_H

#define MAX_NAME_LENGTH 16

/* define retail_item struct below */

/* here is an example of defining a point struct with a typedef;
 * delete this in your final code
typedef struct point {
  double x;
  double y;
} point;
 */

//defines a racer struct with typedef:
typedef struct {
int bib_number;
char name[MAX_NAME_LENGTH + 1];
int age;
} racer;

/* function prototypes -- should match your .c implementation */
racer create_racer (int num, char *name, int age);
void print(racer rcr);

#endif
