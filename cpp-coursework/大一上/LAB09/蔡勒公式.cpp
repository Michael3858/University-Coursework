/* 讓使用者輸入西元 年 月 日
   輸出該天為星期幾？(0:星期日, 1 ~6星期1~6）
   例如輸入2019 12 5輸出4\n */
#include<iostream>
using namespace std;
int main(){
	int y1, m1, d1, w, c, y, m, d;
	cin >> y1 >> m1 >> d1;
	c = y1 / 100;
	y = y1 % 100;
	d = d1;
	if(m1 == 1 || m1 == 2){
		y--;
		m = m1 + 12;
	}
	else{
		m = m1;
	}
	if(y1 < 1582){
		w = y + y / 4 - c + 26 * (m + 1) / 10 + d + 4; 
	}
	else{
		w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
	}
	if(w > 0){
		w = w % 7;
		cout << w << endl;
	}
	else if(w < 0){
		w = (w % 7 + 7) % 7;
		cout << w << endl;
	}
	return 0;
}
