#include <iostream>
using namespace std;
int N ;
int temp ;
int arr[301] ;
int d[301][3] ;

#define FASTIO() cin.tie(NULL)  ; ios::sync_with_stdio(false) ;
int main() {
	FASTIO() ;
	cin >> N ;
	for(int i= 0; i < N ; i++) {   // input 
		cin >> temp ;
		arr[i] = temp ;
	}
	
	//
	for (int i = 0 ; i <  N ;i++) {
		if ( i == 0) {
			d[i][1] = arr[0] ; 
		}
		else if ( i == 1 ) {
			d[i][1] = arr[1] ;
			d[i][2] = d[i-1][1] + arr[i] ;
		}
		else {  // i >= 2
			d[i][1] = max(d[i-2][1],d[i-2][2]) + arr[i] ;
			d[i][2] = d[i-1][1] + arr[i] ;
		}	
	}
	cout << max(d[N-1][1],d[N-1][2]) ;
	
	
	
}
