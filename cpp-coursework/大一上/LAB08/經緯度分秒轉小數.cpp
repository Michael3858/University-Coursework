/* 寫一個程式要求使用者輸入緯度的度數，分，與秒（皆為整數）。60秒=1分，60分=1度
   輸出小數的度數，例如輸入13 51 19，輸出13.8553\n。 */
#include<iostream>
using namespace std;
int main(){
	float x, y, z, a;
	cin >> x >> y >> z;
	y = y / 60.0;
	z = z / 60 / 60.0;
	a = x + y + z;
	cout << a << endl;
	return 0; 
}
