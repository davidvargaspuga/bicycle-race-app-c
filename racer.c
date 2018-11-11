//David Vargas Puga
#include <stdio.h>
#include "racer.h"
#include "race.h"
#include "string.h"


/* function prototypes*/
racer create_racer (int num, char *name, int age);
void print(racer rcr);

/* declares a racer object using the paramaters passed
 */
racer create_racer(int bib_num, char *name, int age)
{
    //initialize variables
    int default_age = 18;
    int default_bib_number = 300;
    racer rcr;
    //if negative bib number, set's to default and increases default
    if(bib_num  < 1)
        bib_num = default_bib_number;
    rcr.bib_number = bib_num;
    default_bib_number++;
    //if negative age, set's to default
    if(age < 1 )
        age = default_age;
    rcr.age = age;
    //runs through
    for(int i = 0; i < MAX_NAME_LENGTH; i++)
    {
        //if valid character, set it equal to the racer name character at that index
        if(name[i] != '\0')
            rcr.name[i] = name[i];
        //if not, starting at the invalid char, add a blank space at each index until MAX_NAME_LENGTH
        else
        {
            for(int j=i; j < MAX_NAME_LENGTH; j++)
            {
                rcr.name[j] = ' ';
            }
            break;
        }
    }
    rcr.name[MAX_NAME_LENGTH] = '\0'; // finalizes the name at MAX_NAME_LENGTH
    return rcr; //returns racer
}

/*prints information about racer
 */
void print(racer rcr)
{
	printf("Racer %d\t%s\t%d\n", rcr.bib_number, rcr.name, rcr.age);

}
