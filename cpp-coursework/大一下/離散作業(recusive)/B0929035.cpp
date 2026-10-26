#include<iostream>
#include<cstdlib>
using namespace std;
int GCD(int a, int b);
int GCD(int a, int b){
	if(b != 0){
		return GCD(b, a % b);
	}
	else{
		return a;
	}
}
int binarySearch(int arr[], int p, int r, int num);
int binarySearch(int arr[], int p, int r, int num){
	if(p <= r){
		int mid = (p + r) / 2;
		if(arr[mid] == num){
			return mid;
		}
		if(arr[mid] > num){
			return binarySearch(arr, p, mid - 1, num);
		}
		if(arr[mid] < num){
			return binarySearch(arr, mid + 1, r, num);
		}
	}
	return -1;
}
int linearSearch(int arr[], int num, int size);
int linearSearch(int arr[], int num, int size){
	for(int i = 0; i < size; i++){
		if(arr[i] == num){
			return i;
		}
	}
	return -1;
}
int fib(int n);
int fib(int n){
	if(n <= 1){
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}
void merge(int arr[], int p, int q, int m);
void merge(int arr[], int p, int q, int m){
	int n1 = m - p + 1;
	int n2 = q - m;
	int *L = new int[n1];
	int *R = new int[n2];
	for(int i = 0; i < n1; i++){
		L[i] = arr[p + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = arr[i + m + 1];
	}
	L[n1] = 2147483647;
	R[n2] = 2147483647;
	int a = 0, b = 0;
	for(int i = p; i <= q; i++){
		if(L[a] <= R[b]){
			arr[i] = L[a];
			a++;
		}
		else{
			arr[i] = R[b];
			b++;
		}
	}
}
void mergeSort(int arr[], int p, int q);
void mergeSort(int arr[], int p, int q){
	if(p < q){
		int mid = (p + q) / 2;
		mergeSort(arr, p, mid);
		mergeSort(arr , mid + 1, q);
		merge(arr, p, q, mid);
	}
}
int main(){
	cout << "Please input the integer 1 to 5." << endl;
    cout << "1 is to do GCD Algorithm." << endl;
    cout << "2 is to do Binary Search Algorithm." << endl;
    cout << "3 is to do linear search." << endl;
    cout << "4 is to do Find the nth Fibonacci number." << endl;
    cout << "5 is to do Merge Sort." << endl;
    int c;
    cin >> c;
    if (c < 1 || c > 5){
    	system("pause");
        return 0;
    }
    if(c == 1){
    	cout << "Please input two positive integers to find GCD." << endl;
    	int n1, n2;
    	cin >> n1 >> n2;
   		if(n1 <= 0 || n2 <= 0){
   			system("pause");
   			return 0;
   		}
		cout << "GCD(" << n1 << ", " << n2 << ") = " << GCD(n1, n2) << endl;
		system("pause");
		return 0;
	}
	else if(c == 2){
		cout << "Please input how many numbers of integers you want to construct a series." << endl;
		int n;
		cin >> n;
		cout << "Please input integers in a series." << endl;
		int arr[n];
		for(int i = 0; i < n; i++){
           	cin >> arr[i];
        }
        for(int i = 1; i < n; i++){
        	if(arr[i] < arr[i - 1]){
        		system("pause");
        		return 0;
			}
		}
		cout << "Please input an integer you want to find in series." << endl;
		int num;
		cin >> num;
		int size = (sizeof(arr) / sizeof(arr[0]));
		int ans = binarySearch(arr, 0, size - 1, num);
		if(ans == -1){
           	cout << "Element " << num << " is not present in series." << endl;
        }
        else{
           	cout << num << " is present at index " << ans + 1 << "th." << endl;
        }
        system("pause");	
        return 0;
	}
	else if(c == 3){
		cout << "Please input how many numbers of integers you want to construct a series." << endl;
		int n;
		cin >> n;
		cout << "Please input integers in a series." << endl;
		int arr[n];
		for(int i = 0; i < n; i++){
           	cin >> arr[i];
        }
		cout << "Please input an integer you want to find in series." << endl;
		int num;
		cin >> num;
		int size = (sizeof(arr) / sizeof(arr[0]));
		int ans = linearSearch(arr, num, size);
		if (ans == -1){
           	cout << "Element " << num << " is not present in series." << endl;
       	}
        else{
           	cout << num << " is present at index " << ans + 1 << "th." << endl;
        }
        system("pause");
       	return 0;
	}
	else if(c == 4){
		cout << "Please input a non-negative integer." << endl;
		int n;
		cin >> n;
		if(n < 0){
			system("pause");
			return 0;
		}
		cout << n << "th Fibnacci number is " << fib(n) << endl;
		system("pause");
		return 0;
	}
	else if(c == 5){
		cout << "Please input how many numbers of integers you want to construct a series." << endl;
		int n;
		cin >> n;
		cout << "Please input integers in a series." << endl;
		int arr[n];
		for (int i = 0; i < n; i++){
           	cin >> arr[i];
        }
        mergeSort(arr, 0, n - 1);
        cout << "After Merge Sort : " << endl;
        for(int i = 0; i < n; i++){
        	cout << arr[i] << " ";
		}
		cout << endl;
		system("pause");
		return 0;
	}
} 
