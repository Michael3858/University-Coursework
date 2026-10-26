/* 寫一個程式會將攝氏溫度轉為華氏溫度
   輸入為一個實數攝氏溫度
   輸出為華氏溫度小數＋ 跳行 */
#include<iostream>
using namespace std;
int main(){
	float c, f;
	cin >> c;
	f = 9 * c / 5 + 32;
	cout << f << "\n";
	return 0;
}
