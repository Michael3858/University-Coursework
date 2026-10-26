/* 一個物體的初速為v0, 末速為v, 移動時間為t, 請問位移為多少? */
#include<iostream>
using namespace std;
int main(){
	int v0, v, t, s;
	cin >> v0 >> v >> t;
	s = (v0 + v) * t / 2;
	cout << s; 
	return 0;
} 
