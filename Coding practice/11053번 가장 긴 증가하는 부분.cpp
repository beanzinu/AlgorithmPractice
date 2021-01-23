#include <iostream>
using namespace std;
int N  ;
int arr[1001] ;
int d[1001] ;
int answer ;
void Dp(int start,int count) {
	if (count > answer )  answer = count ;
	int i =1 ;
	while( start + i < N) {
		if (arr[start]  < arr[start + i]  ) {
			if ( d[start+i] < count+1 ) {
				d[start+i] = count+1 ;
				Dp(start+i,count+1) ;
			}
			else {
				i++ ; continue ; 
			} 
		}
		i++ ;	
	} // while  
	
	
}



int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	cin >> N ;
	for (int i = 0 ; i  < N ; i++) {
		cin >> arr[i] ;
	}
	for (int i = 0 ; i  < N ; i++) {
		Dp(i,1) ;
	}
	cout << answer ; 
	
}
