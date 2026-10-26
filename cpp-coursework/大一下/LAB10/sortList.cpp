/* 描述
   Derived: sortList
   繼承intList
   新增功能如下
   包含所有intList的功能
   所有加入的資料必須是sorted
   會影響排序的函數有
   insert,remove, setValue
   Override這3個函數
   讓執行這3個函數後數列還是維持排序
   本次Lab time只會測試insert()
   程式不斷輸入正整數代表輸入該正整數至intList
   如果輸入0，輸出list內所有數字由小到大，每一個數字後面跳行。程式結束
   輸入
   程式不斷輸入正整數代表輸入該正整數至intList
   如果輸入0，輸出list內所有數字由小到大，每一個數字後面跳行。程式結束
   輸出
   程式不斷輸入正整數代表輸入該正整數至intList
   如果輸入0，輸出list內所有數字由小到大，每一個數字後面跳行。程式結束 */
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
class sortList:public intList{
	public:
		void insert(int value);
};
void sortList::insert(int value){
	int last, listValue;
	intList::insert(value);
	last = getSize();
	for(int i = last; i > 1; i--){
		listValue = getValue(i - 1);
		if(listValue > value){
			swapValue(i, i - 1);
		}
		else{
			break;
		}
	}
}
int main(){
	sortList myList;
	int n;
	while(cin >> n){
		if(n == 0){
			break;
		}
		else if(n > 0){
			myList.insert(n);
		}
	}
	for(int i = 1; i <= myList.getSize(); i++){
		cout << myList.getValue(i) << endl;
	}
}
