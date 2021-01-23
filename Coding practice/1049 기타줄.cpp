#include <iostream>

using namespace std;
int min_6= 1001,min_1 = 1001;

int main() {
	int N,M ;
	cin >> N >> M;
	while(M--) {
		int n1,n2 ;
		cin >> n1 >> n2 ;
		if ( n1 < min_6 ) min_6 = n1 ;
		if ( n2 < min_1 ) min_1 = n2 ;
	}	
	// 결과 출력
	if ( min_6 >= min_1 *6) cout << N*min_1 ;
	else {
		if ( (N%6)*min_1 > min_6 ) cout << min_6 * ((N/6)+1) ;
		else {
			cout << (min_6*(N/6)) + (min_1*(N%6)) ;
		}
	} 
	
	
}
