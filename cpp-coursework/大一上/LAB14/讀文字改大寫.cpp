/* 請開啟3.in
   不斷的讀取1個char直到讀取到的char為‘\n’就停止。
   把讀取到的char小寫換成大寫，大寫不要管。
   將結果輸出到3.out
   3.out最後加上\n */
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	ifstream inStream;
	ofstream outStream;
	
	inStream.open("3.in");
	outStream.open("3.out");
	
	char ch[100];
	int len;
	while(inStream >> ch){
		len = strlen(ch);
		for(int i = 0; i < len; i++){
			if(ch[i] <= 'z' && ch[i] >= 'a'){
				ch[i] = ch[i] - 'a' + 'A';
			}
			outStream << ch[i];
		}
	}
	outStream << endl;
	
	inStream.close();
	outStream.close();
}
