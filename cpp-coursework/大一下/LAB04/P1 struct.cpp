/* 宣告一個struct包含編號(int)、國英數社自(double)五科成績。
   程式一開始輸入一個數字x
   接著會輸入x份編號與國英數社自六個數字。
   每一個人的總分為五科任選最高四科目的總和。
   輸出 最高分與最低分的編號與平均(同分的情況，請輸出先輸入的編號) */
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct grade{
	int num;
	double point[5];
	double av = 0;
};
int main(){
	int x;
	cin >> x;
	grade n[x];
	for(int i = 0; i < x; i++){
		cin >> n[i].num;
		for(int j = 0; j < 5; j++){
			cin >> n[i].point[j];
		}
		sort(n[i].point, n[i].point + 5);
		for(int j = 1; j < 5; j++){
			n[i].av += n[i].point[j];
		}
		n[i].av /= 4;
	}
	double max = n[0].av, min = n[0].av, maxnum = n[0].num, minnum = n[0].num;
	for(int i = 1; i < x; i++){
		if(n[i].av > max){
			max = n[i].av;
			maxnum = n[i].num;
		}
		else if(n[i].av < min){
			min = n[i].av;
			minnum = n[i].num;
		}
	}
	cout << maxnum << " " << max << endl << minnum << " " << min << endl;
	return 0;
}
