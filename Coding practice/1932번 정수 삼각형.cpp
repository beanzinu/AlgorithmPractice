#include <iostream>
using namespace std;
int n ;
int d[501] ;
int main() {
	cin >> n  ;
	
	for (int i=1 ;  i <= n ; i++) {
		int temp ;
		int temparr[i+1] ;
		for (int j =0 ; j < i ; j++) {
			cin >> temp ;
			if (i == 1 ) {  
			temparr[0] = temp ; break; }
			
			if ( j == 0)  { // first 
				temparr[0] = d[0] + temp ;
			}
			else if ( j == i-1 ) { // last
			 temparr[j] = d[j-1] + temp ; 
			}
			else {
				temparr[j] = max(d[j],d[j-1]) + temp ;
			}		
	} // j
	copy(temparr,temparr+i,d) ;
	}
	int MAX = 0 ;
	for (int i = 0 ; i < n ; i++) {
		if ( d[i] > MAX )  MAX = d[i] ;
	}
	cout << MAX ;
	
	
	
}
