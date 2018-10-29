/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState TempG;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    int Check;

    printf ("TESTING supplyCount():\n");

    Check = initializeGame(4, k, 1, &G);

    printf("Initialized Game = %d\n", Check);
    assert(Check == 0);

    Check = supplyCount(adventurer, &G);

    // Note: There should be 10 of each Kingdom card in a two player game
    // Referenced from dominion.c file
    printf("Supply Count of Adventurer = %d\n", Check);

    // Check that there are 10 Adventurer cards
    assert(Check == 10);

    // Check last type of Kingdom card
    Check = supplyCount(great_hall, &G);

    printf("Supply Count of Great Hall = %d\n", Check);
    assert(Check == 10);

    printf("All tests passed!\n");

    return 0;

}


