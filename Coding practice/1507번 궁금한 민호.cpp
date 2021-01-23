#include <iostream>
using namespace std;
int N ;
int answer ;


int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	cin >>  N ;
	int arr[N+1][N+1] ;
	
	for (int i = 1 ; i <= N ; i++) {
		for (int j=1 ; j <= N ; i++) {
			cin >> arr[i][j] ;
		}
	}
	
	for (int i = 1 ; i <= N ; i++) {
		for (int j = i+1 ; j <= N ; j++) {
		 int MIN =  20001 ;
			for (int k = 1 ; k <=  N ;k++) {
				if ( k == j ) continue ;
				if ( arr[i][k] + arr[k][j] < MIN )	MIN = arr[i][k] + arr[k][j] ;		
			}
			if (arr[i][j] < MIN ) answer = answer + arr[i][j] ;  
		}
		
	}
	
	cout << answer ;	
	
}
