#include <iostream>
using namespace std;

int N ;
int result ;
int d[40001] ; // �ִ뿬�� ���� 
int h[40001] ; // ���� ��ġ  
#define FASTIO() cin.tie(NULL) ; ios::sync_with_stdio(false) ;
int main() {
	FASTIO() ;
	cin >>  N ;
	
	int temp ;
	for(int i = 1 ; i <= N ; i++) {
		cin >> temp ;
		h[i] = temp ; 
	} 
	
	for (int i = 1 ; i <= N  ; i++ ) { 
		int MAX = 0 ;
		for (int j= i ; j >=1 ; j--) {
			if ( h[j] < h[i] && d[j] > MAX ) MAX = d[j] ;
			if ( MAX == result ) break;
		}
		
		d[i] = MAX + 1 ;
		if ( d[i] > result ) result = d[i] ;
	}
	// ���
	cout << result ;
	
}
