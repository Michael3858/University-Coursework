/* 你的程式會讓使用者輸入兩個整數s,與x，s為srand的seed，然後亂數函式產生x張牌。（不用處理重複）
   每一張牌
   產生1~4的亂數(1=Spade, 2=Heart, 3=Diamond,4=Club)
   產生1~13的數字( 11=J, 12=Q, 13=K, 1=A)
   印出你的牌，例如D10或是HJ
   每一張牌都需要跳行 */
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int s, x;
	cin >> s >> x;
	srand(s);
	for(int i = 1; i <= x; i++){
		int a, b;
		a = rand() % 4 + 1;
		b = rand() % 13 + 1;
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
	}
	return 0;
}
