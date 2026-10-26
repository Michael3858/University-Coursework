/* 讓使用者輸入兩個正整數s與x
   s為srand的seed，x為幾張牌。
   產生x張紙牌 （需要印出來）
   D4\n
   CA\n
   CJ\n ….
   然後印出最大的牌與最小的牌
   所以，一共會印出x+2張（行）牌 */
#include<iostream>
#include<cstdlib>
using namespace std;

int issueCard();
int issueCard(){
	int x = rand() % 52 + 1;
	int a = (x - 1) / 13 + 1;
	int b = (x - 1) % 13 + 1;
	switch(a){
		case 1 :
			cout << "S";
			break;
		case 2 :
			cout << "H";
			break;
		case 3 :
			cout << "D";
			break;
		case 4 :
			cout << "C";
			break;
	}
	switch(b){
		case 1 :
			cout << "A";
			break;
		case 11 :
			cout << "J";
			break;
		case 12 :
			cout << "Q";
			break;
		case 13 :
			cout << "K";
			break;
		default :
			cout << b;
			break;
	}
	cout << endl;
	return x;
}

int cmpCard(int card1, int card2);
int cmpCard(int card1, int card2){
	if(card1 > card2){
		return 1;
	}
	else if(card1 < card2){
		return -1;
	}
	else{
		return 0;
	}
}

int main(){
	int s, x;
	cin >> s >> x;
	int card[x];
	srand(s);
	for(int i = 0; i < x; i++){
		card[i] = issueCard();
	}
	int max = card[0];
	int min = card[x - 1];
	for(int i = 0; i < x; i++){
		if(cmpCard(max, card[i]) == 1){
			continue;
		}
		else if(cmpCard(max, card[i] == -1)){
			max = card[i];
		}
	}
	for(int i = x; i > 0; i--){
		if(cmpCard(min, card[i - 1]) == 1){
			min = card[i - 1];
		}
		else if(cmpCard(min, card[i - 1]) == -1){
			continue;
		}
	}
	int a1 = (max - 1) / 13 + 1;
	int b1 = (max - 1) % 13 + 1;
	switch(a1){
		case 1 :
			cout << "S";
			break;
		case 2 :
			cout << "H";
			break;
		case 3 :
			cout << "D";
			break;
		case 4 :
			cout << "C";
			break;
	}
	switch(b1){
		case 1 :
			cout << "A";
			break;
		case 11 :
			cout << "J";
			break;
		case 12 :
			cout << "Q";
			break;
		case 13 :
			cout << "K";
			break;
		default :
			cout << b1;
			break;
	}
	cout << endl;
	int a2 = (min - 1) / 13 + 1;
	int b2 = (min - 1) % 13 + 1;
	switch(a2){
		case 1 :
			cout << "S";
			break;
		case 2 :
			cout << "H";
			break;
		case 3 :
			cout << "D";
			break;
		case 4 :
			cout << "C";
			break;
	}
	switch(b2){
		case 1 :
			cout << "A";
			break;
		case 11 :
			cout << "J";
			break;
		case 12 :
			cout << "Q";
			break;
		case 13 :
			cout << "K";
			break;
		default :
			cout << b2;
			break;
	}
	cout << endl;
	return 0;
}
