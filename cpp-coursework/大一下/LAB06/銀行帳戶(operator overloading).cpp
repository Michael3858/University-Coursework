/* 承上題
   請Overloading operator
   BankAcc+BankAcc將兩個帳戶金額相加
   BankAcc-BankAcc將兩個帳戶金額相減
   BankAcc%BankAcc兩個帳戶金額相減後之絕對值
   BankAcc*BankAcc:前BankAcc+後BankAcc*0.99（1%手續費）
   BankAcc/BankAcc:前BankAcc-後BankAcc*1.01（1%手續費）
   輸入兩個人每個幣值的帳戶金額
   輸出上述五種Operator Overloading的計算結果(依序) */
#include<iostream>
#include<cmath>
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
		double getNTD() const;
		double getUSD() const;
		double getEUD() const;
		void output();
};
const BankAcc operator +(const BankAcc &a, const BankAcc &b); // const 跟 & 可加可不加 
const BankAcc operator -(const BankAcc &a, const BankAcc &b);
const BankAcc operator %(const BankAcc &a, const BankAcc &b);
const BankAcc operator *(const BankAcc &a, const BankAcc &b);
const BankAcc operator /(const BankAcc &a, const BankAcc &b);

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
double BankAcc::getNTD() const{
	return NTD;
}
double BankAcc::getUSD() const{
	return USD;
}
double BankAcc::getEUD() const{
	return EUD;
}
void BankAcc::output(){
	cout << NTD << " " << USD << " " << EUD << endl;
}
const BankAcc operator +(const BankAcc &a, const BankAcc &b){
	return BankAcc(a.getNTD() + b.getNTD(), a.getUSD() + b.getUSD(), a.getEUD() + b.getEUD());
}
const BankAcc operator -(const BankAcc &a, const BankAcc &b){
	return BankAcc(a.getNTD() - b.getNTD(), a.getUSD() - b.getUSD(), a.getEUD() - b.getEUD());
}
const BankAcc operator %(const BankAcc &a, const BankAcc &b){
	return BankAcc(abs(a.getNTD() - b.getNTD()), abs(a.getUSD() - b.getUSD()), abs(a.getEUD() - b.getEUD()));
}
const BankAcc operator *(const BankAcc &a, const BankAcc &b){
	return BankAcc(a.getNTD() + b.getNTD() * 0.99, a.getUSD() + b.getUSD() * 0.99, a.getEUD() + b.getEUD() * 0.99);
}
const BankAcc operator /(const BankAcc &a, const BankAcc &b){
	return BankAcc(a.getNTD() - b.getNTD() * 1.01, a.getUSD() - b.getUSD() * 1.01, a.getEUD() - b.getEUD() * 1.01);
}
int main(){
	double NTD, USD, EUD;
	cin >> NTD >> USD >> EUD;
	BankAcc b1(NTD, USD, EUD); 
	cin >> NTD >> USD >> EUD;
	BankAcc b2(NTD, USD, EUD);
	BankAcc b3;
	b3 = b1 + b2;
	b3.output();
	b3 = b1 - b2;
	b3.output();
	b3 = b1 % b2;
	b3.output();
	b3 = b1 * b2;
	b3.output();
	b3 = b1 / b2;
	b3.output();
}
