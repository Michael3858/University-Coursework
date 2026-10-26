/* 請寫一個函數voidspaceStar(int space, int star);
   這個函數會輸出space個空白以及star個星星。並且跳行
   你的main function會讓使用者輸入一個數字，利用spaceStar函數畫出下圖，當使用者輸入4。
       *
      ***
     *****
    ******* */
#include<iostream>
using namespace std;

void spaceStar(int space, int star);
void spaceStar(int space, int star){
	for(int i = 1; i <= space; i++){
		cout << " ";
	}
	for(int j = 1; j <= star; j++){
		cout << "*";
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		spaceStar((n - 1 - i), (1 + 2 * i));
	}
	return 0;
}

