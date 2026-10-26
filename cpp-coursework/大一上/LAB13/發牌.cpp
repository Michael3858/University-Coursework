/* 請寫一個撲克牌發排程式
   會將撲克牌洗牌後隨機發成四份
   印出每一份的牌
   輸入一個 seed s
   srand(s);
   印出四份牌，一份牌一行，牌空白間隔
   例如
   SA S5 SJ ….
   S3 SK …
   S2 S4 S6 S7 S9 SQ …
   S8 S10 …*/
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

const int NUMBER_OF_CARDS = 52;

void createCards(int cards[], int numberOfCards);
void createCards(int cards[], int numberOfCards){
	for(int i = 0; i < numberOfCards; i++){
		cards[i] = i;
	}
}

void shuffleCards(int cards[], int numberOfCards);
void shuffleCards(int cards[], int numberOfCards){
	int a, b, n;
	for(int j = 1; j <= numberOfCards; j++){
		a = rand() % 52;
		b = rand() % 52;
		n = cards[a];
		cards[a] = cards[b];
		cards[b] = n;
	}
}

int dealCard(int cards[], int &remainCards);
int dealCard(int cards[], int &remainCards){
	int returnCard;
	returnCard = cards[remainCards - 1];
	remainCards--;
	return returnCard;
}

void printCard(int x);
void printCard(int x){
	int cardFace, cardNumber;
	cardFace = x / 13 + 1;
	cardNumber = x % 13 + 1;
	switch(cardFace){
		case 1:
			cout << "S";
			break;
		case 2:
			cout << "H";
			break;
		case 3:
			cout << "D";
			break;
		case 4:
			cout << "C";
			break;
	}
	switch(cardNumber){
		case 1:
			cout << "A";
			break;
		case 2:
			cout << "2";
			break;
		case 3:
			cout << "3";
			break;
		case 4:
			cout << "4";
			break;
		case 5:
			cout << "5";
			break;
		case 6:
			cout << "6";
			break;
		case 7:
			cout << "7";
			break;
		case 8:
			cout << "8";
			break;
		case 9:
			cout << "9";
			break;
		case 10:
			cout << "10";
			break;
		case 11:
			cout << "J";
			break;
		case 12:
			cout << "Q";
			break;
		case 13:
			cout << "K";
			break;
	} 
	cout << " ";		  
}

int main(){
	int cards[NUMBER_OF_CARDS];
	int totalCards = NUMBER_OF_CARDS;
	int s;
	cin >> s;
	srand(s);
	createCards(cards, totalCards);
	shuffleCards(cards, totalCards);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 13; j++){
			int n = dealCard(cards, totalCards);
			printCard(n);
		}
		cout << endl;
	}
	return 0;
}
