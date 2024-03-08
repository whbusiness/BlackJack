// Guessr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "header.h"


void checkIfTheyWantAnotherCard(hands getHand);
void StartAIHand(int playerHand, hands getHand);
bool CheckIfAIWon(int playerHand, int dealerHand);
bool CheckIfAILost(int dealersHand);
void DealerHit(int dealersHand, int playerHand);
void GameOver();
void StartGame();
using namespace std;

bool Won = false;


int main()
{
    StartGame();

    return 0;
}
void checkIfTheyWantAnotherCard(hands getHand) {
    char response = getHand.getResponse();
    int otherCard = getHand.getOtherCard();
    int hand = getHand.getHand();
    response = AskForResponse();
    getHand.setResponse(response);
    otherCard = GetResponse(response);
    getHand.setOtherCard(otherCard);

    if (otherCard <= 0) {
        StartAIHand(hand, getHand);
    }
    else if(otherCard > 0)
    {
        hand += otherCard;
        getHand.setHand(hand);
        cout << "Your Hand Is Currently: " << endl << hand;
        if (hand >= 21) {
            Won = false;
            GameOver();
        }
        else {
            checkIfTheyWantAnotherCard(getHand);
        }
    }
}


void GameOver() {
    if (Won) {
        cout << "You Won! " << endl << "Would you like to play again?" << endl;
    }
    else {
        cout << "You lost! " << endl << "Would you like to play again?" << endl;
    }
    char response;
    cin >> response;
    if (response == 'y') {
        StartGame();
    }
    else {
        exit(0);
    }
}


void StartGame() {
    hands getHand;
    getHand.ResetVariables();
    cout << "Welcome To Blackjack" << endl;
    cout << "Your Starting Card is: " << endl;
    int hand = getHand.getHand();
    hand = ReturnCard();
    cout << hand;
    getHand.setHand(hand);
    checkIfTheyWantAnotherCard(getHand);
}


void StartAIHand(int playerHand, hands getHand) {
    cout << "Your Hand Is: " << playerHand << endl;
    cout << "The Dealer is now recieving their cards..." << endl;
    getHand.ResetVariables();
    int dealersHand;
    int otherCard;
    dealersHand = ReturnCard();
    getHand.setHand(dealersHand);
    cout << "Dealers Hand is: " << dealersHand << endl;
    if (CheckIfAIWon(playerHand, dealersHand)) {
        Won = false;
        GameOver();
    }
    if (CheckIfAILost(dealersHand)) {
        Won = true;
        GameOver();
    }
    if (!CheckIfAIWon(playerHand, dealersHand) && !CheckIfAILost(dealersHand)) {
        DealerHit(dealersHand, playerHand);
    }
}

void DealerHit(int dealersHand, int playerHand) {
    int otherCard = 0;
    cout << "Dealer Has Decided To Hit..." << endl;
    otherCard = ReturnCard();
    dealersHand += otherCard;
    cout << "Dealers Hand is: " << dealersHand << endl;
    if (CheckIfAILost(dealersHand)) {
        Won = true;
        GameOver();
    }
    else if (CheckIfAIWon(playerHand, dealersHand)) {
        Won = false;
        GameOver();
    }
    else {
        DealerHit(dealersHand, playerHand);
    }
}

bool CheckIfAIWon(int playerHand, int dealerHand) {
    if (dealerHand > playerHand) {
        return true;
    }
    return false;
}
bool CheckIfAILost(int dealerHand) {
    if (dealerHand > 21) {
        return true;
    }
    return false;
}