/* 請開啟1.in
   讀取一個正整數
   找到最接近且小於該正整數的質數
   把這個質數輸出到1.out
   重複以上動作直到讀不到任何正整數為止 */
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num);
bool isPrime(int num){
	int i;
	if(num == 1){
		return false;
	}
    for (i = 2; i < num; i++){
        if (num % i == 0){
        	return false;
        	break;
		}
   }
   if(i == num){
   		return true;
   }
}

int number(int num);
int number(int num){
	int a = num - 1;  // 要小於該正整數 
    while(isPrime(a) == false){
    	a--;
	}
	return a;
}

int main(){
    ifstream inStream;
    ofstream outStream;

    inStream.open("1.in");
    outStream.open("1.out");

    int a, b;

    while(inStream >> a)
    {
        b = number(a);
        outStream << b << endl;
    }

    inStream.close();
    outStream.close();

    return 0;
}
