#include <iostream>
#include <stack>
using namespace std;
stack<int> s ;
int Max , Min ;
char arr[10] ;
int main() {
	int k ;
	cin >> k;
	for (int i=0; i < k ; i++) {
		char temp ;
		cin >> temp ;
		arr[i] = temp ;
	}
	int max_i = 9 ;
	for (int i =0; i < k ; i++) {
		if(arr[i]=='<') s.push(max_i--) ;
		else {
			s.push(max_i--) ;
			while(!s.empty()) {
			cout << s.top() ;
			s.pop() ;
			}	
		}
	}
	s.push(max_i--) ;
	while(!s.empty()) {
			cout << s.top() ;
			s.pop() ;
			}
	// 최대 
	cout << '\n' ;
	// 최소
	int min_i = 0 ;
	for (int i =0; i < k ; i++) {
		if(arr[i]=='>') s.push(min_i++) ;
		else {
			s.push(min_i++) ;
			while(!s.empty()) {
			cout << s.top() ;
			s.pop() ;
			}	
		}
	}
	s.push(min_i++) ;
	while(!s.empty()) {
			cout << s.top() ;
			s.pop() ;
			}
	 
	
}
