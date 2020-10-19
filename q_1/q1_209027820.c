#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>



char globBuf[65536];            /* 1. globBuf: uninitialized data section */ 


int primes[] = { 2, 3, 5, 7 };  /* 2. D: initialized data section  */


static int
square(int x)                   /* 3. t-: text (code) section.*/
//000000000000068a t square -  

{
    int result;                 /* 4. stack: in register */

    result = x * x;
    return result;              /* 5. Return value passed by: register*/ 
}

static void
doCalc(int val)                 /* 6. t-: text (code) section */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7.in Stack */	
			

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /*8. t-: text (code) section*/

{
    static int key = 9973;      /*9. d-: initialized data section */


    static char mbuf[10240000]; /*  10. B-: BSS uninitialized data*/

    char* p;                    /* 11. Not allocated */


    doCalc(key);

    exit(EXIT_SUCCESS);
}