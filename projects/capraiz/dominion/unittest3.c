/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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
    int Valid = 0;
    int compare(const int* a, const int* b);

    printf ("\n-------------------- TESTING shuffle(): ----------------------\n");

    // Initialize the gameState structs
    memcpy(&TempG, &G, sizeof(struct gameState));

    // Note: int shuffle(int player, struct gameState *state)
    Check = shuffle(0, &G);

    // TEST 1.1
    if (G.deckCount[0] > 0) {

        //assert(Check != -1);
	if (Check != -1) {
	   printf("TEST 1.1 Passed\n");
	   Valid++;
	}

	else {
	   printf("TEST 1.1 Failed\n");
	}

        // Referenced from shuffle() function in dominion.c file
        qsort((void*)(G.deck[0]), G.deckCount[0], sizeof(int), compare);
        qsort((void*)(TempG.deck[0]), TempG.deckCount[0], sizeof(int), compare);
    }

    // TEST 1.2
    else {

        //assert(Check == -1);
	if (Check == -1) {
	   printf("TEST 1.2  Passed\n");
	   Valid++;
	}

	else {
	   printf("TEST 1.2 Failed\n");
	}

    }

    //assert(memcmp(&G, &TempG, sizeof(struct gameState)) == 0);

    // TEST 2
    if (memcmp(&G, &TempG, sizeof(struct gameState) == 0)) {
       printf("TEST 2 Passed\n");
       Valid++;
    }

    else {
       printf("TEST 2 Failed\n");
    }

    if (Valid >= 2) {
       printf("All tests passed!\n");
    }

    else {
       printf("Not all tests passed!\n");
    }

    return 0;

}
