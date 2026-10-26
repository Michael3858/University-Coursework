#include<iostream>
using namespace std;
void sPermu(char *str, int s, int n){
	char c;
	if(s == n - 1){
		cout << str << endl;
		return;
	}
	for(int i = s; i < n; i++){
		c = str[i];
		for(int j = i; j > s; j--){
			str[j] = str[j - 1];
		}
		str[s] = c;
		sPermu(str, s + 1, n);
		c = str[s];
		for(int j = s; j < i; j++){
			str[j] = str[j + 1];
		}
		str[i] = c;
	}
}
int main(){
	char *str, c;
	int n;
	cin >> n;
	str = new char[n + 1];
	for(int i = 0; i < n; i++){
		cin >> str[i];
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(str[j] > str[j + 1]){
				c = str[j];
				str[j] = str[j + 1];
				str[j + 1] = c;
			}
		}
	}
	str[n] = '\0';
	sPermu(str, 0, n);
} 
