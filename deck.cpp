#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>


#include "deck.h"
#include "card.h"

using namespace std;

Deck::Deck() {           // pristine, sorted deck

    int card_pointer =0;

    Card::Suit suit_s= Card::spades;
    Card::Suit suit_d= Card::diamonds;
    Card::Suit suit_c= Card::clubs;
    Card::Suit suit_h= Card::hearts;

    for(int i=0; i<13; i++){
        Card card_s(i,suit_s);
        myCards[card_pointer]= card_s;

        Card card_d(i, suit_d);
        myCards[card_pointer+13]= card_d;

        Card card_c(i,suit_c);
        myCards[card_pointer+26]= card_c;

        Card card_h(i, suit_h);
        myCards[card_pointer+39]= card_h;

        card_pointer++;
    }

    myIndex = 0;        // initialize Index to first card in deck

}

void Deck::shuffle() {   // shuffle the cards in the current deck

    srand((unsigned)time(0));

    for (int i = 0; i < SIZE; i ++) {
        int random1 = rand() % SIZE;
        int random2 = rand() % SIZE;

        Card temp = myCards[random1];           //temporary holder for 1st card
        myCards[random1] = myCards[random2];    // swap cards
        myCards[random2] = temp;
    }

    myIndex = 0;        // reset Index to first card in deck

}


Card Deck::dealCard() {   // get a card, after 52 are dealt, fail

    if (myIndex <SIZE){
        myIndex++;
        return myCards[myIndex];
    }
    else {      // if deck is empty, return any card, output that deck is empty
        Card c;
        return c;
    }

}


int Deck::size() const { // # cards left in the deck

    return(SIZE - myIndex);            // number of cards left in deck

}