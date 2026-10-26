/* 輸入一個數字x
   y=1+2+3+4+…
   y>x≧y-i
   輸出i\n */
#include<iostream>
using namespace std;
int main(){
	int x;
	cin >> x;
	int y = 1, i;
	for(i = 2; y <= x; i++){
		y += i;
	}
	i--;
	cout << i << endl;
}
