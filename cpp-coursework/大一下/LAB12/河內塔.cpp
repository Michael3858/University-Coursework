/* 描述
   Tower of Hanoi
   有三根杆子A，B，C。A桿上有N個(N>1)穿孔圓盤，盤的尺寸由下到上依次變小。
   要求按下列規則將所有圓盤移至C桿：
   每次只能移動一個圓盤；
   大盤不能疊在小盤上面。
   提示：可將圓盤臨時置於B桿，也可將從A桿移出的圓盤重新移回A桿，但都必須尊循上述兩條規則。
   輸入
   讓使用者輸入N( N>1)
   請印出步驟，最後輸出一共移動了多少次？PS:盤子最小的是1,最大是N
   Move1 from A to C\n
   …
   Totalsteps:7\n
   輸出
   讓使用者輸入N( N>1)
   請印出步驟，最後輸出一共移動了多少次？PS:盤子最小的是1,最大是N
   Move1 from A to C\n
   …
   Totalsteps:7\n */
#include<iostream>
#include<cmath>
using namespace std;
void tower(int n, char c1, char c2, char c3);
void tower(int n, char c1, char c2, char c3){
	if(n > 0){
		tower(n - 1, c1, c3, c2);
		cout << "Move " << n << " from " << c1 << " to " << c3 << endl;
		tower(n - 1, c2, c1, c3);
	}
}
int main(){
	int n;
	cin >> n;
	int moved = pow(2, n) - 1;
	if(n >= 1){
		tower(n, 'A', 'B', 'C');
		cout << "Total steps:" << moved << endl;
	}
}
