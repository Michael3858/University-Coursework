/* 請建立一個classBankAcc
   銀行帳戶可以記錄(使用PrivateData)
   台幣金額
   美金金額
   歐元金額
   1美金= 30台幣
   1歐元= 40台幣
   Constructor
   Default
   把三種幣值內容都設成0
   3parameters
   BankAcc( double NTD, double USD, double EUD);
   請寫
   doublevalueInNTD();帳戶總價值台幣計價
   doublevalueInUSD();帳戶總價值美金計價
   doublevalueInEUD();帳戶總價值歐元計價
   voidoutput();輸出三種帳戶的金額
   台幣美金歐元\n */
#include<iostream>
using namespace std;
class BankAcc{
	private:
		double NTD;
		double USD;
		double EUD;
	public:
		BankAcc();
		BankAcc(double N, double U, double E);
		double valueInNTD();
		double valueInUSD();
		double valueInEUD();
		void output();
};
BankAcc::BankAcc(){
	NTD = 0;
	USD = 0;
	EUD = 0;
}
BankAcc::BankAcc(double N, double U, double E){
	NTD = N;
	USD = U;
	EUD = E;
}
double BankAcc::valueInNTD(){
	return NTD + USD * 30 + EUD * 40;
}
double BankAcc::valueInUSD(){
	return NTD / 30 + USD + EUD * 40 / 30;
}
double BankAcc::valueInEUD(){
	return NTD / 40 + USD * 30 / 40 + EUD;
}
void BankAcc::output(){
	cout << NTD << " " << USD << " " << EUD << endl;
}
int main(){
	double NTD, USD, EUD;
	cin >> NTD >> USD >> EUD;
	BankAcc b(NTD, USD, EUD);
	cout <<	b.valueInNTD() << " " << b.valueInUSD() << " " << b.valueInEUD() << endl;
} 
