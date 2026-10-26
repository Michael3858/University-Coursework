#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<algorithm>
using namespace std;
void merge(int *intlist, int *mergedlist, const int l, const int m, const int n){
	int i1, i2, iresult;
	for(i1 = l, iresult = l, i2 = m + 1; i1 <= m && i2 <= n; iresult++){
		if(intlist[i1] <= intlist[i2]){
			mergedlist[iresult] = intlist[i1];
			i1++;
		}
		else{
			mergedlist[iresult] = intlist[i2];
			i2++;
		}
	}
	copy(intlist + i1, intlist + m + 1, mergedlist + iresult);
	copy(intlist + i2, intlist + n + 1, mergedlist + iresult);
}
void mergepass(int *intlist, int *resultlist, const int n, const int s){
	int i;
	for(i = 1; i <= n - 2 * s + 1; i += 2 * s){
		merge(intlist, resultlist, i, i + s - 1, i + 2 * s - 1);
	}
	if((i + s - 1) < n){
		merge(intlist, resultlist, i, i + s - 1, n);
	}
	else{
		copy(intlist + i, intlist + n + 1, resultlist + i);
	}
}
void mergesort(int *a, const int n){
	int *templist = new int[n + 1];
	for(int i = 1; i < n; i *= 2){
		mergepass(a, templist, n, i);
		i *= 2;
		mergepass(templist, a, n, i);
	}
	delete [] templist;
	/*for(int i = 1; i <= 10; i++){
		cout << a[i] << " ";
	}
	cout << endl;*/
}
void adjust(int *a, const int root, const int n){
	int e = a[root];
	int i;
	for(i = 2 * root; i <= n; i *= 2){
		if(i < n && a[i] < a[i + 1]){
			i++;
		}
		if(e >= a[i]){
			break;
		}
		a[i / 2] = a[i];
	}
	a[i / 2] = e;
}
void heapsort(int *a, const int n){
	for(int i = n / 2; i >= 1; i--){
		adjust(a, i, n);
	}
	for(int i = n - 1; i >= 1; i--){
		int temp = a[1];
		a[1] = a[i + 1];
		a[i + 1] = temp;
		adjust(a, 1, i);
	}
	/*for(int i = 1; i <= 10; i++){
		cout << a[i] << " ";
	}
	cout << endl;*/
}
void insert(const int& e, int *a, int i){
	a[0] = e;
	while(e < a[i]){
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}
void insertionsort(int *a, const int n){
	for(int i = 2; i <= n; i++){
		int temp = a[i];
		insert(temp, a, i - 1);
	}
	/*for(int i = 1; i <= 10; i++){
		cout << a[i] << " ";
	}
	cout << endl;*/
}
int main(){
	srand(time(0));
	double time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0;
	int c;
	cout << "請選擇排序法:" << endl;
	cout << "1.merge sort" << endl;
	cout << "2.heap sort" << endl;
	cout << "3.insertion sort" << endl;
	cin >> c;
	int *num1;
	num1 = new int [11];
	for(int i = 1; i <= 10; i++){
		num1[i] = rand() % 50000 + 1;
	}
	if(c == 1){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		mergesort(num1, 10);
		QueryPerformanceCounter(&nEndTime);
		time1 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;	
	}
	if(c == 2){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		heapsort(num1, 10);
		QueryPerformanceCounter(&nEndTime);
		time1 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}	
	if(c == 3){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		insertionsort(num1, 10);
		QueryPerformanceCounter(&nEndTime);
		time1 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}
	delete [] num1;
	int *num2;
	num2 = new int [101];
	for(int i = 1; i <= 100; i++){
		num2[i] = rand() % 50000 + 1;
	}
	if(c == 1){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		mergesort(num2, 100);
		QueryPerformanceCounter(&nEndTime);
		time2 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;	
	}
	if(c == 2){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		heapsort(num2, 100);
		QueryPerformanceCounter(&nEndTime);
		time2 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}	
	if(c == 3){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		insertionsort(num2, 100);
		QueryPerformanceCounter(&nEndTime);
		time2 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}
	delete [] num2;
	int *num3;
	num3 = new int [1001];
	for(int i = 1; i <= 1000; i++){
		num3[i] = rand() % 50000 + 1;
	}
	if(c == 1){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		mergesort(num3, 1000);
		QueryPerformanceCounter(&nEndTime);
		time3 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;	
	}
	if(c == 2){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		heapsort(num3, 1000);
		QueryPerformanceCounter(&nEndTime);
		time3 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}	
	if(c == 3){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		insertionsort(num3, 1000);
		QueryPerformanceCounter(&nEndTime);
		time3 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}
	delete [] num3;
	int *num4;
	num4 = new int [10001];
	for(int i = 1; i <= 10000; i++){
		num4[i] = rand() % 50000 + 1;
	}
	if(c == 1){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		mergesort(num4, 10000);
		QueryPerformanceCounter(&nEndTime);
		time4 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;	
	}
	if(c == 2){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		heapsort(num4, 10000);
		QueryPerformanceCounter(&nEndTime);
		time4 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}	
	if(c == 3){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		insertionsort(num4, 10000);
		QueryPerformanceCounter(&nEndTime);
		time4 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}
	delete [] num4;
	int *num5;
	num5 = new int [100001];
	for(int i = 1; i <= 100000; i++){
		num5[i] = rand() % 50000 + 1;
	}
	if(c == 1){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		mergesort(num5, 100000);
		QueryPerformanceCounter(&nEndTime);
		time5 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;	
	}
	if(c == 2){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		heapsort(num5, 100000);
		QueryPerformanceCounter(&nEndTime);
		time5 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}	
	if(c == 3){
		LARGE_INTEGER nFreq;
		LARGE_INTEGER nBeginTime;
		LARGE_INTEGER nEndTime;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		insertionsort(num5, 100000);
		QueryPerformanceCounter(&nEndTime);
		time5 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}
	delete [] num5;
	cout << "10個數字:" << time1 << "s" << endl;
	cout << "100個數字:" << time2 << "s" << endl;
	cout << "1000個數字:" << time3 << "s" << endl;
	cout << "10000個數字:" << time4 << "s" << endl;
	cout << "100000個數字:" << time5 << "s" << endl;
} 

