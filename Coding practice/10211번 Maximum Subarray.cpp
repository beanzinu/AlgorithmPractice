#include <iostream>
using namespace std;

int T,N ;

int main() {
	cin >> T ;
	while(T--) {
		cin >> N ;
		int x= 0,y ;
		int answer = -1000  ;
		
	for (int i=0 ; i< N  ;i++) {
		cin >> y ;
		if (x+y >0) {
			x= x+y ;
			if (answer < x) answer = x ;
		} 
		else {
			x= 0 ; 
			if ( answer < 0 && answer < y) answer = y ;
		} 
	}
	cout << answer<<'\n' ;
	}
}
