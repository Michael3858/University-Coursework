/* 讓使用者輸入生日(月日），輸出使用者的星座為何？ */
#include<iostream>
using namespace std;
int main(){
	int m, d;
	cin >> m >> d;
	if((m == 1 && d >= 21) || (m == 2 && d <= 19)){
		cout << "Aquarius" << endl;
	}
	else if((m == 2 && d >= 20) || (m == 3 && d <= 20)){
		cout << "Pisces" << endl;
	}
	else if((m == 3 && d >= 21) || (m == 4 && d <= 19)){
		cout << "Aries" << endl;
	}
	else if((m == 4 && d >= 20) || (m == 5 && d <= 20)){
		cout << "Taurus" << endl;
	}
	else if((m == 5 && d >= 21) || (m == 6 && d <= 21)){
		cout << "Gemini" << endl;
	}
	else if((m == 6 && d >= 22) || (m == 7 && d <= 22)){
		cout << "Cancer" << endl;
	}
	else if((m == 7 && d >= 23) || (m == 8 && d <= 22)){
		cout << "Leo" << endl;
	}
	else if((m == 8 && d >= 23) || (m == 9 && d <= 22)){
		cout << "Virgo" << endl;
	}
	else if((m == 9 && d >= 23) || (m == 10 && d <= 23)){
		cout << "Libra" << endl;
	}
	else if((m == 10 && d >= 24) || (m == 11 && d <= 21)){
		cout << "Scorpio" << endl;
	}
	else if((m == 11 && d >= 22) || (m == 12 && d <= 20)){
		cout << "Sagittarius" << endl;
	}
	else if((m == 12 && d >= 21) || (m == 1 && d <= 20)){
		cout << "Capricorn" << endl;
	}
}
