/* 輸入身高跟體重，計算出BMI */
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float h, w, b;
	cin >> h >> w;
	b = w / pow(h / 100.0 , 2);
	cout << b;
	return 0;
} 
