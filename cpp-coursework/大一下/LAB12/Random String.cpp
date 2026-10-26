/* 描述
   請建立一個classmyRandString
   提供一個constructormyRandString(int size);與member function void generate();
   會產生一個亂數字串，長度為亂數1~size，內容每個字元都是亂數A~Z。
   並且利用Operatoroverloading <<
   myRandString x(10); x.generate();
   讓cout << “亂數字串：”<<x <<endl;
   顯示亂數字串：ADJWQJR.如果x的亂數字串是ADJWQJR。
   程式輸入3個數字
   第一個輸入的數字是seed
   第二個輸入的數字是size
   第三個數字為x(x> 0)
   x，代表重新亂數(generate)幾次，並把每一次亂數的結果輸出
   Ex.輸入：105 3\n 
   輸出：ASDFG\n ZXCVB\n QWERT\n(這邊先亂打)
   輸入
   程式輸入3個數字
   第一個輸入的數字是seed
   第二個輸入的數字是size
   第三個數字為x(x> 0)
   x，代表重新亂數(generate)幾次，並把每一次亂數的結果輸出
   Ex.輸入：105 3\n
   輸出：ASDFG\n ZXCVB\n QWERT\n(這邊先亂打)
   輸出
   程式輸入3個數字
   第一個輸入的數字是seed
   第二個輸入的數字是size
   第三個數字為x(x> 0)
   x，代表重新亂數(generate)幾次，並把每一次亂數的結果輸出
   Ex.輸入：105 3\n
   輸出：ASDFG\n ZXCVB\n QWERT\n(這邊先亂打) */
#include<iostream>
#include<cstdlib>
using namespace std;
class myRandString{
	private:
		int s, ss;
		char *str;
	public:
		myRandString(int size);
		void generate();
		friend ostream &operator <<(ostream &os, myRandString &x);
};
myRandString::myRandString(int size){
	s = size;
	str = new char[size];
}
void myRandString::generate(){
	ss = rand() % s + 1;
	for(int i = 0; i < ss; i++){
   		str[i] = 'A' + rand() % 26;
	}
}
ostream &operator<<(ostream &os, myRandString &x){
	for(int i = 0; i < x.ss; i++){
		os << x.str[i];
	}
	os << endl;
	return os;
}
int main(){
	int s;
	cin >> s;
	srand(s);
	int size;
	cin >> size;
	myRandString m(size);
	int x;
	cin >> x;
	for(int i = 0; i < x; i++){
		m.generate();
		cout << m;
	}
}
