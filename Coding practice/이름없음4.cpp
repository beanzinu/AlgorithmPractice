#include <iostream>
using namespace  std;

int d[1000001] ;
int N ;
int dp(int x) {
	if (x==1) return 1 ;
	if (x==2) return 2 ;
	if (d[x]!=0) return d[x] ;
	return d[x] = (dp(x-1) + dp(x-2)) % 15746 ;
} 


int main() {
	cin >> N ;
	
	cout << dp(N) ;
	
	
} 
