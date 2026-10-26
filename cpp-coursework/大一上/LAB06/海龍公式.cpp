/* 輸入三角形3邊長，輸出三角形面積 */
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float a, b, c, s, A;
	cin >> a >> b >> c;
	s = (a + b + c) / 2.0;
	A = sqrt(s * (s - a) * (s - b) * (s - c));
	cout << A;
	return 0;
}
