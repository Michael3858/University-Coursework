/* 程式開啟3.in為輸入(一行)
   3.out為輸出
   3.in的第一個字元為密碼。
   直接寫到3.out
   其餘每一個字元必須xor密碼後寫到3.out
   重複上一步驟直到檔案結束 */
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	
	in.open("3.in");
	out.open("3.out");
	
	int len;
	char v[1000];
	
	while(in >> v){
		len = strlen(v);
		for(int i = 1; i < len; i++){
			v[i] ^= v[0];
			out << v[i];
		}
	}
  	out << endl;
  	in.close();
  	out.close();
}
