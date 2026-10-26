/* 描述
   classshuffleCards:publiccards 
   {
   public:
   shuffleCards(int seed);
   //Seed為srand的seed，呼叫52次shuffle();
   void shuffle();
   //產生1…totalCards間亂數2個，交換這兩個位置的牌
   intgetCard();
   //Override parentgetCard，如果沒牌，先呼叫newCards;
   再shuffle();52次，然後呼叫parentgetCard();回傳
   };
   程式一開始輸入一個y，y為seed。
   接著程式不斷輸入整數x
   如果x為0程式結束
   如果x> 0，使用getCard()產生x張牌，並出出該張牌。(格式如上一題)
   例如：Diamond J\n
   輸入
   程式一開始輸入一個y，y為seed。
   接著程式不斷輸入整數x
   如果x為0程式結束
   如果x> 0，使用getCard()產生x張牌，並出出該張牌。(格式如上一題)
   例如：Diamond J\n
   輸出
   程式一開始輸入一個y，y為seed。
   接著程式不斷輸入整數x  
   如果x為0程式結束
   如果x> 0，使用getCard()產生x張牌，並出出該張牌。(格式如上一題)
   例如：Diamond J\n */
#include<iostream>
#include<cstdlib>
using namespace std;
class cards{
	private:
  		int cardArray[52];
  		int totalCards;
	public: 
		cards();
		int getCard();
		int getCard(const int pos); 
		bool swapCards(const int a, const int b); 
		int remainCards();
		void newCards();
};
cards::cards(){
	totalCards = 52;
	for(int i = 0; i < 52; i++){
		cardArray[i] = i;
	}
}
int cards::getCard(){
	return cardArray[--totalCards];
}
int cards::getCard(const int pos){
	return cardArray[pos - 1];
}
bool cards::swapCards(const int a, const int b){
	if((a < 1 || a > totalCards) || (b < 1 || b > totalCards)){
		return false;
	}
	else{
		int tmp = cardArray[a - 1];
		cardArray[a - 1] = cardArray[b - 1];
		cardArray[b - 1] = tmp;
		return true;
	}
}
int cards::remainCards(){
	return totalCards;
}
void cards::newCards(){
	totalCards = 52;
	for(int i = 0; i < 52; i++){
		cardArray[i] = i;
	}
}
class shuffleCards:public cards{
	public:
  		shuffleCards(int seed); 
  		void shuffle(); 
  		int getCard(); 
};
shuffleCards::shuffleCards(int seed){
	srand(seed);
	for(int i = 0; i < 52; i++){
		shuffle();
	}
}
void shuffleCards::shuffle(){
	int n1 = rand() % remainCards() + 1;
	int n2 = rand() % remainCards() + 1;
	swapCards(n1, n2);
}
int shuffleCards::getCard(){
	if(remainCards() == 0){
		newCards();
		for(int i = 0; i < 52; i++){
			shuffle();
		}
	}
	return cards::getCard();
}
int main(){
	int y;
	cin >> y;
	shuffleCards s(y);
	int x;
	while(cin >> x){
		if(x == 0){
			break;
		}
		else if(x > 0){
			for(int i = 0; i < x; i++){
				int s1 = s.getCard();
				int a = s1 / 13;
				int b = s1 % 13;
				switch(a){
					case 0:
						cout << "Spare ";
						break;
					case 1:
						cout << "Heart ";
						break;
					case 2:
						cout << "Diamond ";
						break;
					case 3:
						cout << "Club ";
						break;
				}
				switch(b){
					case 0:
						cout << "A";
						break;
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
						cout << b + 1;
						break;
					case 10:
						cout << "J";
						break;
					case 11:
						cout << "Q";
						break;
					case 12:
						cout << "K";
						break;
				}
				cout << endl;
			}
		}
	}
}
