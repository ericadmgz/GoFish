#include <iostream>
#include <string>

#include "card.h"

using namespace std;

Card::Card(){       // default, ace of spades
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {      // return string version e.g. Ac 4h Js
    string cardString;
    string str1 = rankString(myRank);
    string str2 = suitString(mySuit);

    str1.append(str2);
    cardString = str1;

    return cardString;
}

bool Card::sameSuitAs(const Card& c) const {        // true if suit same as c
    if (mySuit == c.mySuit){
        return true;
    }
    else{
        return false;
    }

}

int Card::getRank() const {  // return rank, 1..13

    return myRank;
}

string Card::suitString(Suit s) const{  // return "s", "h",...
    if (s == spades) {
        return "s";
    }
    else if (s == hearts){
        return "h";
    }
    else if (s == diamonds){
        return "d";
    }
    else if (s == clubs){
        return "c";
    }
}

string Card::rankString(int r) const {  // return "A", "2", ..."Q"

    switch(r){

        case 1: return "A";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "10";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return "A";
    }

}


bool Card::operator == (const Card& rhs) const{
    if (myRank == rhs.myRank && mySuit == rhs.mySuit){
        return true;
    }
    else{
        return false;
    }

}

bool Card::operator != (const Card& rhs) const{
    if (myRank == rhs.myRank && mySuit == rhs.mySuit){
        return false;
    }
    else{
        return true;
    }
}

ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}