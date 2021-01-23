#include <iostream>
#include <algorithm>
using namespace std; 
#define FASTIO cin.tie(NULL) ; ios::sync_with_stdio(false) ;
int N , L ;
bool d[1001] ;
int temp ;
int Count ; 

int main() {
	FASTIO ;
	cin >> N >>  L ;
	int input[N+1] ;
	
	for (int i=0 ; i < N  ; i++) {
		cin >> input[i] ;
	}
	sort(input,input+N) ;
	for(int i=0 ; i < N ; i++) {
		temp = input[i] ;
		if (d[temp] == true ) continue ;
		else {
			for (int j = temp ; j < temp + L ; j++) {
				d[j] = true ;
			}
			Count++ ;
		}
	} 
	 
	cout << Count ;
	
	
}
