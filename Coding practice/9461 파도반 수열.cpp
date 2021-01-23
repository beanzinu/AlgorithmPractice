#include <iostream>
using namespace std;
int T ;
long long int d[101] ={ 0,1,1,1,2,2,0  } ;


int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	
	cin >> T ;
	int input ;
	while(T--) {
		cin >> input ;
		if (input < 6) cout << d[input]  << '\n' ;
		else {
			int rep = input - 5 ;
			long long int a=2 , b= 1 , s = 3 ;
			
			for(int i = 1 ; i <= rep ; i++) {
				s = a+ b ;
				d[i+5] = s ;
				a = s; 
				b = d[i+1] ;
			}
			
			cout << s << '\n' ;
		}
		
		
	}
	
	
}
