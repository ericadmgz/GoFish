#include <iostream>
#include <fstream>
#include <string>

#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

void turn(Player &player1, Player &player2, Deck &d, ofstream& file){

    bool turnAgain = true;

    while (turnAgain){
        if(player1.getHandSize() > 0){
            Card p1choose = player1.chooseCardFromHand();
            file << player1.getName() << " asks - Do you have a " << p1choose.rankString(p1choose.getRank()) << "?\n";

            if (player2.rankInHand(p1choose)){
                file << player2.getName() << " says - Yes, I do have a " << p1choose.rankString(p1choose.getRank()) << ".\n";
                file << player1.getName() << " books the " << p1choose.rankString(p1choose.getRank()) << ".\n\n";

                Card pair = player2.CardOfRankInHand(p1choose.getRank());
                player1.addCard(pair);
                player1.bookCards(p1choose, pair);
            }

            else{
                file << player2.getName() << " says - Go Fish.\n";
                Card c1 = d.dealCard();     // deal card for each player
                file << player1.getName() << " draws " << c1.toString() << ".\n";
                player1.addCard(c1);
                Card pt1;
                Card pt2;
                int p1books = player1.checkHandForBook(pt1,pt2);
                if (p1books){
                    file << player1.getName() << " books the " << c1.rankString(c1.getRank() )<< ".\n\n";
                    turn(player1, player2, d, file);        // player1's turn again if successful in finding a pair
                }
                else{
                    file << "\n\n";
                    turnAgain = false;
                }
            }
        }
        else{
            Card card1 = d.dealCard();          // if player's hand is empty, draw a card from deck
            player1.addCard(card1);
            file << player1.getName() << "'s hand is empty - draws " << card1.toString() <<".\n\n";
            turnAgain = false;

        }

    }

}

int main() {

    ofstream file;
    file.open("gofish_results.txt");
    file << "Go Fish!  -  Begin Game\n\n";

    Deck d;                         // create a new deck of cards
    d.shuffle();                    // shuffle the deck

    Player player1("Erica");        // creating first player
    Player player2("Amanda");       // creating second player

    int numCards = 7;               // 7 cards dealt when only two players

    for (int i = 0; i < numCards; i++) {
        Card c1 = d.dealCard();     // deal card for each player
        Card c2 = d.dealCard();

        player1.addCard(c1);        // add card to hand for each player
        player2.addCard(c2);
    }

//    file << player1.getName() << "'s Hand: " << player1.showHand() << endl;

    Card ptr1;
    Card ptr2;
    while(player1.checkHandForBook(ptr1,ptr2)){
//        file << player1.getName() << "'s Books: " << player1.showBooks() << endl;
    }
//    int p1book = player1.checkHandForBook(ptr1, ptr2);
//    int p2book = player2.checkHandForBook(ptr1, ptr2);

//    file << player2.getName() << "'s Hand: " << player2.showHand() << endl;
    while(player2.checkHandForBook(ptr1,ptr2)){
//        file << player2.getName() << "'s Books: " << player2.showBooks() << endl;
    }

    int p1bookSize = player1.getBookSize();
    int p2bookSize = player2.getBookSize();

    while (p1bookSize < 14 && p2bookSize < 14) {
        turn(player1, player2, d, file);
        turn(player2, player1, d, file);

        p1bookSize = player1.getBookSize();
        p2bookSize = player2.getBookSize();
    }

    file << "*********GAME OVER!!!*********" << endl;
    file << player1.getName() << " has " << player1.getBookSize() << " books: " << player1.showBooks() << endl;
    file << player2.getName() << " has " << player2.getBookSize() << " books: " << player2.showBooks() << "\n\n";

    string winner;
    if (player1.getBookSize() > player2.getBookSize()) {
        winner = player1.getName();
    } else {
        winner = player2.getName();
    }

    file << "*********The winner is " << winner << "!!!*********" << endl;
    file.close();
}
