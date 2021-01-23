#include <iostream>
using namespace std;
#define FASTIO cin.tie(NULL) ; ios::sync_with_stdio(false) ;

int N ;
int count ;

int main() {
	cin >>  N  ;
	int arr[N+1] ;
	
	for(int i=0 ; i<N ;i++) cin >> arr[i] ;	
		
	for (int i=N-2 ; i >= 0 ; i--) {
		if (arr[i] >= arr[i+1]) {
			
			count = count + arr[i]-arr[i+1] +1 ;
			arr[i] = arr[i+1] - 1 ;
		  
	}
	}
	cout << count ; 
	
}
