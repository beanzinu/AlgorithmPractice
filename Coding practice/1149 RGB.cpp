#include <iostream>
using namespace std;
int N ;
int d[3][1001] ;
int arr[3][1001] ;


int main() {
	cin >> N ;
	for (int i=0 ; i <  N ; i++){
		for (int j=0 ; j <  3 ;j++ ) {
			cin >> arr[j][i] ;
		}
	}
	
	d[0][0] = arr[0][0] ;
	d[1][0] = arr[1][0] ;
	d[2][0] = arr[2][0] ;
	
	for (int i=1 ; i < N ; i++) {
		d[0][i] = arr[0][i] + min(d[1][i-1],d[2][i-1]) ;
		d[1][i] = arr[1][i] + min(d[0][i-1],d[2][i-1]) ;
		d[2][i] = arr[2][i] + min(d[0][i-1],d[1][i-1]) ;
	}
	
	cout << min(min(d[0][N-1],d[1][N-1]),d[2][N-1]) ; 
	
	
	
}
