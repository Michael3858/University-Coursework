#include<iostream>
#include<string>
#include<sstream>
#include<bitset>
#include<algorithm>
using namespace std;
int toNumber(string s);
int toNumber(string s){
	s.erase(std::remove(s.begin(), s.end(), '$'), s.end());
	if(s == "v0") s = "2";
	else if(s == "v1") s = "3";
	else if(s == "a0") s = "4";
	else if(s == "a1") s = "5";
	else if(s == "a2") s = "6";
	else if(s == "a3") s = "7";
	else if(s == "t0") s = "8";
	else if(s == "t1") s = "9";
	else if(s == "t2") s = "10";
	else if(s == "t3") s = "11";
	else if(s == "t4") s = "12";
	else if(s == "t5") s = "13";
	else if(s == "t6") s = "14";
	else if(s == "t7") s = "15";
	else if(s == "s0") s = "16";
	else if(s == "s1") s = "17";
	else if(s == "s2") s = "18";
	else if(s == "s3") s = "19";
	else if(s == "s4") s = "20";
	else if(s == "s5") s = "21";
	else if(s == "s6") s = "22";
	else if(s == "s7") s = "23";
	else if(s == "t8") s = "24";	
	else if(s == "t9") s = "25";
	else if(s == "k0") s = "26";	
	else if(s == "k1") s = "27";
	else if(s == "sp") s = "29";	
	else if(s == "ra") s = "31";
	int n = stoi(s);
	return n;
}
bool isNumber(const string& s);
bool isNumber(const string& s){
	for(char const &c : s){
		if(std::isdigit(c) == 0 && c != '-'){
			return false;
		}
	}
	return true;
}
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
	if(ins == "add"){
		int c = 2;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = 00000" << endl;
					cout << "function code = 100000" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "addi"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(isNumber(arr[2]) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(isNumber(arr[2]) == true){
					int num = stoi(arr[2]);
					if(num > 32767 || num < -32768){
						idx = s.find("Immediate value error!\n");
						if(idx == string::npos){
							s += "Immediate value error!\n";
							w += 1;
						}
					}
				}
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source = " << arr[1] << endl;
					cout << "immediate value = " << arr[2] << endl;
					cout << "opcode = 001000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[0]));
					cout << "rt = " << bs2 << endl;
					bitset<16> bs3(toNumber(arr[2]));
					cout << "immediate value = " << bs3 << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "addu"){
		int c = 2;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = 00000" << endl;
					cout << "function code = 100001" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "addiu"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(isNumber(arr[2]) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(isNumber(arr[2]) == true){
					int num = stoi(arr[2]);
					if(num > 32767 || num < -32768){
						idx = s.find("Immediate value error!\n");
						if(idx == string::npos){
							s += "Immediate value error!\n";
							w += 1;
						}
					}
				}
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source = " << arr[1] << endl;
					cout << "immediate value = " << arr[2] << endl;
					cout << "opcode = 001001" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[0]));
					cout << "rt = " << bs2 << endl;
					bitset<16> bs3(toNumber(arr[2]));
					cout << "immediate value = " << bs3 << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "sub"){
		int c = 2;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = 00000" << endl;
					cout << "function code = 100010" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "sll"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(isNumber(arr[2]) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(isNumber(arr[2]) == true){
					int num = stoi(arr[2]);
					if(num > 31 || num < 0){
						idx = s.find("Shift amount error!\n");
						if(idx == string::npos){
							s += "Shift amount error!\n";
							w += 1;
						}
					}
				}
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					cout << "rs = 00000" << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = " << bs2 << endl;
					cout << "function code = 000000" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "srl"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(isNumber(arr[2]) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(isNumber(arr[2]) == true){
					int num = stoi(arr[2]);
					if(num > 31 || num < 0){
						idx = s.find("Shift amount error!\n");
						if(idx == string::npos){
							s += "Shift amount error!\n";
							w += 1;
						}
					}
				}
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					cout << "rs = 00000 " << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = " << bs2 << endl;
					cout << "function code = 000010" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "and"){
		int c = 2;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = 00000" << endl;
					cout << "function code = 100100" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "or"){
		int c = 2;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = 00000" << endl;
					cout << "function code = 100101" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "nor"){
		int c = 2;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = 00000" << endl;
					cout << "function code = 100111" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "lw"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string str1, str2;
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "memory address = " << "MEM[" << str2 << " + " << str1 << "]" << endl;
					cout << "source = " << str2 << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "opcode = 100011" << endl;
					bitset<5> bs1(toNumber(str2));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[0]));
					cout << "rt = " << bs2 << endl;
					bitset<16> bs3(toNumber(str1));
					cout << "immediate value = " << bs3 << endl;  
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
				if(isNumber(s1) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				int n1 = stoi(s1);
				if(n1 < -32768 || n1 > 32767 || n1 % 4 != 0){
					idx = s.find("Immediate value error!\n");
					if(idx == string::npos){
						s += "Immediate value error!\n";
						w += 1;
					}
				}
				if(s2.length() != 3){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				if(s2[0] != '$'){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(s2.substr(1, 2) != "t0" && s2.substr(1, 2) != "t1" && s2.substr(1, 2) != "t2" && s2.substr(1, 2) != "t3" && s2.substr(1, 2) != "t4" && s2.substr(1, 2) != "t5" && s2.substr(1, 2) != "t6" && s2.substr(1, 2) != "t7" && s2.substr(1, 2) != "t8" && s2.substr(1, 2) != "t9" && s2.substr(1, 2) != "s0" && s2.substr(1, 2) != "s1" && s2.substr(1, 2) != "s2" && s2.substr(1, 2) != "s3" && s2.substr(1, 2) != "s4" && s2.substr(1, 2) != "s5" && s2.substr(1, 2) != "s6" && s2.substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(c == 0){
				if(arr[c].length() > 3 || arr[c].length() < 2){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				if(arr[c].substr(0, 1) != "$"){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				if(arr[c].length() == 2){
					if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
						idx = s.find("Register error!\n");
						if(idx == string::npos){
							s += "Register error!\n";
							w += 1;
						}
					}
				}
				if(arr[c].length() == 3){
					if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
						idx = s.find("Register error!\n");
						if(idx == string::npos){
							s += "Register error!\n";
							w += 1;
						}
					}
				}
			}
			c--;
		}
	}
	if(ins == "sw"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string str1, str2;
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "memory address = " << "MEM[" << str2 << " + " << str1 << "]" << endl;
					cout << "source = " << str2 << endl;
					cout << "destination = " << "MEM[" << str2 << " + " << str1 << "]" << endl;
					cout << "opcode = 101011" << endl;
					bitset<5> bs1(toNumber(str2));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[0]));
					cout << "rt = " << bs2 << endl;
					bitset<16> bs3(toNumber(str1));
					cout << "immediate value = " << bs3 << endl;  
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
				if(isNumber(s1) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				int n1 = stoi(s1);
				if(n1 < -32768 || n1 > 32767 || n1 % 4 != 0){
					idx = s.find("Immediate value error!\n");
					if(idx == string::npos){
						s += "Immediate value error!\n";
						w += 1;
					}
				}
				if(s2.length() != 3){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				if(s2[0] != '$'){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(s2.substr(1, 2) != "t0" && s2.substr(1, 2) != "t1" && s2.substr(1, 2) != "t2" && s2.substr(1, 2) != "t3" && s2.substr(1, 2) != "t4" && s2.substr(1, 2) != "t5" && s2.substr(1, 2) != "t6" && s2.substr(1, 2) != "t7" && s2.substr(1, 2) != "t8" && s2.substr(1, 2) != "t9" && s2.substr(1, 2) != "s0" && s2.substr(1, 2) != "s1" && s2.substr(1, 2) != "s2" && s2.substr(1, 2) != "s3" && s2.substr(1, 2) != "s4" && s2.substr(1, 2) != "s5" && s2.substr(1, 2) != "s6" && s2.substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(c == 0){
				if(arr[c].length() > 3 || arr[c].length() < 2){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				if(arr[c].substr(0, 1) != "$"){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				if(arr[c].length() == 2){
					if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
						idx = s.find("Register error!\n");
						if(idx == string::npos){
							s += "Register error!\n";
							w += 1;
						}
					}
				}
				if(arr[c].length() == 3){
					if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
						idx = s.find("Register error!\n");
						if(idx == string::npos){
							s += "Register error!\n";
							w += 1;
						}
					}
				}
			}
			c--;
		}
	}
	if(ins == "beq"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(isNumber(arr[2]) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(isNumber(arr[2]) == true){
					int num = stoi(arr[2]);
					if(num > 32767 || num < -32768){
						idx = s.find("Address error!\n");
						if(idx == string::npos){
							s += "Address error!\n";
							w += 1;
						}
					}
				}
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "source 1 = " << arr[0] << endl;
					cout << "source 2 = " << arr[1] << endl;
					cout << "address = " << arr[2] << endl;
					cout << "opcode = 000100" << endl;
					bitset<5> bs1(toNumber(arr[0]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[1]));
					cout << "rt = " << bs2 << endl;
					bitset<16> bs3(toNumber(arr[2]));
					cout << "address = " << bs3 << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "bne"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(isNumber(arr[2]) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(isNumber(arr[2]) == true){
					int num = stoi(arr[2]);
					if(num > 32767 || num < -32768){
						idx = s.find("Address error!\n");
						if(idx == string::npos){
							s += "Address error!\n";
							w += 1;
						}
					}
				}
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "source 1 = " << arr[0] << endl;
					cout << "source 2 = " << arr[1] << endl;
					cout << "address = " << arr[2] << endl;
					cout << "opcode = 000101" << endl;
					bitset<5> bs1(toNumber(arr[0]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[1]));
					cout << "rt = " << bs2 << endl;
					bitset<16> bs3(toNumber(arr[2]));
					cout << "address = " << bs3 << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "slt"){
		int c = 2;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = 00000" << endl;
					cout << "function code = 101010" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "slti"){
		int c = 1;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(isNumber(arr[2]) == false){
					idx = s.find("Format error!\n");
					if(idx == string::npos){
						s += "Format error!\n";
						w += 1;
					}
				}
				else if(isNumber(arr[2]) == true){
					int num = stoi(arr[2]);
					if(num > 32767 || num < -32768){
						idx = s.find("Immediate value error!\n");
						if(idx == string::npos){
							s += "Immediate value error!\n";
							w += 1;
						}
					}
				}
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source = " << arr[1] << endl;
					cout << "immediate value = " << arr[2] << endl;
					cout << "opcode = 001010" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[0]));
					cout << "rt = " << bs2 << endl;
					bitset<16> bs3(toNumber(arr[2]));
					cout << "immediate value = " << bs3 << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "sltu"){
		int c = 2;
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		while(true){
			if(c < 0){
				if(w > 0){
					cout << s;
					break;
				}
				else if(w == 0){
					cout << "operation = " << ins << endl;
					cout << "destination = " << arr[0] << endl;
					cout << "source 1 = " << arr[1] << endl;
					cout << "source 2 = " << arr[2] << endl;
					cout << "opcode = 000000" << endl;
					bitset<5> bs1(toNumber(arr[1]));
					cout << "rs = " << bs1 << endl;
					bitset<5> bs2(toNumber(arr[2]));
					cout << "rt = " << bs2 << endl;
					bitset<5> bs3(toNumber(arr[0]));
					cout << "rd = " << bs3 << endl;
					cout << "shamt = 00000" << endl;
					cout << "function code = 101011" << endl;  
					break;
				}
			}
			if(arr[c].length() > 3 || arr[c].length() < 2){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].substr(0, 1) != "$"){
				idx = s.find("Format error!\n");
				if(idx == string::npos){
					s += "Format error!\n";
					w += 1;
				}
			}
			else if(arr[c].length() == 2){
				if(arr[c].substr(1, 1) != "0" && arr[c].substr(1, 1) != "1" && arr[c].substr(1, 1) != "2" && arr[c].substr(1, 1) != "3" && arr[c].substr(1, 1) != "4" && arr[c].substr(1, 1) != "5" && arr[c].substr(1, 1) != "6" && arr[c].substr(1, 1) != "7" && arr[c].substr(1, 1) != "8" && arr[c].substr(1, 1) != "9"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			else if(arr[c].length() == 3){
				if(arr[c].substr(1, 2) != "t0" && arr[c].substr(1, 2) != "t1" && arr[c].substr(1, 2) != "t2" && arr[c].substr(1, 2) != "t3" && arr[c].substr(1, 2) != "t4" && arr[c].substr(1, 2) != "t5" && arr[c].substr(1, 2) != "t6" && arr[c].substr(1, 2) != "t7" && arr[c].substr(1, 2) != "t8" && arr[c].substr(1, 2) != "t9" && arr[c].substr(1, 2) != "s0" && arr[c].substr(1, 2) != "s1" && arr[c].substr(1, 2) != "s2" && arr[c].substr(1, 2) != "s3" && arr[c].substr(1, 2) != "s4" && arr[c].substr(1, 2) != "s5" && arr[c].substr(1, 2) != "s6" && arr[c].substr(1, 2) != "s7" && arr[c].substr(1, 2) != "v0" && arr[c].substr(1, 2) != "v1" && arr[c].substr(1, 2) != "a0" && arr[c].substr(1, 2) != "a1" && arr[c].substr(1, 2) != "a2" && arr[c].substr(1, 2) != "a3" && arr[c].substr(1, 2) != "k0" && arr[c].substr(1, 2) != "k1" && arr[c].substr(1, 2) != "sp" && arr[c].substr(1, 2) != "ra" && arr[c].substr(1, 2) != "10" && arr[c].substr(1, 2) != "11" && arr[c].substr(1, 2) != "12" && arr[c].substr(1, 2) != "13" && arr[c].substr(1, 2) != "14" && arr[c].substr(1, 2) != "15" && arr[c].substr(1, 2) != "16" && arr[c].substr(1, 2) != "17" && arr[c].substr(1, 2) != "18" && arr[c].substr(1, 2) != "19" && arr[c].substr(1, 2) != "20" && arr[c].substr(1, 2) != "21" && arr[c].substr(1, 2) != "22" && arr[c].substr(1, 2) != "23" && arr[c].substr(1, 2) != "24" && arr[c].substr(1, 2) != "25" && arr[c].substr(1, 2) != "26" && arr[c].substr(1, 2) != "27" && arr[c].substr(1, 2) != "28" && arr[c].substr(1, 2) != "29" && arr[c].substr(1, 2) != "30" && arr[c].substr(1, 2) != "31"){
					idx = s.find("Register error!\n");
					if(idx == string::npos){
						s += "Register error!\n";
						w += 1;
					}
				}
			}
			c--;
		}
	}
	if(ins == "j"){
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		if(isNumber(str) == false){
			idx = s.find("Format error!\n");
			if(idx == string::npos){
				s += "Format error!\n";
				w += 1;
			}
		}
		int num = stoi(str);
		if(num < 0 || num > 67108863){
			idx = s.find("Address error!\n");
			if(idx == string::npos){
				s += "Address error!\n";
				w += 1;
			}
		}
		if(w > 0){
			cout << s;
		}
		else if(w == 0){
			cout << "operation = " << ins << endl;
			cout << "address = " << str << endl;
			cout << "opcode = 000010" << endl;
			bitset<26> bs1(toNumber(str));
			cout << "address = " << bs1 << endl;
		}
	}
	if(ins == "jal"){
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		if(isNumber(str) == false){
			idx = s.find("Format error!\n");
			if(idx == string::npos){
				s += "Format error!\n";
				w += 1;
			}
		}
		int num = stoi(str);
		if(num < 0 || num > 67108863){
			idx = s.find("Address error!\n");
			if(idx == string::npos){
				s += "Address error!\n";
				w += 1;
			}
		}
		if(w > 0){
			cout << s;
		}
		else if(w == 0){
			cout << "operation = " << ins << endl;
			cout << "address = " << str << endl;
			cout << "opcode = 000011" << endl;
			bitset<26> bs1(toNumber(str));
			cout << "address = " << bs1 << endl;
		}
	}
	if(ins == "jr"){
		int w = 0;
		string s = ""; 
		string ::size_type idx;
		if(str.length() > 3 || str.length() < 2){
			idx = s.find("Format error!\n");
			if(idx == string::npos){
				s += "Format error!\n";
				w += 1;
			}
		}
		else if(str.substr(0, 1) != "$"){
			idx = s.find("Format error!\n");
			if(idx == string::npos){
				s += "Format error!\n";
				w += 1;
			}
		}
		else if(str.length() == 2){
			if(str.substr(1, 1) != "0" && str.substr(1, 1) != "1" && str.substr(1, 1) != "2" && str.substr(1, 1) != "3" && str.substr(1, 1) != "4" && str.substr(1, 1) != "5" && str.substr(1, 1) != "6" && str.substr(1, 1) != "7" && str.substr(1, 1) != "8" && str.substr(1, 1) != "9"){
				idx = s.find("Register error!\n");
				if(idx == string::npos){
					s += "Register error!\n";
					w += 1;
				}
			}
		}
		else if(str.length() == 3){
			if(str.substr(1, 2) != "t0" && str.substr(1, 2) != "t1" && str.substr(1, 2) != "t2" && str.substr(1, 2) != "t3" && str.substr(1, 2) != "t4" && str.substr(1, 2) != "t5" && str.substr(1, 2) != "t6" && str.substr(1, 2) != "t7" && str.substr(1, 2) != "t8" && str.substr(1, 2) != "t9" && str.substr(1, 2) != "s0" && str.substr(1, 2) != "s1" && str.substr(1, 2) != "s2" && str.substr(1, 2) != "s3" && str.substr(1, 2) != "s4" && str.substr(1, 2) != "s5" && str.substr(1, 2) != "s6" && str.substr(1, 2) != "s7" && str.substr(1, 2) != "v0" && str.substr(1, 2) != "v1" && str.substr(1, 2) != "a0" && str.substr(1, 2) != "a1" && str.substr(1, 2) != "a2" && str.substr(1, 2) != "a3" && str.substr(1, 2) != "k0" && str.substr(1, 2) != "k1" && str.substr(1, 2) != "sp" && str.substr(1, 2) != "ra" && str.substr(1, 2) != "10" && str.substr(1, 2) != "11" && str.substr(1, 2) != "12" && str.substr(1, 2) != "13" && str.substr(1, 2) != "14" && str.substr(1, 2) != "15" && str.substr(1, 2) != "16" && str.substr(1, 2) != "17" && str.substr(1, 2) != "18" && str.substr(1, 2) != "19" && str.substr(1, 2) != "20" && str.substr(1, 2) != "21" && str.substr(1, 2) != "22" && str.substr(1, 2) != "23" && str.substr(1, 2) != "24" && str.substr(1, 2) != "25" && str.substr(1, 2) != "26" && str.substr(1, 2) != "27" && str.substr(1, 2) != "28" && str.substr(1, 2) != "29" && str.substr(1, 2) != "30" && str.substr(1, 2) != "31"){
				idx = s.find("Register error!\n");
				if(idx == string::npos){
					s += "Register error!\n";
					w += 1;
				}
			}
		}
		if(w > 0){
			cout << s;
		}
		else if(w == 0){
			cout << "operation = " << ins << endl;
			cout << "source = " << str << endl;
			cout << "opcode = 000000" << endl;
			bitset<26> bs1(toNumber(str));
			cout << "rs = " << bs1 << endl;
			cout << "rt = 00000" << endl;
			cout << "rd = 00000" << endl;
			cout << "shamt = 00000" << endl;
			cout << "function code = 001000" << endl;  
		}
	}
}
