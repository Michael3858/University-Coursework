#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	cout << "Please enter MIPS instruction:" << endl;
	string s, arr[50];
	getline(cin, s);
	string ins = "";
	int i;
	for(i = 0; s[i] != ' '; i++){
		ins += s[i];
	}
	string str = s.substr(i + 1, s.length() - i - 1);
	stringstream ss(str);
	int n = 0;
	while(getline(ss, arr[n], ',')) n++;
	if((ins != "add") && (ins != "sub") && (ins != "lw") && (ins != "sw")){
		cout << "Instruction error!" << endl;
	}
	else if((ins == "add") || (ins == "sub")){
		int c = 2;
		while(true){
			if(c < 0){
				cout << "instruction: " << ins << endl;
				cout << "Source operands: " << arr[1] << "、" << arr[2] << endl;
				cout << "Destination operand: " << arr[0] << endl;
				break;
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				cout << "Register error!";
				break;
			}
			if(arr[c].substr(0, 1) != "$"){
				cout << "Register error!";
				break;
			}
			if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					cout << "Register error!";
					break;
				}
			}
			if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					cout << "Register error!";
					break;
				}
			}
			c--;
		}
	}
	else if((ins == "lw") || (ins == "sw")){
		int c = 1;
		string str1, str2;
		while(true){
			if(c < 0){
				if(ins == "lw"){
					cout << "instruction: " << ins << endl;
					cout << "Source operands: " << str2 << "、" << str1 << endl;
					cout << "Destination operand: " << arr[0] << endl;
					break;
				}
				else if(ins == "sw"){
					cout << "instruction: " << ins << endl;
					cout << "Source operands: " << str2 << "、" << arr[0] << endl;
					cout << "Destination operand: " << "Mem[" << str2 << " + " << str1 << "]" << endl;
					break;
				}
			}
			if(c == 1){
				string s1 = "", s2 = "";
				int j;
				for(j = 0; arr[1].substr(j, 1) != "("; j++){
					s1 += arr[1].substr(j, 1);
				}
				for(j = j + 1; arr[1].substr(j, 1) != ")"; j++){
					s2 += arr[1].substr(j, 1);
				}
				str1 = s1;
				str2 = s2;
				//cout << str1 << " " << str2 << endl;
				bool inte = true;
				for(int x = 0; x < s1.length(); x++){
					if(s1[x] < 48 || s1[x] > 57){
						inte = false;
					}
				}
				if(inte == false){
					cout << "Register error!";
					break;
				}
				int n1 = stoi(s1);
				if(n1 <= 0){
					cout << "Register error!";
					break;
				}
				if(s2.length() != 3){
					cout << "Register error!";
					break;
				}
				if(s2[0] != '$'){
					cout << "Register error!";
					break;
				}
				else if(s2.substr(1, 2) != "t0" && s2.substr(1, 2) != "t1" && s2.substr(1, 2) != "t2" && s2.substr(1, 2) != "t3" && s2.substr(1, 2) != "t4" && s2.substr(1, 2) != "t5" && s2.substr(1, 2) != "t6" && s2.substr(1, 2) != "t7" && s2.substr(1, 2) != "t8" && s2.substr(1, 2) != "t9" && s2.substr(1, 2) != "s0" && s2.substr(1, 2) != "s1" && s2.substr(1, 2) != "s2" && s2.substr(1, 2) != "s3" && s2.substr(1, 2) != "s4" && s2.substr(1, 2) != "s5" && s2.substr(1, 2) != "s6" && s2.substr(1, 2) != "s7"){
					cout << "Register error!";
					break;
				}
			}
			else if(c == 0){
				if(arr[c].length() > 3 || arr[c].length() < 2){
					cout << "Register error!";
					break;
				}
				if(arr[c].substr(0, 1) != "$"){
					cout << "Register error!";
					break;
				}
				if(arr[c].length() == 2){
					if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
						cout << "Register error!";
						break;
					}
				}
				if(arr[c].length() == 3){
					if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
						cout << "Register error!";
						break;
					}
				}
			}
			c--;
		}
    }
}
