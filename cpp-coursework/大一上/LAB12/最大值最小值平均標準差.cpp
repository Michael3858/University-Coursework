/* 讓使用者輸入s，s為srand的seed
   宣告一個int陣列有100個int
   利用亂數產生100~1000亂數100個
   計算這一百個亂數的
   最大值\n
   最小值\n
   平均\n
   標準差\n
   其中平均標準差為實數(double) */
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(){
	int s;
	cin >> s;
	srand(s);
	int num[100];
	for(int i = 0; i < 100; i++){
		num[i] = rand() % 901 + 100;
	}
	int max = num[0], min = num[0];
	for(int i = 1; i < 100; i++){
		if(num[i] > max){
			max = num[i];
		}
		if(num[i] < min){
			min = num[i];
		} 
	}
	double av, sum = 0;
	for(int i = 0; i < 100; i++){
		sum += num[i];
	}
	av = sum / 100.0;
	double sd, x = 0;
	for(int i = 0; i < 100; i++){
		x += pow((num[i] - av) , 2);
	}
	sd = sqrt(x / 100.0);
	cout << max << endl << min << endl << av << endl << sd << endl;
	return 0; 
} 
