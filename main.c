/* CS 305, Fall 2018
 * HOMEWORK 1
 *
 * main.c
 * author: Martin Cenek
 *
 * creates race and racers
 * main.c driver provides tests of race and racer 
 *
 * compile with race.c and racer.c
 * gcc race.c racer.c main.c
 * OR
 * gcc -o signup race.c racer.c main.c
 *
 * If creating signup object file, then run with command:
 * signup
 * Otherwise, run with command:
 * a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include "race.h"
#include "racer.h"

/* prototypes */
int run_test(void);
int longer_than_sixteen(void);
int negative_age_and_bib(void);
int delete_empty_race(void);

/* main 
 * using void paramater since we are not using command line arguments
 * for this program
 */
int main(void) {
    run_test();
    longer_than_sixteen();
    negative_age_and_bib();
    delete_empty_race();
}

/* runs a test, creating racers with negative bib number and age
 */
int negative_age_and_bib(void)
{
    race *test1 = create_race(10); //creates a race for 10 racers
    //creates racers:
    racer david = create_racer(323, "David Vargas", -5);
    racer aidan = create_racer(-100, "Aidan Hall", 18);
    //adds racers to race test1:
    add_racer(test1, david);
    add_racer(test1, aidan);
    print_race(test1); //prints race test1
    free_race(test1); //frees memory for test1
    return EXIT_SUCCESS;
}

/* runs a test, deleting from an empty race
 */
int delete_empty_race(void)
{
    race *test1 = create_race(0); //creates a race object for 0 racers
    delete_racer(test1, 100); //attempts to delete a nonexistent race
    print_race(test1); //prints race
    free_race(test1); //frees memory for race test1
    return EXIT_SUCCESS;
}

/* runs a test, creating a racer with a name longer than 16 characters
 */
int longer_than_sixteen(void)
{
    race *test2 = create_race(10); //creates a race object for 10 racers
    //creates racers:
    racer long_name = create_racer(323, "David Nicolas Vargas Puga", -5);
    racer aidan = create_racer(-100, "Aidan Hall", 18);
    //adds racers to race:
    add_racer(test2, long_name);
    add_racer(test2, aidan);
    print_race(test2); //prints race test1
    free_race(test2); // frees memory for race test2
    return EXIT_SUCCESS;
}

/* run_test
 * runs a test, creating races and adding/deleting racers
 */
int run_test(void) {
    /* create two races */
    /* note: using pointers for races so the race data can be
     modified */
    race *tdf = create_race(-3);
    race *vuelta = create_race(2);



    /* create riders */
    /* note: not using pointers to racers since once they are created
    * they are not later modified -- only used as data */
    // create riders
    racer mickey = create_racer(101, "Mickey Mouse", 18);
    racer pluto = create_racer(333, "Pluto Disney", 16);
    racer goofy = create_racer(222, "Goofy Diskey", 21);
    racer daisy = create_racer(912, "Daisy Duke", 28);
    racer mary = create_racer(124, "Mary Poppins", 41);
    racer pink = create_racer(545, "Pinkalicious", 16);
    racer huey = create_racer(322, "Huey Duck", 15);
    racer dewey = create_racer(122, "Dewey Duck", 15);
    racer louie = create_racer(111, "Louie Duck", 15);
    racer peanut = create_racer(121, "Peanut Brown", 17);
    racer froom = create_racer(1, "Chris Froom", 38);
    racer contador = create_racer(201, "Alberto Contador", 40);
  
   
    
    // put some riders into Race (scanned for checkout)
    add_racer(tdf,mickey);
    add_racer(tdf,pluto);
    add_racer(tdf,goofy);
    add_racer(tdf,daisy);

    // for write-up: draw a picture of what tdf's racer roster looks like

    // print Race
    print_race(tdf);

    // put more riders into Race
    add_racer(tdf,mary);
    add_racer(tdf,pink);
    add_racer(tdf,huey);
    add_racer(tdf,dewey);

    // print Race
    print_race(tdf);

    // add riders
    add_racer(tdf,louie);
    add_racer(tdf,peanut);

    // print Race
    print_race(tdf);

    // add riders to vuelta
    add_racer(vuelta,pluto);
    add_racer(vuelta,pink);
    print_race(vuelta);

    // add another rider
    add_racer(vuelta,huey);


    print_race(tdf);

    /* put more riders in */
    add_racer(tdf, louie);
    add_racer(tdf, louie);
    add_racer(tdf, froom);
    add_racer(tdf, contador);

    /* print the race */
    print_race(tdf);

    /* print the race */
    print_race(tdf);

    /* at point to draw picture 1 in report */

    /* delete riders */
    //printf("Trying to delete rider 333\n");
    delete_racer(tdf, 333);

    /* print the race */
    print_race(tdf);

    /* at point to draw picture 2 in report */

    /* delete rider */
    //printf("Trying to delete rider 0000\n");
    delete_racer(tdf, 0000);


    /* add riders to vuelta */
    add_racer(vuelta, contador);
    add_racer(vuelta, froom);

    /* print race */
    print_race(vuelta);

    /* add another riders to vuelta */
    add_racer(vuelta, mickey);
    add_racer(vuelta, mary);

    /* delete riders */
    //printf("Trying to delete rider 1\n");
    delete_racer(vuelta, 333);
    //printf("Trying to delete rider 0000\n");
    delete_racer(vuelta, 000);
    print_race(vuelta);
    //printf("Trying to delete rider 101\n");
    delete_racer(vuelta, 545);
    print_race(vuelta);
    //printf("Trying to delete rider 124\n");
    delete_racer(vuelta, 545);
    print_race(vuelta);

    /* add riders to vuelta */
    add_racer(vuelta, huey);
    add_racer(vuelta, dewey);
    print_race(vuelta);

    /* free memory for races */
    free_race(vuelta);
    free_race(tdf);

    return EXIT_SUCCESS;
} /* end main */
