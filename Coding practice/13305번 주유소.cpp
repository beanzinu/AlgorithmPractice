#include <iostream>
using namespace std;
int N  ;
int cost ; // answer 



int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	cin >> N  ;
	int d[N] ; // distance 
	int c[N+1] ; // cost
	
	for (int i = 0 ; i<N-1 ; i++) cin >> d[i] ;
	for (int i =0 ; i<N ; i++) cin >> c[i] ;
	
	long long int temp = 1000000001 ;
	for (int i=0 ; i<N-1 ;i++) {
		if ( c[i] < temp  ) temp = c[i] ;
		cost = cost + (temp * d[i]) ;
		
	}
	cout << cost ; 
	
}
