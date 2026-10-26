/* 請設計一個class
   包含member data,時,分,秒 三個資料
   三個member function
   void input();cin三個數分別為時分秒
   如果0 >時>23將時修正為0
   如果0 >分>59將分修正為0
   如果0 >秒>59將秒修正為0
   void output();
   輸出hh:mm:ss\n例如03:09:27\n
   voidoutputSeconds();
   輸出 總共秒數sssss\n
   例如01:09:27，請輸出04167\n
   一次輸入(時分秒)
   兩個輸出(output, outputSeconds) */
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
class Time{
	public:
		void input();
		void output();
		void outputSecond();
		int h, m, s, sum;
};
int main(){
	Time t;
	t.input();
	t.output();
	t.outputSecond();	
}
void Time::input(){
	cin >> h >> m >> s;
	if(h < 0 || h > 23){
		h = 0;
	}
	if(m < 0 || m > 59){
		m = 0;
	}
	if(s < 0 || s > 59){
		s = 0;
	}
}
void Time::output(){
	if(h < 10){
		cout << "0" << h << ":";
	}
	else{
		cout << h << ":";
	}
	if(m < 10){
		cout << "0" << m << ":";
	}
	else{
		cout << m << ":";
	}
	if(s < 10){
		cout << "0" << s << endl;
	}
	else{
		cout << s << endl;
	}
}
void Time::outputSecond(){
	sum = h * 3600 + m * 60 + s;
	if(sum < 10){
		cout << "0000" << sum << endl;
	}
	else if(sum < 100){
		cout << "000" << sum << endl;
	}
	else if(sum < 1000){
		cout << "00" << sum << endl;
	}
	else if(sum < 10000){
		cout << "0" << sum << endl;
	}
	else{
		cout << sum << endl;
	}
}
