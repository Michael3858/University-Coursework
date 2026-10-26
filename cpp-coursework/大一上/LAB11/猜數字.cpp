/*選擇一個四位數字讓對方猜謎
四個位數的數字必須不同
例如: 0941
對方猜的數字，如果數字正確位置不對1B，如果數字跟位置都正確1A
例如5904: 1A 2B
當4A遊戲結束 */
#include<iostream>
using namespace std;

bool checkNumber(int x);
bool checkNumber(int x){
	int x1, x2, x3, x4;
	x1 = x / 1000;
	x2 = (x / 100) % 10;
	x3 = (x / 10) % 10;
	x4 = x % 10;
	if(x1 == x2 || x1 == x3 || x1 == x4 || x2 == x3 || x2 == x4 || x3 == x4){
		return false;
	}
	else{
		return true;
	}
}

int generateNumber();
int generateNumber(){
	int n = rand() % 9754 + 123;
	while(checkNumber(n) == false){
		n = rand() % 9754 + 123;
	}
	return n;
}

bool cmpNumber(int x, int y);
bool cmpNumber(int x, int y){
	int x1, x2, x3, x4, y1, y2, y3, y4;
	int i = 0, j = 0;
	x1 = x / 1000;
	x2 = (x / 100) % 10;
	x3 = (x / 10) % 10;
	x4 = x % 10;
	y1 = y / 1000;
	y2 = (y / 100) % 10;
	y3 = (y / 10) % 10;
	y4 = y % 10;
	if(x1 == y2 || x1 == y3 || x1 == y4){
		j++;
	}
	else if(x1 == y1){
		i++;
	}
	if(x2 == y1 || x2 == y3 || x2 == y4){
		j++;
	}
	else if(x2 == y2){
		i++;
	}
	if(x3 == y1 || x3 == y2 || x3 == y4){
		j++;
	}
	else if(x3 == y3){
		i++;
	}
	if(x4 == y1 || x4 == y2 || x4 == y3){
		j++;
	}
	else if(x4 == y4){
		i++;
	}
	cout << i << "A" << j << "B" << endl;
	if(i == 4){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int s, a;
	cin >> s;
	srand(s);
	int x = generateNumber();
	while(cin >> a){
		if(a == 0){
			cout << x;
			break;
		}
		else if(cmpNumber(a, x) == true){
			break;
		}
	}
}	
