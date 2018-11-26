/*
 * cardtest3.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "council_room"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int xtraBuys = 0;
    int shuffledCards = 0;

    //int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    //int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +4 cards --------------
	printf("TEST 1: choice1 = 1 = +4 cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 4;
	xtraCoins = 0;
	xtraBuys = 0;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + xtraBuys);
	//assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	//assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	//assert(testG.coins == G.coins + xtraCoins);
	//assert(testG.numBuys == G.numBuys + xtraBuys);
	
	// Check Test 1.1
	if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) {
	   printf("TEST 1.1 Passed\n");
	}

	else {
	   printf("TEST 1.1 Failed\n");
	}

	// Check Test 1.2
        if (testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) {
	   printf("TEST 1.2 Passed\n");
	}

	else {
	   printf("TEST 1.2 Failed\n");
	}
        
	// Check Test 1.3
	if ((testG.coins == G.coins + xtraCoins) && (testG.numBuys == G.numBuys + xtraBuys)) {
	   printf("TEST 1.3 Passed\n");
	}

	else {
	   printf("TEST 1.3 Failed\n");
	}


	// ----------- TEST 2: choice1 = 2 = +1 buy --------------
	printf("TEST 2: choice1 = 2 = +1 buy\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 2;
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 0;
	xtraCoins = 0;
	xtraBuys = 1;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + xtraBuys);
	//assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	//assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	//assert(testG.coins == G.coins + xtraCoins);
	//assert(testG.numBuys == G.numBuys + xtraBuys);
	
	// Check Test 2.1
	if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards) {
	   printf("TEST 2.1 Passed\n");
	}

	else {
	   printf("TEST 2.1 Failed\n");
	}

	// Check Test 2.2
        if (testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards) {
	   printf("TEST 2.2 Passed\n");
	}

	else {
	   printf("TEST 2.2 Failed\n");
	}
        
	// Check Test 2.3
	if ((testG.coins == G.coins + xtraCoins) && (testG.numBuys == G.numBuys + xtraBuys)) {
	   printf("TEST 2.3 Passed\n");
	}

	else {
	   printf("TEST 2.3 Failed\n");
	}


	// ----------- TEST 3: choice1 = 3  -------------
	printf("TEST 3: choice1 = 3 : Ensure no game state change for other player\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 3;
	//cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 0;
	xtraCoins = 0;
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	//printf("coins = %d, expected = %d\n", testG.coins, G.coins);
	//printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + xtraBuys);
	//assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
	//assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
	//assert(testG.coins == G.coins + xtraCoins);
	//assert(testG.numBuys == G.numBuys + xtraBuys);

        // Check Test 3.1
	if (testG.handCount[otherPlayer] == G.handCount[otherPlayer]) {
	   printf("TEST 3.1 Passed\n");
	}

	else {
	   printf("TEST 3.1 Failed\n");
	}

	// Check Test 3.2
        if (testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]) {
	   printf("TEST 3.2 Passed\n");
	}

	else {
	   printf("TEST 3.2 Failed\n");
	}
        
	// Check Test 3.3
	if ((testG.coins == G.coins + xtraCoins) && (testG.numBuys == G.numBuys + xtraBuys)) {
	   printf("TEST 3.3 Passed\n");
	}

	else {
	   printf("TEST 3.3 Failed\n");
	}

	// ----------- TEST 4: choice1 = 4 : Each other player draws a card --------------

	printf("TEST 4: choice1 = 4 : Each other player draws a card\n");
	choice1 = 4;
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	//choice1 = 4;
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 1;
	xtraCoins = 0;
	xtraBuys = 0;
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer] + newCards);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + xtraBuys);
	//assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer] + newCards - discarded);
	//assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer] - newCards + shuffledCards);
	//assert(testG.coins == G.coins + xtraCoins);
	//assert(testG.numBuys == G.numBuys + xtraBuys);
        
	// Check Test 4.1
	if (testG.handCount[otherPlayer] == G.handCount[otherPlayer] + newCards) {
	   printf("TEST 4.1 Passed\n");
	}

	else {
	   printf("TEST 4.1 Failed\n");
	}

	// Check Test 4.2
        if (testG.deckCount[otherPlayer] == G.deckCount[otherPlayer] - newCards + shuffledCards) {
	   printf("TEST 4.2 Passed\n");
	}

	else {
	   printf("TEST 4.2 Failed\n");
	}
	

	//printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


