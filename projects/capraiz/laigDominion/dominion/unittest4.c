/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
    int j;
    int Count;

    printf ("\n----------------------- TESTING isGameOver(): ---------------------------\n");

    // Initialize the gameState structs
    memcpy(&TempG, &G, sizeof(struct gameState));

    Check = isGameOver(&G);

    if (G.supplyCount[province] != 0) {
        assert(Check != 1);
    }

    if (G.supplyCount[province] == 0) {
        assert(Check == 1);
    }

    for (j = 0; j < 25; j++) {
        if (G.supplyCount[j] == 0) {
            Count++;
        }
    }

    if (Count <= 3) {
        assert(Check != 1);
    }

    if (Count >= 3) {
        assert(Check == 1);
    }

    /*
    // Game ends if the Province card supply is empty
    Check = G.supplyCount[province];
    assert(Check == 0);

    // Game ends if any three supply piles are empty
    for (j = 0; j < 25; j++) {
        if (G.supplyCount[j] == 0) {
            Count++;
        }
    }

    assert(Count >= 3);
    */

    printf("All tests passed!\n");

    return 0;

}
