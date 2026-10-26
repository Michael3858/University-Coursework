/* 描述
   Derived: searchList
   繼承intList
   新增功能如下
   可以搜尋某一數值是否存在
   如果存在，回傳位置
   如果有數值重複，回傳第一個位置
   如果不存在，回傳-1
   程式不斷輸入正整數代表輸入該正整數至intList
   如果程式輸入–x，代表刪除數值為x的正整數。（注意，publicmember function僅有刪除某位置的函數）。如果成功刪除，顯示ok\n，如果找不到顯示no\n
   如果輸入0程式結束
   輸入
   程式不斷輸入正整數代表輸入該正整數至intList
   如果程式輸入–x，代表刪除數值為x的正整數。（注意，publicmember function僅有刪除某位置的函數）。如果成功刪除，顯示ok\n，如果找不到顯示no\n
   如果輸入0程式結束
   輸出
   程式不斷輸入正整數代表輸入該正整數至intList
   如果程式輸入–x，代表刪除數值為x的正整數。（注意，publicmember function僅有刪除某位置的函數）。如果成功刪除，顯示ok\n，如果找不到顯示no\n
   如果輸入0程式結束 */ 
#include<iostream>
#include<cmath>
using namespace std;
class intList{
	private:
		int *data;
		int totalSize;
		int sizeUsed;
		void expandSize();
	protected:
		bool swapValue(int pos1, int pos2);
	public:
		intList();
		void insert(int value);
		bool remove(int pos);
		int getValue(int pos);
		bool setValue(int pos, int value);
		int getSize(); 
}; 
void intList::expandSize(){
    int *newData, newTotalSize;
	newTotalSize = totalSize * 2;
	newData = new int[newTotalSize];
	for(int i = 0; i < sizeUsed; i++){
		newData[i] = data[i];
	}
	delete data;
	data = newData;
	totalSize = newTotalSize;
}
bool intList::swapValue(int pos1, int pos2){
	if(pos1 < 1 || pos1 > sizeUsed){
		return false;
	}
	if(pos2 < 1 || pos2 > sizeUsed){
		return false;
	}
	int tmp = data[pos1 - 1];
	data[pos1 - 1] = data[pos2 - 1];
	data[pos2 - 1] = tmp;
	return true;
}
intList::intList(){
	data = new int[10];
	totalSize = 10;
	sizeUsed = 0;
}
void intList::insert(int value){
	if(sizeUsed == totalSize){
		expandSize();
	}
	data[sizeUsed++] = value;
}
bool intList::remove(int pos){
	if(pos <= sizeUsed || pos >= 1){
        data[pos - 1] = data[--sizeUsed];
        return true;
	}
	else{
		return false;
	}
}
int intList::getValue(int pos){
	if(pos < 1 || pos > sizeUsed){
		return -1;
	}
	return data[pos - 1];
}
bool intList::setValue(int pos, int value){
	if(pos <= sizeUsed && pos >= 1){
		data[pos - 1] = value;
        return true;
	}
	else{
		return false;
	}
}
int intList::getSize(){
	return sizeUsed;
}
class searchList:public intList{
	public:
		int search(int value);
};
int searchList::search(int value){
	int ocupied = getSize();
	for(int i = 1; i <= ocupied; i++){
		if(getValue(i) == value){
			return i;
		}
	}
	return -1;
}
int main(){
	searchList myList;
	int n;
	while(cin >> n){
		if(n == 0){
			break;
		}
		else if(n > 0){
			myList.insert(n);
		}
		else{
			n = abs(n);
			int pos = myList.search(n);
			if(pos == -1){
				cout << "no" << endl;
			}
			else{
				myList.remove(pos);
				cout << "ok" << endl;
			}
		}
	}
}
