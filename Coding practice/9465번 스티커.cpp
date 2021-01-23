#include <iostream>
using namespace std;

int main() {
	int test_case ;
	cin >> test_case ;
	while(test_case--) {
		int n ;
		cin >> n ;
		int arr[2][n] ;
		int d[2][n] ;
		for(int i=0;i<2;i++) {
			for(int j=0;j<n;j++){
				cin >> arr[i][j] ;
			}
		}
		d[0][0] = arr[0][0] ;
		d[1][0] = arr[1][0] ;
		d[0][1] = d[1][0] + arr[0][1] ;
		d[1][1] = d[0][0] + arr[1][1] ;
		for(int i=2;i<n;i++){
			for(int j=0;j<2;j++){
				if(j==0) {
					d[j][i] = max(d[j+1][i-1],d[j+1][i-2]) + arr[j][i] ;
				}
				else {
					d[j][i] = max(d[j-1][i-1],d[j-1][i-2]) +arr[j][i] ;
				}
			}
		}
		
		cout << max(d[0][n-1],d[1][n-1]) ;
		
	}
	
	
	
}
