#include <iostream>
#include <algorithm>
using namespace std; 
#define FASTIO cin.tie(NULL) ; ios::sync_with_stdio(false) ;
int N ;
int MIN = 1 ;

int main() {
	FASTIO ;
	cin  >> N  ;
	int input[N+1] ; 
	
	for (int i= 0 ; i<N ; i++) cin >> input[i] ;	
	//sort 
	sort(input,input+N) ;
	if ( input[0] == 1 ) {
		for (int i=1 ; i<N ;i++) {
			if (input[i] <= MIN+1  ) {
				MIN = MIN + input[i] ;
			}
			else {
				cout << MIN + 1 ;
				break ;
			}
			if ( i == N -1) cout << MIN+1 ;
		}
	}
	else { cout << MIN ;
	}
}
