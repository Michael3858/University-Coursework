/* 讓使用者輸入1個正整數n(n>=1)
   如果n = 4顯示
   ****\n
    ****\n
     ****\n
      ****\n */
#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			cout << " ";	
		}
		for(int p = 1; p <= n; p++){
			cout << "*";
		}
		cout << endl; 
	}
	return 0;
}
