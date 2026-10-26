/* 描述
   假設有一個函數
   F(1) = 1, F(2) = 1
   F(n)=F(n-1) + F(n-2)for all n>= 1
   輸入
   程式不斷輸入數字x
   輸出
   x>=1輸出F(x)值\n
   x<1程式結束 */
#include<iostream>
using namespace std;
int f(int n){
	if(n == 1 || n == 2){
		return 1;	
	}
	else{
		return f(n - 1) + f(n - 2);
	}
}
int main(){
	int a;
	while(cin >> a){
		if(a < 1){
			break;
		}
		else{
			cout << f(a) << endl;
		}
	}
}

