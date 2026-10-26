/* 描述
   已知最大公因數
   GCD(a, b) = GCD( b,a%b);
   GCD(a,0)=a;
   輸入
   程式不斷輸入數字xy
   輸出
   輸出GCD(x, y)\nif x>0 && y >0
   x<=0 || y<=0結束 */
#include<iostream>
using namespace std;
int GCD(int a, int b){
	if(b != 0){
		return GCD(b, a % b);
	}
	else{
		return a;
	}
}
int main(){
	int x, y;
	while(cin >> x >> y){
		if(x <= 0 || y <= 0){
			break;
		}
		else{
			cout << GCD(x, y) << endl;
		}
	}
}

