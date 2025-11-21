#include <iostream>
#include <string>
#include <ctime>
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards() {
    srand(time(0));
    for (int i = 0; i < 52; i++){
        deck[i] = i;
    }
    shuffle();
    next_card = 0;
}

int DeckOfCards::dealCard() {
   if (next_card >= 52){
    shuffle();
    next_card = 0;
   }
   return deck[next_card++];
}

void DeckOfCards::shuffle() {
    for (int i = 51; i > 0; i--){
        int j = rand() % (i + 1);
        int placeholder = deck[i];
        deck[i] = deck[j];
        deck[j] = placeholder;
    }

}

bool DeckOfCards::valid() {
    bool found[52] = {false};

    for (int i = 0; i < 52; i++){
        int c = deck[i];
        if (c < 0 || c > 51){
            return false;
        }
        if (found[c]){
            return false;
        }
        found[c] = true;
    }
/*
    for (int i = 0; i = 52; i++){
        if (found[i] == false){
            cout << "Missing card" << endl;
            return false;
        }
    }
        */
    return true;
}



void get_hand(int hand[], int num_cards){
    string names[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; 
    for (int i = 0; i < num_cards; i++){
        int val = hand[i] % 13;
        cout << names[val] << " ";
    }
    cout << endl;
}

int main() {
    DeckOfCards my_deck;

    if(my_deck.valid()){
        cout << "Its valid" << endl;
    }

    else {cout << "Not valid" << endl;}

    for (int i = 0; i < 13; i++){
        int my_hand[4];
        for(int j = 0; j < 4; j++){
            my_hand[j] = my_deck.dealCard();
        }
        get_hand(my_hand, 4);
    }


    return 0;
}