/* 程式輸入兩個數字s, x
   s為srand的seed
   宣告一陣列int*ptr[1024];
   讓使用者輸入一整數x<= 1024
   亂數產生x個整數(-100~100)
   先利用ptr[i] = new int;產生一個動態int
   *(ptr[i])=亂數
   求出這x個整數的平均、標準差 */
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
	int s, x, *ptr[1024], sum = 0;
	cin >> s >> x;
	if (x > 1024){
        cout << "number can not larger than 1024." << endl;
        exit(1);
    }
	srand(s);
	for(int i = 0; i < x; i++){
		ptr[i] = new int;
		*ptr[i] = rand() % 201 - 100;
		sum += *ptr[i];
	}
	float av;
	av = sum * 1.0 / x;
	float a = 0;
	for(int i = 0; i < x; i++){
		a += pow(*ptr[i] - av, 2);
	}
	float sd;
	sd = sqrt(a / x);
	cout << av << endl << sd << endl;
}
