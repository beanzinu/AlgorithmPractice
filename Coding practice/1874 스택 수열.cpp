#include <iostream>
#include <stack> 
using namespace std;
	stack<int> v ; 
 	
 	
 	
 	
int main (void) {
	int n ;
	scanf("%d",&n) ;
	
	char ans[n+1] ; // +,- 표시  
	int num =0;
	
	int j =1 ;
	bool no = true ;
	
	for(int i=0; i < n ; i++) {
	
		int temp ;
		scanf("%d",&temp) ;
		
		int top ;
		if(!v.empty() ) {
			top = v.top() ;		}
		else  top = 0 ;
		
		if (top>=temp && !v.empty()) {
			
			if ( top == temp) {
			v.pop() ;
			ans[num++] = '-' ;
			continue ; 
			}
			else {  // 안되는 경우   
				
				no = false ;
			}
			
		} 
		else if ( top < temp  ) { // v.top() < temp  
		  
		                
		while (j <= temp && j <= n) {
		
			v.push(j++) ; 
			ans[num++] = '+' ;		
			if ( v.top() == temp) {
				v.pop() ; ans[num++] = '-' ; 
			}	
		}  
			} // else  if
		else cout << "error" << endl ;
	

		
	}    // i
	if ( no )
	for (int i=0; i < num ; i ++) {
		printf("%c\n",ans[i]) ;
	}
	else printf("NO") ;
	
}



