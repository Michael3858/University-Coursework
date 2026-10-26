/* 程式開啟4.in為輸入
   統計4.in裡面a~zA~Z 0~9最常出現的字元為誰
   Output該字元+\n（PS:寫到4.out）
   例如
   4.in裡面為I have an Apple iPhone.
   Output e\n
   其中.空白不列入統計，e出現三次最多 */
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	
	in.open("4.in");
	out.open("4.out");
	
	char v[1000], ch[62] = {0};
	int len, n;
	
	while(in >> v){
		len = strlen(v);
		for(int i = 0; i < len; i++){
			if(v[i] >= 'a' && v[i] <= 'z'){
				n = v[i] - 'a';
				ch[n]++;
			}
			else if(v[i] >= 'A' && v[i] <= 'Z'){
				n = v[i] - 'A' + 26;
				ch[n]++;
			}
			else if(v[i] >= '0' && v[i] <= '9'){
				n = v[i] - '0' + 52;
				ch[n]++;
			}
		}
	}
	int max = ch[0], m;
	for(int i = 0; i < 62; i++){
		if(ch[i] > max) {
			max = ch[i];
			m = i;
		}
	}
	char ans;
	if(m >= 0 && m <= 25){
		ans = 'a' + m;
		out << ans;
	}
	else if(m >= 26 && m <= 51){
		ans = 'A' + m - 26;
		out << ans;
	}
	else if(m >= 52 && m <= 61){
		ans = '0' + m - 52;
		out << ans;
	}
	in.close();
	out.close();
}
