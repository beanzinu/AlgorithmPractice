#include <iostream>

using namespace std;


int N  ;
int count ;

int main() {
	cin.tie(NULL)  ; ios::sync_with_stdio(false) ;
	
	/* first = 1 
	S = -1 
	LL = -2
	*/
	cin >> N ;
	bool PASS = false ;
	
	char s[51] ;
	
	cin >> s ;
	
	for(int i=0 ; i < N  ; i++) {
		
		if (s[i] == 'S') count++; 
		else if (s[i] == 'L') {
			 
			i++ ;
			if (!PASS) {
				PASS = true ;
				count= count+ 2;
			}
			else count++ ;
		}

	}
	
	cout << count ;
	
	
}
