/* 設定同動態二維陣列
   [0][0],[0][1], [0][2],… [0][n-1]
   將內容從小到大排序
   依此類推
   [1][0], [1][1], [1][2],… [1][n-1]
   [m-1][0], [m-1][1], [m-1][2],…[m-1][n-1]
   輸出與動態二維陣列同 */
#include<iostream>
using namespace std;
int main(){
	int m, n;
	cin >> m >> n;
	int **a;
	a = new int *[m];
	for(int x = 0; x < m; x++){
		a[x] = new int [n];
	}
  	int s;
	for(int x = 0; x < m; x++){
		for(int y = 0; y < n; y++){
			cin >> a[x][y];
		}
      	for(int y = 0; y <= n; y++){
        	for(int z = 0; z < n - y - 1; z++){
            	if(a[x][z] > a[x][z + 1]){
                	s = a[x][z];
                  	a[x][z] = a[x][z + 1];
                  	a[x][z + 1] = s;
                }
            }
        }
	}
	int i, j;
	while(cin >> i >> j){
		if(i < 0 || j < 0){
			break;
		}
		else{
			cout << a[i][j] << endl;
		}
	}
}
