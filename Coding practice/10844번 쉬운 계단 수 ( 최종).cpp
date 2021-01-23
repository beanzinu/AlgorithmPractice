#include <iostream>
using namespace std;

int N ;
int arr[101][10] ;

int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	
	cin >> N ;
	
	// �����ڸ�
	for(int i= 0 ; i<=9 ; i++) {
		 arr[1][i] = 1 ; 
	}
	
	for (int i =2 ; i <= N ;i++ ) {
		for (int j = 0 ; j<= 9 ; j++) {
			if( j== 0) {
				arr[i][j] = (arr[i-1][1]) %1000000000;
			}
			else if (j==9) {
				arr[i][j] = (arr[i-1][8]) %1000000000;
			}
			else {
				arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1])%1000000000 ;
			}
		}
	}
	
	int answer = 0 ;
	
	for(int i=1; i<=9 ; i++) {
		answer = (answer + arr[N][i])% 1000000000 ;
	}
	
	cout << answer ;
	
	
	
}
