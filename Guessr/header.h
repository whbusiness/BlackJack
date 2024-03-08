#pragma once
using namespace std;


class hands {
private:
    char response;
    int otherCard;
    int hand;
public:
    char getResponse() {
        return response;
    }
    void setResponse(char resp) {
        response = resp;
    }
    int getOtherCard() {
        return otherCard;
    }
    void setOtherCard(int oth) {
        otherCard = oth;
    }
    int getHand() {
        return hand;
    }
    void setHand(int h) {
        hand = h;
    }
    void ResetVariables() {
        hand = 0;
        response = NULL;
        otherCard = 0;
    }
};
int ReturnCard() {
	return rand() % 11 + 1;
}

int GetResponse(char response) {
    if (response == 'y') {
        return ReturnCard();
    }
    return 0;
}


char AskForResponse() {
    char response;
    cout << endl << "Would you like to hit?" << endl;
    cin >> response;
    return response;
}