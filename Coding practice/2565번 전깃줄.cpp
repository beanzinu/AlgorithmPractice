#include <iostream>
using namespace std;

int N ;
int rep ;
int result ;
int d[501] ; // 최대연결 개수 
int h[501] ; // 연결 위치 

#define FASTIO() cin.tie(NULL) ; ios::sync_with_stdio(false) ;
int main() {
	FASTIO() ;
	cin >>  N ;
	
	int A,B ; 
	for(int i = 0 ; i < N ; i++) {
		cin >> A >> B ;
		h[A] =  B ;
		if ( B > rep ) rep = B ;
		if ( A > rep )  rep = A ;
	}
	
	for (int i = 1 ; i <= rep  ; i++ ) {
		if ( h[i] == 0 ) continue ;   // 연결선이 없을때 
		int MAX = 0 ;
		for (int j= i ; j >=1 ; j--) {
			if ( h[j] == 0) continue ;  // 연결선이 없을때 
			if ( h[j] < h[i] && d[j] > MAX ) MAX = d[j] ;
		}
		
		d[i] = MAX + 1 ;
		if ( d[i] > result ) result = d[i] ;
	}
	// 출력
	cout << N - result ;
	
}
