#include <iostream>
using namespace std;
int N ;
int answer ;
void Dp(int x,int count) {
	if (count == N) {
		if ( answer == 999999999) answer = 0 ;
		else answer++ ;
		 return ;
	}
	
	if ( x-1 >=0 ) Dp(x-1,count+1) ;
	if ( x+1 <=9) Dp(x+1,count+1) ;
	
}



int main() {
	cin.tie(NULL); ios::sync_with_stdio(false) ;
	cin >> N ;
	
	for (int i = 1 ; i <= 5 ; i++) {
		int temp = answer ;
		Dp(i,1) ;
		if ( i != 5 ) {
			answer = ( answer + answer - temp ) % 1000000000  ;
		}
	}
	cout << answer ; 
	
}
