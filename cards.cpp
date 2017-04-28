
#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
 You might or might not need these two extra libraries
 #include <iomanip>
 #include <algorithm>
 */


/* *************************************************
 Card class
 ************************************************* */

/*
 Default constructor for the Card class.
 It could give repeated cards. This is OK.
 Most variations of Blackjack are played with
 several decks of cards at the same time.
 */
Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS; break;
        case  2: rank = DOS; break;
        case  3: rank = TRES; break;
        case  4: rank = CUATRO; break;
        case  5: rank = CINCO; break;
        case  6: rank = SEIS; break;
        case  7: rank = SIETE; break;
        case  8: rank = SOTA; break;
        case  9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English
string Card::get_english_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "golds";
            break;
        case COPAS:
            suitName = "cups";
            break;
        case ESPADAS:
            suitName = "swords";
            break;
        case BASTOS:
            suitName = "clubs";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in English
string Card::get_english_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "One";
            break;
        case DOS:
            rankName = "Two";
            break;
        case TRES:
            rankName = "Three";
            break;
        case CUATRO:
            rankName = "Four";
            break;
        case CINCO:
            rankName = "Five";
            break;
        case SEIS:
            rankName = "Six";
            break;
        case SIETE:
            rankName = "Seven";
            break;
        case SOTA:
            rankName = "Jack";
            break;
        case CABALLO:
            rankName = "Knight";
            break;
        case REY:
            rankName = "King";
            break;
        default: break;
    }
    return rankName;
}


// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
}

int Card::get_value() const{
    int rank = get_rank();
    if(rank < 8){
        value = rank;
    }
    else{
        value = 0.5;
    }
    return value;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}

void Card::print_card() const {
    std::string suit_sp = c.get_spanish_suit();
    std::string rank_sp = c.get_spanish_rank();
    std::string suit_eg = c.get_english_suit();
    std::string rank_eg = c.get_english_rank();
    std::cout << "\t" << rank_sp << " de " << suit_sp << "\t(" << rank_eg << " of " << suit_eg <<")." <<endl;
}


/* *************************************************
 Hand class
 ************************************************* */

Hand::Hand(){
    Card c;
    cards_.push_back(c);
    value = c.get_value();
}

void Hand::add_card(){
    Card c;
    cards_.push_back(c);
    value += c.get_value();
}

void Hand::print(){
    std::cout << "Dealer's cards: " << endl;
    for(i = 0; i<cards.size(); ++i){
        cards_[i].print_card();
    }
    std::cout << "The dealer's total is: " << value << endl;
}

int Player::get_value(){
    return value;
}

/* *************************************************
 Player class
 ************************************************* */
Player::Player(int m){
    Card c;
    cards_.push_back(c);
    total =c.get_value();
    money = m;
}

void Player::add_card(){
    Card c;
    cards_.push_back(c);
    total += c.get_value();
}

void Player::if_win(int bet){
    cards_.erase(cards.begin(),cards.end());
    money = m+bet;
    total = 0;
}

void Player::if_lose(int bet){
    cards_.erase(cards.begin(),cards.end());
    money = m-bet;
    total = 0;
}

void Player::print_newcard(){
    Card c = cards_[cards_.size()-1];
    
    std::cout << "New card: " << endl;
    c.print_card();
}

int Player::get_total() const{
    return total;
}

int Player::get_money() const{
    return money;
}
