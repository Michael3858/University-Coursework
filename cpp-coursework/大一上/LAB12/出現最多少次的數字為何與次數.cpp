/* 讓使用者輸入一個s，為srand的seed
   產生10萬個1~50的亂數
   輸出出現最多次的數字為何與次數\n
   輸出出現最少次的數字為何與次數\n
   輸出範例
   32 2190\n
   6 1882\n */
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int s;
	cin >> s;
	srand(s);
	int num[51];
	for(int i = 1; i <= 50; i++){
		num[i] = 0;
	}
	for(int i = 0; i < 100000; i++){
		int x = rand() % 50 + 1;
		num[x]++;
	}
	int max = num[1];
	int min = num[1];
	int x, y;
	for(int i = 2; i <= 50; i++){
		if(max < num[i]){
			max = num[i];
			x = i;
		}
		if(min > num[i]){
			min = num[i];
			y = i;
		}
	}
	cout << x << " " << max << endl << y << " " << min << endl;
	return 0;
}
