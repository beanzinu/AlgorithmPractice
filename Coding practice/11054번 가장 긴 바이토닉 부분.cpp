#include <iostream>
using namespace std;
int N ;
int arr[1001] ;
int front[1001] = {1, };
int back[1001] ;

#define FASTIO() cin.tie(NULL) ; ios::sync_with_stdio(false) ;
int main() {
	cin >>  N ;
	
	for(int i= 0; i <  N  ; i++)  cin >> arr[i] ;
	
	for (int i = 0 ;  i < N ; i++) {  // front
		int MAX = 0 ;
		
		for(int j= i ; j >= 0 ; j--) { 
			if (arr[j] < arr[i] ) {
				if ( MAX < front[j]) MAX = front[j] ;	
			}
		}
		front[i] = MAX + 1;
		
	}   
	
	// back
	for (int i = N-1 ; i >=0 ; i--) {
		int MAX = 0 ;
		
		for (int j =i ; j <= N ; j++) {
			if (arr[j] < arr[i] ){
				if(MAX < back[j]) MAX = back[j] ;
			}
		}
		
		back[i]  = MAX +1 ;
	}
	// result
	int result = 0 ;  
	for (int i = 0 ;  i < N  ; i++) {
		if ( front[i]+back[i] > result) result = front[i] + back[i] ;
	}
	cout << result -1 ;
	
}

