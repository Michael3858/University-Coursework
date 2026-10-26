/* 輸入為1.in檔案，檔案大小為n
   1.in內容為英文文章
   利用動態陣列產生一個n的char陣列
   將1.in全部內容讀到該陣列
   srand(100);//固定使用100為seed
   產生50個1~n的亂數
   將每一個亂數位置的字元輸出到1.out
   如果亂數是x,請輸出SOME_ARRAY[x-1] */
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	
	in.open("1.in");
	out.open("1.out");
	
	int begin, end, n;
	ifstream myfile("1.in");
	begin = myfile.tellg();
	myfile.seekg(0, ios::end);
	end = myfile.tellg();
	myfile.close();
	n = end - begin;
	
	char *ch;
	ch = new char[n];
	
	for(int i = 0; i < n; i++){
		in.get(ch[i]);
	}
	
	int a;
	srand(100);
	
	for(int i = 0; i < 50; i++){
		a = rand() % n + 1;
		out << ch[a - 1];
	}
	
	in.close();
	out.close();
	
	delete [] ch;
}
