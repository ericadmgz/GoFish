#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>

#include "player.h"

using namespace std;

Player::Player(){
    myName = "";

}

void Player::addCard(Card c) {  //adds a card to the hand

    myHand.push_back(c);        // adds card to the back of hand

}
void Player::bookCards(Card c1, Card c2){

    myBook.push_back(c1);
    myBook.push_back(c2);

    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
//
bool Player::checkHandForBook(Card &c1, Card &c2){
    Card *card1 = new Card();
    Card *card2 = new Card();

    int handSize = getHandSize();

    for (int i=0; i<(handSize-1); i++) {
        Card first = myHand[i];
        int rank1 = first.getRank();

        for (int j=i+1; j<handSize; j++){
            Card second = myHand[j];
            int rank2 = second.getRank();

            if (rank1 == rank2){
                *card1 = first;
                *card2 = second;

                bookCards(*card1, *card2);
                return true;
            }
        }
    }

    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{

    int rank = c.getRank();
    int handSize = getHandSize();

    for (int i=0; i<handSize; i++){
        if (myHand [i].getRank() == rank){
            return true;
        }
    }

    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{

    srand((unsigned)time(0));
    int handSize = getHandSize();

    int random1 = rand()%handSize;

    Card chooseCard= myHand[random1];

    return chooseCard;
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{

    int handSize = getHandSize();

    for(int i=0; i<handSize; i++){
        if (myHand[i] == c){
            return true;
        }
    }

    return false;

}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){

    int handSize = getHandSize();
    int i = 0;

    while(myHand[i] != c && i!= handSize){
        i++;
    }

    Card hold = myHand[i];
    myHand.erase(myHand.begin()+i);
    return hold;
}

string Player::showHand() const{

    string handString;
    string result;

    int handSize = getHandSize();

    if (handSize ==1){
        handString += myHand[0].toString();
        result = handString;
    }

    else{

        for (int i=0; i<(handSize-1); i++){              // Add card and comma to the string (except last card)
            handString += myHand[i].toString();
            handString += ", ";
        }

        handString += myHand[handSize-1].toString();
        result = handString;
    }

    return result;
}

string Player::showBooks() const{

    string bookString;
    string result;

    int bookSize = getBookSize();

    if (bookSize ==1){
        bookString += myBook[0].toString();
        result = bookString;
    }

    else{

        for (int i=0; i<(bookSize-1); i++){              // Add card and comma to the string (except last card)
            bookString += myBook[i].toString();
            bookString += ", ";
        }

        bookString += myBook[bookSize-1].toString();
        result = bookString;
    }

    return result;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const{
    return myBook.size();
}

//This function will check for a players hand for a card of the same rank
//If card of same rank is found, will return the card and erase it from the player's hand
Card Player::CardOfRankInHand(int r) {
    int handSize = getHandSize();

    for(int i=0; i< handSize;i++){
        int compare = myHand[i].getRank();

        if(compare == r){
            Card found = myHand[i];
            removeCardFromHand(found);

            return found;
        }

    }

    Card c;
    return c;
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//bool Player::checkHandForPair(Card &c1, Card &c2){
//
//}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

//bool Player::sameRankInHand(Card c) const{
//
//
//}
