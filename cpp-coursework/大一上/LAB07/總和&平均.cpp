/* 使用者會輸入5個整數，算出並顯示這5個數的總和。跳行；算出並顯示平均。跳行 */
#include<iostream>
using namespace std;
int main(){
	int n1, n2, n3, n4, n5;
	float sum, av;
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	sum = n1 + n2 + n3 + n4 + n5;
	av = sum / 5.0;
	cout << sum << endl << av << endl;
	return 0; 
}
