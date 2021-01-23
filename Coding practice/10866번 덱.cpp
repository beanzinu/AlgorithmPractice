#include <iostream>
#include <queue>
using namespace std ;
queue<int> q1 ;
queue<int> q2 ;

int main() {
	int n;
	cin >> n ;
	
	
	for(int i= 0 ; i < n ;i ++ ) {
		string input ;
		cin >> input ;
		if (input.compare("push_front")== 0) {
			int number ; cin >> number ;
			
			q2.push(number) ;
			for(int j=0; j < q1.size(); j++){
				int temp ; 
				temp = q1.front() ; q1.pop();
				q2.push(temp) ;
			}
			swap(q1,q2) ;
			queue<int> empty ;
			swap(q2,empty) ;
			
		} // push_front 
		else if (input.compare("push_back")==0) {
			int number; cin >> number;
			q1.push(number) ;
		}
		else if (input.compare("pop_front")==0){
			if (q1.empty()) {
				cout << "-1\n" ;
				continue;
			}
			cout << q1.front() << '\n' ; 
			
			q1.pop();
		}
		else if (input.compare("pop_back")==0) {
			if (q1.empty()) {
				cout <<"-1\n" ;
				continue;
			}
			while (!q1.empty()){
				if (q1.size()==1) {
					cout << q1.front() << '\n' ;
					break;
				}
				int temp =q1.front() ;
				q2.push(temp) ;
				q1.pop();
			}
			swap(q1,q2);
			queue<int> empty;
			swap(q2,empty) ;
		}
		else if (input.compare("size")==0) {
			cout << q1.size() << '\n' ;
		}
		else if (input.compare("empty") == 0 ) {
			if(q1.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (input.compare("front")== 0) {
			if (q1.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q1.front() << '\n' ;
		}
		else{ //back
			if (q1.empty()) {
				cout << "-1\n";
				continue;
			}
		 cout << q1.back() << '\n' ;
		 
		 }
			
		
		
	}  	 // i
	

	
	
} 
