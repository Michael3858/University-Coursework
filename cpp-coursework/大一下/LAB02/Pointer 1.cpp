/* 程式輸入兩個正整數s與a
   s為srand的seed
   宣告一個pointer變數
   int*x;
   請寫一個迴圈、執行a次
   x=new int;
   讓*x=亂數1~100中的一個數
   如果*x為偶數，output *x
   delete x; //把剛剛產生的動態變數歸還系統 */
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int s, a, *x;
	cin >> s >> a;
	srand(s);
	for(int i = 0; i < a; i++){
		x = new int;
		*x = rand() % 100 + 1;
		if(*x % 2 == 0){
			cout << *x << endl;
		}
		delete x;
	}
	return 0;
}
