#include <iostream>
#include <algorithm>
int r[100001];
int Max ;
using namespace std ;

bool compare (int a,int b){
	return a > b;
}

int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ; 
	int N ;
	cin >> N;
	for (int i=0 ;i < N ; i ++) {
		int temp ;
		cin >> temp ;
		r[i] = temp;
	}
	sort(r,r+N,compare) ; // 내림차순 정렬
	
	for (int i = 0 ; i < N ; i ++) {
		int min = r[i] ;
		if ( Max < min * (i+1) ) Max = min* (i+1) ;
	}
	
	cout << Max ;
	 
	
} 
