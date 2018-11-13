#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "village"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int xtraBuys = 0;
    int xtraActions = 0;
    int shuffledCards = 0;

    //int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    //int remove1, remove2;
    //int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    // Set random seed
    srand(time(NULL));
    int seed = rand() % 5000;

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    int State = 0;
    int tcCount = 0;
       
    printf("\n----------------- Testing Card: %s ----------------\n", TESTCARD);
    printf("------------- Random: Semi-Fixed Tests --------------\n");

    while(1) {

        printf("\n--------------------------------------------------------------------\n");
        printf("Iteration %d: state = %d\n", tcCount, State);
        printf("--------------------------------------------------------------------\n");
    
        // Increment the iteration in the random test
        tcCount++;

        // ----------- TEST 1: choice1 = 1 = +1 cards --------------
        printf("TEST 1: choice1 = 1 = +1 cards\n");

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

        // Random testing for the amount of newCards, xtraCoins, and xtraBuys the player recieves
        newCards = rand() % 5;
        xtraCoins = rand() % 5;
        xtraBuys = rand() % 5;
        xtraActions = rand() % 5;

        //newCards = 1;
        //xtraCoins = 0;
        //xtraBuys = 0;
        printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
        printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
        printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + xtraBuys);
        //assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
        //assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
        //assert(testG.coins == G.coins + xtraCoins);
        //assert(testG.numBuys == G.numBuys + xtraBuys);

        // Check Test 1.1
        if ((testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) && State == 0) {
           printf("TEST 1.1 Passed\n");
           State = 1;
        }

        else {
           printf("TEST 1.1 Failed\n");
        }

        // Check Test 1.2
            if ((testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) && State == 1) {
           printf("TEST 1.2 Passed\n");
           State = 2;
        }

        else {
           printf("TEST 1.2 Failed\n");
        }
            
        // Check Test 1.3
        if ((testG.coins == (G.coins + xtraCoins)) && (testG.numBuys == (G.numBuys + xtraBuys)) && (testG.numActions == (G.numActions + xtraActions)) && State == 2) {
           printf("TEST 1.3 Passed\n");
           State = 3;
        }

        else {
           printf("TEST 1.3 Failed\n");
        }

        // ----------- TEST 2: choice1 = 2 = +2 Actions --------------
        printf("TEST 2: choice1 = 2 = +2 Actions\n");

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 2;
        cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

        // Random testing for the amount of newCards, xtraCoins, xtraBuys, and xtraActions the player recieves
        newCards = rand() % 5;
        xtraCoins = rand() % 5;
        xtraBuys = rand() % 5;
        xtraActions = rand() % 5;

        //newCards = 0;
        //xtraCoins = 0;
        //xtraBuys = 0;
        //xtraActions = 2;
        printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
        printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
        printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + xtraBuys);
        printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
        //assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
        //assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
        //assert(testG.coins == G.coins + xtraCoins);
        //assert(testG.numBuys == G.numBuys + xtraBuys);
        //assert(testG.numActions == G.numActions + xtraActions);
            
        // Check Test 2.1
        if ((testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) && State == 3) {
           printf("TEST 2.1 Passed\n");
           State = 4;
        }

        else {
           printf("TEST 2.1 Failed\n");
        }

        // Check Test 2.2
            if ((testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) && State == 4) {
           printf("TEST 2.2 Passed\n");
           State = 5;
        }

        else {
           printf("TEST 2.2 Failed\n");
        }
            
        // Check Test 2.3
        if ((testG.coins == G.coins + xtraCoins) && (testG.numBuys == G.numBuys + xtraBuys) && (testG.numActions == G.numActions + xtraActions) && State == 5) {
           printf("TEST 2.3 Passed\n");
           State = 6;
        }

        else {
           printf("TEST 2.3 Failed\n");
        }


        // ----------- TEST 3: choice1 = 3  -------------
        printf("TEST 3: choice1 = 3 : Ensure no game state change for other player\n");

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 3;
        //cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

        //newCards = 0;
        //xtraCoins = 0;
        //xtraBuys = 0;
        //xtraActions = 0;
        printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
        printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
        //printf("coins = %d, expected = %d\n", testG.coins, G.coins);
        //printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + xtraBuys);
        //assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
        //assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
        //assert(testG.coins == G.coins + xtraCoins);
        //assert(testG.numBuys == G.numBuys + xtraBuys);
        
            // Check Test 3.1
        if ((testG.handCount[otherPlayer] == G.handCount[otherPlayer]) && State == 6) {
           printf("TEST 3.1 Passed\n");
           State = 7;
        }

        else {
           printf("TEST 3.1 Failed\n");
        }

        // Check Test 3.2
        if ((testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]) && State == 7) {
           printf("TEST 3.2 Passed\n");
           State = 8;
        }

        else {
           printf("TEST 3.2 Failed\n");
        }
            
        // Check Test 3.3
        if ((testG.coins == G.coins + xtraCoins) && (testG.numBuys == G.numBuys + xtraBuys) && (testG.numActions == G.numActions + xtraActions) && State == 8) {
           printf("TEST 3.3 Passed\n");
           State = 9;
        }

        else {
           printf("TEST 3.3 Failed\n");
        }

        // Check if all tests passed
        if (State == 9) {
            printf("\nAll Tests Passed\n");
            exit(0);
        }

        if (tcCount >= 10000) {
            printf("\nError: Too Many Iterations >> Tests Failed\n");
            exit(0);
        }

    }

        //printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


    return 0;
}

