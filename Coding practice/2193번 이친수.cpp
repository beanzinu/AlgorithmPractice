#include <iostream> 
using namespace std;

int N ;
long long int d[91][2] ;
int main() {
	cin >> N ;
	d[1][1] = 1 ;
	for(int i=2; i<=90 ; i++) {
		d[i][0] = d[i-1][0] + d[i-1][1] ;
		d[i][1] = d[i-1][0] ; 
	}	
	cout << d[N][0] + d[N][1] ;
	
	
	
} 
