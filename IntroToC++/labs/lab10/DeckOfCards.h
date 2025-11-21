#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards {
    private:
        int deck[52];
        int next_card;
    public:
        DeckOfCards();
        int dealCard();
        void shuffle();
        bool valid();
};

#endif