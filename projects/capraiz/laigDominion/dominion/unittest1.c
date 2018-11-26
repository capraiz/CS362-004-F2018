/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i, j;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    typedef enum {numBuys, coins, supplyCount};
    int z = numBuys;
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


    printf("\n----------------- TESTING buyCard() -----------------\n");

    for (z; z <= coins; z++) {

       switch (z) {

	  default:
	     break;

	  case numBuys:

	     printf("TEST 1: numBuys    \n");

	     G.numBuys = 0;

	     if (buyCard(0, &G) == -1) {
		printf("TEST 1 Passed\n");
	     }

	     else {
		printf("TEST 1 Failed\n");
	     }

	     break;

	  case coins:
	     
	     printf("TEST 2: Coins Needed     \n");

	     for (i = curse; i < treasure_map; i++) {

		printf("Card %d Cost\n", i+1);

		G.coins = 0;
		G.numBuys = 1;

		if (buyCard(i, &G) == -1) {
		   printf("TEST Passed\n");
		}

		else {
		   printf("TEST Failed\n");
		}
	     }

	     break;

	  case supplyCount:

	     printf("TEST 3: supplyCount       \n");

	     G.numBuys = 2;

	     for (j = curse; j < treasure_map; j++) {
		
		printf("Card %d Supply\n", j+1);

		G.supplyCount[j] = 0;

		if (buyCard(j, &G) == -1) {
		   printf("TEST Passed\n");
		}

		else {
		   printf("TEST Failed\n");
		}
	     }

	     break;
       }
    }


    //printf("All tests passed!\n");

    return 0;
}
