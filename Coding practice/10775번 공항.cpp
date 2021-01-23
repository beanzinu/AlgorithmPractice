#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL) ; ios::sync_with_stdio(false) ;


int G ,P ;
int temp ;
int count ;
bool PASS ;
int main() {
	FASTIO ;
	cin >> G >>  P ;
	bool C[G+1] = { 0 , };
	
	for(int i =0; i < P ;i++) {
		cin >> temp ;
		if (PASS == true) continue ;
		
		while(temp > 0) {
			if (C[temp] == false) {
			C[temp] = true ;
			count++;
			break;
			}
			temp-- ;
		} 
		if (temp == 0) PASS = true ;
		
		
	}
	 cout << count ;
	
	
}
