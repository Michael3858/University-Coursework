/* 請開啟3.in
   不斷的讀取1個char直到讀取到的char為‘\n’就停止。
   把讀取到的字元XOR ‘a’（怎麼XOR請自行Google)
   將結果輸出到4.out 
   最後加上\n */
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	ifstream inStream;
	ofstream outStream;
	
	inStream.open("3.in");
	outStream.open("4.out");
	
	char ch[100];
	int len;
	while(inStream >> ch){
		len = strlen(ch);
		for(int i = 0; i < len; i++){
			ch[i] ^= 'a';
			outStream << ch[i];
		}
	}
	outStream << endl;
  
	inStream.close();
	outStream.close();
}
