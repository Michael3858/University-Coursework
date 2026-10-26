/* 輸入兩個點座標, 輸出中點座標 */
#include<iostream>
using namespace std;
int main(){
	float x1, x2, x, y1, y2, y;
	cin >> x1 >> y1 >> x2 >> y2;
	x = (x1 + x2) / 2.0;
	y = (y1 + y2) / 2.0;
	cout << x << " " << y;
	return 0;
}
