/* 描述
   Base Class: intList
   可以新增/刪除正整數到該物件
   新增沒有size限制，會自動擴增
   remove會拿最後一個資料去補刪除的位置
   有mutater, accessor可以修改、存取資料
   可以swap兩個位置的值
   class intList//pos從1開始（陣列從0開始）
   {
   public:
   intList();
   void insert(intvalue);//新增value到數列
   bool remove(intpos);//刪除pos位置的正整數
   int getValue(intpos);//回傳pos位置的值
   bool setValue(intpos,int value);//設定pos位置的值為value
   int getSize();//sizeUsed的accessor
   protected:
   bool swapValue(int pos1, int pos2);
   private:
   int *data;//資料存放的動態陣列
   int totalSize;//目前動態陣列的大小
   int sizeUsed;//目前有幾個正整數
   void expandSize();//擴增動態陣列大小為兩倍
   };
   程式不斷輸入正整數代表輸入該正整數至intList
   如果程式輸入–x，代表刪除位置為x的正整數。如果成功刪除，顯示x位置的值\n，如果無法刪除顯示no\n
   如果輸入0程式結束
   輸入
   程式不斷輸入正整數代表輸入該正整數至intList
   如果程式輸入–x，代表刪除位置為x的正整數。如果成功刪除，顯示x位置的值\n，如果無法刪除顯示no\n
   如果輸入0程式結束
   輸出
   程式不斷輸入正整數代表輸入該正整數至intList
   如果程式輸入–x，代表刪除位置為x的正整數。如果成功刪除，顯示x位置的值\n，如果無法刪除顯示no\n
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
	if(pos <= sizeUsed && pos >= 1){
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
int main(){
	intList myList;
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
			int ans = myList.getValue(n);
			if(myList.remove(n)){
				cout << ans << endl;
			}
			else{
				cout << "no" << endl;
			}
		}
	}
}
