/*請建立一個classpowerDate
  可以記錄(使用Private Data)
  年（西元）
  月
  日
  星期幾
  請寫一個constructor
  powerDate(const int y, const int m, const int d);
  設定y為年，m為月，d為日
  如果y, m, d設定的時期不合理（年份沒有介於1900~2021，月份沒有介於1~12等等），直接設定y=1900, m=1, d=1
  boolisLeap();回傳該年是否為閏年
  intgetWeek();回傳星期幾(0~6, 0為星期天）
  bool set( const int y, const int m, const int d);
  設定y為年，m為月，d為日如果y, m, d設定的時期不合理，直接設定y=1900, m=1, d=1
  intgetYear(); intgetMonth(); intgetDay(); Accessor得到年月日
  powerDatemyDate;
  cout<<“現在日期: “ <<myDate<<endl;
  能顯示現在日期: 2020-05-08L Friday
  其中L代表閏年，l代表沒閏年
  cin>>myDate;
  輸入三個整數y m d。如果設定不合理，同set()。
  myDate[n]將物件的日期+ n天
  注意，n也可以為負
  Hint:[] operator必須為Member operator overloading
  回傳值本題不重要，可以考慮為+n天候的myDate物件，或是任何東西。
  注：不用考慮＋n天超過2021年或1900年的狀況
  如: 2 1900 1 1 -1
  或: 2 2021 12 31 1 
  輸入
  產生一個物件d1，日期為1900-01-01
  系統不斷輸入一個控制數字a
  a=0
  程式結束
  a=1
  cin>> d1;cout<< d1 <<endl;
  a=2
  cin>>d1;cin>> n; d1[n];cout<< d1<<endl;*/
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class powerDate{
	private:
		int year;
		int month;
		int day;
		int week;
	public:
		powerDate(const int y, const int m, const int d);
		bool isLeap();
		bool set(const int y, const int m, const int d);
		int getWeek();
		int getYear();
		int getMonth();
		int getDay();
		void next();
		void back();
};
powerDate::powerDate(const int y, const int m, const int d){
	year = y;
	month = m;
	day = d;
	if(year > 2021 || year < 1900){
		year = 1900;
		month = 1;
		day = 1;
	}
	if(month > 12 || month < 1){
		year = 1900;
		month = 1;
		day = 1;
	}
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||month == 12){
		if(day < 1 || day > 31){
			year = 1900;
			month = 1;
			day = 1;
		}
	}
	if(month == 2){
		if((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0)){
			if(day < 1 || day > 29){
				year = 1900;
				month = 1;
				day = 1;
			}
		}
		else{
			if(day < 1 || day > 28){
				year = 1900;
				month = 1;
				day = 1;
			}
		}
	}
	if(month == 4 || month == 6 || month == 9 || month == 11){
		if(day < 1 || day > 30){
			year = 1900;
			month = 1;
			day = 1;
		}
	}
}
bool powerDate::isLeap(){
	if((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0)){
		return true;
	}
	else{
		return false;
	}
}
bool powerDate::set(const int y, const int m, const int d){
	year = y;
	month = m;
	day = d;
	int i = 1;
	if(year > 2021 || year < 1900){
		year = 1900;
		month = 1;
		day = 1;
		i = 0;
	}
	if(month > 12 || month < 1){
		year = 1900;
		month = 1;
		day = 1;
		i = 0;
	}
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||month == 12){
		if(day < 1 || day > 31){
			i = 0;
		}
	}
	if(month == 2){
		if((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0)){
			if(day < 1 || day > 29){
				i = 0;
			}
		}
		else{
			if(day < 1 || day > 28){
				i = 0;
			}
		}
	}
	if(month == 4 || month == 6 || month == 9 || month == 11){
		if(day < 1 || day > 30){
			i = 0;
		}
	}
	if(i == 0){
		return false;
	}
	else if(i == 1){
		return true;
	}
} 
int powerDate::getWeek(){
	int w, c, y, y1, m, d;
	y1 = year;
	d = day;
	m = month;
	if(m == 1 || m == 2){
		y1--;
		m += 12;
	}
	c = y1 / 100;
	y = y1 % 100;
	w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
	if(w > 0){
		w = w % 7;
	}
	else{
		w = (w % 7 + 7) % 7;
	}
	return w;
}
int powerDate::getYear(){
	return year;
}
int powerDate::getMonth(){
	return month;
}
int powerDate::getDay(){
	return day;
}
void powerDate::next(){
	day++;
	switch(month){
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10 :
		case 12 :
			if(day > 31){
				day -= 31;
				month++;
			}
			break;
		case 4 :
		case 6 :
		case 9 :
		case 11 :
			if(day > 30){
				day -= 30;
				month++;
			}
			break;
		case 2 :
			if(isLeap() == true){
				if(day > 29){
					day -= 29;
					month++;
				}
			}
			else{
				if(day > 28){
					day -= 28;
					month++;
				}
			}
			break;
	}
	if(month > 12){
		month -= 12;
		year++;
	}
}
void powerDate::back(){
	day--;
	if(day == 0){
		switch(month){
			case 1 :
				day = 31;
				month = 12;
				year--;
				break;
			case 2 :
			case 4 :
			case 6 :
			case 8 :
			case 9 :
			case 11 :
				day = 31;
				month--;
				break;
			case 3 :
				if(isLeap() == true){
					day = 29;
					month--;
				}
				else if(isLeap() == false){
					day = 28;
					month--;	
				}
				break;
			case 5 :
			case 7 :
			case 10 :
			case 12 :
				day = 30;
				month--;
				break;
		}
	}
}
int main(){
	int y, m, d, n;
	int a;
	while(cin >> a){
		if(a == 0){
			break;
		}
		cin >> y >> m >> d;
		powerDate myDate(y, m, d);
		if(a == 1){
			cout << myDate.getYear() << "-";
			if(myDate.getMonth() < 10){
				cout << "0" << myDate.getMonth() << "-";
			}
			else{
				cout << myDate.getMonth() << "-";
			}
			if(myDate.getDay() < 10){
				cout << "0" << myDate.getDay();
			}
			else{
				cout << myDate.getDay();
			}
			if(myDate.isLeap() == true){
				cout << "L" << " ";
			}
			else{
				cout << "l" << " ";
			}
			switch(myDate.getWeek()){
				case 0 :
					cout << "Sunday";
					break;
				case 1 :
					cout << "Monday";
					break;
				case 2 :
					cout << "Tuesday";
					break;
				case 3 :
					cout << "Wednesday";
					break;
				case 4 :
					cout << "Thursday";
					break;
				case 5 :
					cout << "Friday";
					break;
				case 6 :
					cout << "Saturday";
					break;
			}
			cout << endl;
		}
		if(a == 2){
			cin >> n;
			if(myDate.set(y, m, d) == false){
				powerDate myDate1(1900,1,1);
				if(n >= 0){
					for(int i = 0; i < n; i++){
						myDate1.next();
					}
				}
				else if(n < 0){
					n = -n;
					for(int i = 0; i < n; i++){
						myDate1.back();
					}
				}
				cout << myDate1.getYear() << "-";
				if(myDate1.getMonth() < 10){
					cout << "0" << myDate1.getMonth() << "-";
				}
				else{
					cout << myDate1.getMonth() << "-";
				}
				if(myDate1.getDay() < 10){
					cout << "0" << myDate1.getDay();
				}
				else{
					cout << myDate1.getDay();
				}
				if(myDate1.isLeap() == true){
					cout << "L" << " ";
				}
				else{
					cout << "l" << " ";
				}
				switch(myDate1.getWeek()){
					case 0 :
						cout << "Sunday";
						break;
					case 1 :
						cout << "Monday";
						break;
					case 2 :
						cout << "Tuesday";
						break;
					case 3 :
						cout << "Wednesday";
						break;
					case 4 :
						cout << "Thursday";
						break;
					case 5 :
						cout << "Friday";
						break;
					case 6 :
						cout << "Saturday";
						break;
				}
				cout << endl;
			}
			else if(myDate.set(y, m, d) == true){
				if(n >= 0){
					for(int i = 0; i < n; i++){
						myDate.next();
					}
				}
				else if(n < 0){
					n = -n;
					for(int i = 0; i < n; i++){
						myDate.back();
					}
				}
				cout << myDate.getYear() << "-";
				if(myDate.getMonth() < 10){
					cout << "0" << myDate.getMonth() << "-";
				}
				else{
					cout << myDate.getMonth() << "-";
				}
				if(myDate.getDay() < 10){
					cout << "0" << myDate.getDay();
				}
				else{
					cout << myDate.getDay();
				}
				if(myDate.isLeap() == true){
					cout << "L" << " ";
				}
				else{
					cout << "l" << " ";
				}
				switch(myDate.getWeek()){
					case 0 :
						cout << "Sunday";
						break;
					case 1 :
						cout << "Monday";
						break;
					case 2 :
						cout << "Tuesday";
						break;
					case 3 :
						cout << "Wednesday";
						break;
					case 4 :
						cout << "Thursday";
						break;
					case 5 :
						cout << "Friday";
						break;
					case 6 :
						cout << "Saturday";
						break;
				}
				cout << endl;
			}
		}
	}
}
