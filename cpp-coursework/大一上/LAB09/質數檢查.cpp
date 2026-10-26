/* 讓使用者輸入一個正整數
   輸出該數是否為質數
   例如輸入11 輸出1\n
   輸入4 輸出0\n */
#include<iostream>
using namespace std;
int main(){
	int n, i;
	cin >> n;
	if(n == 1){
		cout << "0";
	}
	for(i = 2; i < n; i++){
		if(n % i == 0){
			cout << "0";
			break;
		}
	}
	if(i == n){
		cout << "1";
	}
	cout << endl;
	return 0;
}
#include<iostream>
using namespace std;
int main(){
	int n, count = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(n % i == 0){
			count++;
		}
	}
	if(count == 2){
		cout << "質數" << endl;
	}
	else{
		cout << "非質數" << endl;
	}
	return 0;
} 
