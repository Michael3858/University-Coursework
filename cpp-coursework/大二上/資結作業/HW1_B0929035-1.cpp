#include<iostream>
#include<string>
#include<malloc.h>
using namespace std;
int main(){
	int v;
	cin >> v; // 決定用什麼宣告動態陣列 v=1:new v=2:melloc 
	if(v == 1){
		int x, y;
		cin >> x >> y; // x是輸入幾個字串 y是長度不可超過多少 
		char **array; // 宣告二維陣列 
		array = new char *[x];
		for(int i = 0; i < x; i++){
			array[i] = new char[y];
		}
		for(int a = 0; a < x; a++){ 
			for(int b = 0; b < y; b++){
				array[a][b] = ' ';
			}
		}
		cin.ignore(); // 把enter吃掉 
		for(int i = 0; i < x; i++){
			string name;
			getline(cin, name);
			while(name.size() > y){
				cout << "error!!" << endl;
				getline(cin, name);
			}
			for(int j = 0; j < name.size(); j++){
				array[i][j] = name[j];
			}
		}
		char *ans[1000] = {};
		for(int i = 0; i < x; i++){
			ans[i] = array[i]; // 指向每一個字串開頭的指標 
		} 
		for(int i = x - 1; i > 0; i--){ // bubble sort 
			for(int j = 0; j <= i - 1; j++){
				if(*ans[j] < *ans[j + 1]){
					char *c = ans[j];
					ans[j] = ans[j + 1];
					ans[j + 1] = c;	
				} 
			}
		}
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				cout << ans[i][j];
			}
			cout << endl;
		}	
		for(int i = 0; i < x; i++){ // 釋放動態陣列 
			delete [] array[x];
		}
		delete [] array;
	}
	else if(v == 2){
		int x, y;
		cin >> x >> y;
		char **array;
		array = (char**)malloc(sizeof(int*)*x);
		for(int i = 0; i < x; i++){
			array[i] = (char*)malloc(sizeof(int)*y);
		}
		for(int a = 0; a < x; a++){
			for(int b = 0; b < y; b++){
				array[a][b] = ' ';
			}
		}
		cin.ignore();
		for(int i = 0; i < x; i++){
			string name;
			getline(cin, name);
			for(int j = 0; j < name.size(); j++){
				array[i][j] = name[j];
			}
		}
		char *ans[1000] = {};
		for(int i = 0; i < x; i++){
			ans[i] = array[i];
		} 
		for(int i = x - 1; i > 0; i--){
			for(int j = 0; j <= i - 1; j++){
				if(*ans[j] < *ans[j + 1]){
					char *c = ans[j];
					ans[j] = ans[j + 1];
					ans[j + 1] = c;	
				} 
			}
		}
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				cout << ans[i][j];
			}
			cout << endl;
		}
		for(int i = 0; i < x; i++){
			free(array[i]);
		}
		free(array);
	}
	return 0;	
} 
