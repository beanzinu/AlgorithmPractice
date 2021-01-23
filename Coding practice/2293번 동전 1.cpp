#include <iostream>
using namespace std;
int n , k ;
int d[101] ;
int Dp[100001] ;
#define FASTIO cin.tie(NULL) ; ios::sync_with_stdio(false) ;

void dp(int index) {
	
	Dp[d[index]]++ ;
	
	for (int i= index+1 ; i <= k ; i++) {
		Dp[i] = Dp [i] + Dp[i - d[index] ] ;
		
	}
	
	
}


int main() {
	FASTIO ;
	
	//input 
	cin >> n >> k ;
	for (int i = 0  ; i < n ; i++) cin >> d[i]  ;
	
	
	//dp
	for (int i =0 ; i < n ; i++) {
		if ( d[i] <= k) dp(i) ;
		else break ;
	}
	cout << Dp[k] ;
}
