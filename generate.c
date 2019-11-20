/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// set the range within which long integers will be generated (0-LIMIT)
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: terminate program by returning an error code when user types less or more than 2^3 command-line arguments; 
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");  // instruct user about correct program usage
        return 1;
    }

    // TODO: int n is created, the value of first argument is typecasted into an int and the result is stored as n
    int n = atoi(argv[1]);

    // TODO: in case user inserted a second (optional) argument, cast it as a long integer and apply function srand()
    if (argc == 3)
    {
        srand48((long) atoi(argv[2])); //srand() turns its input into a seed for the creation of a pseudo-random integer sequence
    }
    else
    {
        srand48((long) time(NULL)); 
    }

    // TODO: a loop is set in order for n iterations to run
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT)); // function48() with LIMIT (set above as 65536), its output is cast as an int and printed 
    }

    // success
    return 0;  
}
