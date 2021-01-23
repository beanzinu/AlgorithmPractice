#include <iostream>
#include <queue>
using namespace std;
queue<int> q ;
int main () {
	cin.tie(NULL) ;
	int n ;
	cin >> n ;
	for (int i =1 ; i <= n ; i ++){
		q.push(i) ;
	}
	 
	bool odd= true ;
	
	
	while(q.size() != 1){
		
		if (odd) {
			q.pop();
			odd = false ;
		}
		else {
			int temp = q.front() ;
			q.pop() ;
			q.push(temp) ;
			odd = true ; 
		}
		
		
		
	}
	
	cout << q.front() ;
	
} 
