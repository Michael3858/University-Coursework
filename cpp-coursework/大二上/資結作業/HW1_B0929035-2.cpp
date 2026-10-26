#include<iostream>
#include<string>
using namespace std;
int main(){
	int x;
	cin >> x;
	cin.ignore();
	string name[x]; // 先拿來存輸入的字串 
	int lo[x]; // 空格前的長度 
	for(int i = 0; i < x; i++){
		lo[i] = 0;
	}
	int max1 = 0;
	for(int i = 0; i < x; i++){
		getline(cin, name[i]);
		if(max1 < name[i].size()){
			max1 = name[i].size(); // 找出最長的來設二維陣列 
		}
	}
	char **array;
	array = (char**)malloc(sizeof(int*)*x);
	for(int i = 0; i < x; i++){
		array[i] = (char*)malloc(sizeof(int)*max1);
	}
	const char *c;
	for(int i = 0; i < x; i++){
		c = name[i].data();
		for(int j = 0; j < name[i].size(); j++){
			array[i][j] = c[j]; // 把字串放入陣列 
		}
	}
	int max2 = 0;
	for(int i = 0; i < x; i++){
		int j = 0;
		while(array[i][j] != 32){ // 算出空格前的長度 
			lo[i]++;
			j++;
		}
		if(max2 < lo[i]){
			max2 = lo[i]; // 找出空格前最長的 
		}
	}
	for(int i = 0; i < x; i++){
		for(int j = 0; j < max2 - lo[i]; j++){
			cout << " ";
		}
		for(int j = 0; j < name[i].size(); j++){
			cout << array[i][j];
		}		
		cout << endl;
	}
}
