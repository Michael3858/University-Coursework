/* 請開啟2.in
   讀取每一行文字
   在文字前加上這一行的長度，然後寫到2.out
   重複以上動作直到讀不到任何正文字為止
   一行長度不會超過70，請參考strlen函數。 */
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	ifstream inStream;
	ofstream outStream;
	
	inStream.open("2.in");
	outStream.open("2.out");
	
	char ch[70];
	int len;
	while(inStream >> ch){
		len = strlen(ch);
		outStream << len << ch << endl;
	}
	
	inStream.close();
	outStream.close();
}
