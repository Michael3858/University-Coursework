/* 請寫一個函數bool isPrime(int num);
   如果num是質數，回傳true，相反回傳false.
   請在main function中讓使用者輸入一正整數n。
   尋找一個質數x，使得x<=n，x為最大。然後輸出該質數x。 */
#include<iostream>
using namespace std;

bool isPrime(int num);
bool isPrime(int num){
	int i;
	if(num == 1){
		return false;
	}
	for(i = 2; i < num; i++){
		if(num % i == 0){
			return false;
			break;
		}
	}
	if(i == num){
		return true;
	}
}

int main(){
	int n;
	cin >> n;
	while(isPrime(n) == false){
		n--;
	}
	cout << n;
}
