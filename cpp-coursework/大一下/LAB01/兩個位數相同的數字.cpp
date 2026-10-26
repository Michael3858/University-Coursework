/* 輸入seed s
   Random1~999數字1000個
   例如：
   191
   333
   5(=005)
   400
   印出所有 有任兩個位數相同的數字 */
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int s;
  	cin >> s;
	srand(s);
	int num[1000];
	int n1, n2, n3;
	for(int i = 0; i < 1000; i++){
		num[i] = rand() % 999 + 1;
		n1 = num[i] / 100;
		n2 = num[i] % 100 / 10;
		n3 = num[i] % 10;
		if(n1 == n2 || n1 == n3 || n2 == n3){
			cout << num[i] << endl;
		}
	}
}
