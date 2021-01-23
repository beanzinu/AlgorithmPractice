#include <iostream>
using namespace std;
int T_case ;
int F_case ;
int F_count ;


struct Node{
	string node ; // NODE
	string parent ; // PARENT  
};

Node N[100001] ;

string findParent(Node a){
	if (a.parent.compare(a.node)== 0) return a.node ;
	else {
		for (int i= 0 ; i < F_count ; i++ ){
			if (a.parent.compare(N[i].node)==0) {
				return findParent(N[i]) ; 
				
			} 
		}
		
		
	}
	
	
}
// return a's index
int check(string a) {
	for(int i=0 ; i < F_count ; i++) {
		if (N[i].node.compare(a)== 0) return i ;	
	}
	return -1 ;
}



int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	 
	cin >> T_case ;
	
	for(int i=0 ; i < T_case ; i++) {
		cin >> F_case ;
		
		for(int j=0 ; j < F_case ; j++) {
			string a , b ;
			string temp ; 
			cin >> a >> b ; 
			
			//union
			/* if a , b exist ->  change b.parent to a.parent */
			if (check(a)!= -1 && check(b) != -1 ) {
				string c = findParent(N[check(b)]) ;
				string d = findParent(N[check(a)]) ;
				for(int k=0 ; k < F_count ; k++) {
				if (N[k].parent.compare(c)==0) {
					N[k].parent = d ;
					}
				}
				temp = d ;
			} 
			/* if a exist */
			else if (check(a) != -1) {
				N[F_count].node = b ;
				N[F_count].parent = findParent(N[check(a)]) ;
				F_count++ ;  
				temp = findParent(N[check(a)]) ;
			}
			/* if b exist */
			else if (check(b) != -1) {
				N[F_count].node = a ;
				N[F_count].parent = findParent(N[check(b)]) ;
				F_count++ ;
				temp = findParent(N[check(b)]) ;
			}
			else {
				N[F_count].node = a ; N[F_count].parent = a ;
				F_count++ ;
				N[F_count].node = b ; N[F_count].parent = a ;
				F_count++ ;
				temp = a ;
			}
			
			int count = 0 ;
			for (int k = 0 ; k < F_count ; k++) {
				if(N[k].parent.compare(temp) == 0 ) count++ ; 
			}
			
			cout << count ;
			
			
		} // j (F_case ) 
		
		F_count = 0 ; // initiallize
		
	}
	
	
	 
	
	
	
	
	
}


