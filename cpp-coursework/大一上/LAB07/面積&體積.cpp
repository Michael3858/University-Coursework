/* 使用者輸入一整數x
   算出正三角形邊長為x的面積
   算出正方形邊長為x的面積
   算出圓形半徑為x的面積
   算出正方體邊長為x的體積
   算出圓柱體半徑x高x的體積 */
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x;
	cin >> x;
	float a, b, c, d, e;
	a = pow(x , 2) * sqrt(3) / 4.0;
	b = pow(x , 2);
	c = pow(x , 2) * 3.14;
	d = x * x * x;
	e = c * x;
	cout << a << endl << b << endl << c << endl << d << endl << e;
	return 0;
}
