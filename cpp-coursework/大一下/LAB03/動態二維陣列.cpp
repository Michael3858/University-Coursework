/* 輸入兩個數m, n
   產生一個動態二維陣列m*n
   接著輸入n * m個正整數
   將這些正整數依序放到二維陣列中
   [0][0],[0][1], [0][2],… [0][n-1]
   [1][0],[1][1], [1][2],… [1][n-1]
   …
   [m-1][0],[m-1][1], [m-1][2],… [m-1][n-1]
   接著程式會不斷輸入2個整數i, j
   如果兩個整數有一個為負數，程式結束
   輸出二維陣列[i][j] */
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int m, n;
	cin >> m >> n;
	int **array;
	array = new int *[m];
	for(int i = 0; i < m; i++){
		array[i] = new int [n];
	}
	for(int a = 0; a < m; a++){
		for(int b = 0; b < n; b++){
			cin >> array[a][b];
		}
	}
	int i, j;
	while(cin >> i >> j){
		if(i < 0 || j < 0){
			break;
		}
		else{
			cout << array[i][j] << endl;
		}
	}
	for(int x = 0; x < m; x++){
		delete [] array[x];
	}
	delete [] array;
}
