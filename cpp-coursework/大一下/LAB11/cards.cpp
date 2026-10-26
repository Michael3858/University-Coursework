/* 描述
   請撰寫一個classcards，撲克牌類別。定義如下：
   class cards //位置都是由1開始
   {
   public:
   cards(); //產生一副新牌，順序由1…52
   intgetCard(); //回傳陣列最後一張牌，並將最後一張牌刪除
   intgetCard(const int pos); //回傳pos位置的牌, for第三題
   boolswapCards( const int a, const int b ); //把a與b位置的牌交換
   intremainCards(); //回傳目前有幾張牌
   voidnewCards(); //不管還有沒有牌，直接產生一副新的牌
   private:
   intcardArray[52];
   inttotalCards;
   };
   Spare=0、Heart=1、Diamond=2、Club=3
   數字A=0、J=10、Q=11、K=12
   代表一張牌的數字x=花色*13+數字
   例如29。29/13=2…3 => Diamond 4
   第一張0。0 = 0*13 + 0
   最後一張51。51 = 3 * 13 + 12
   程式不斷輸入數字
   如果輸入的數字= 0，程式直接結束
   連續輸入兩個負數-a, -b，代表交換a, b位置的牌
   輸入1代表，呼叫getCard()，並出出該張牌。例如：Diamond J\n
   輸入2代表，輸出還有幾張牌。
   例如：數字\n
   輸入
   程式不斷輸入數字
   如果輸入的數字= 0，程式直接結束
   連續輸入兩個負數-a, -b，代表交換a, b位置的牌
   輸入1代表，呼叫getCard()，並出出該張牌。例如：Diamond J\n
   輸入2代表，輸出還有幾張牌。
   例如：數字\n
   輸出
   程式不斷輸入數字
   如果輸入的數字= 0，程式直接結束
   連續輸入兩個負數-a, -b，代表交換a, b位置的牌
   輸入1代表，呼叫getCard()，並出出該張牌。例如：Diamond J\n
   輸入2代表，輸出還有幾張牌。
   例如：數字\n */ 
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
int main(){
	cards c;
	int n;
	while(cin >> n){
		if(n == 0){
			break;
		}
		else if(n < 0){
			int n1;
			cin >> n1;
			n = abs(n);
			n1 = abs(n1);
			c.swapCards(n, n1);
		}
		else if(n == 1){
			int c1 = c.getCard();
			int a = c1 / 13;
			int b = c1 % 13;
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
		else if(n == 2){
			cout << c.remainCards() << endl;
		}
	}
}
