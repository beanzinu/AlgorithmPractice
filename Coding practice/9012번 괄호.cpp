#include <iostream>
using namespace std ;


int main() {
	int n ;
	scanf("%d",&n) ;
	cin.ignore(256,'\n' ) ;
	string ans[n+1] ;
	int ans_count = 0 ;
	
	char s[51] ;
	char com[51] ;
	for(int i = 0; i < n ; i ++){
		cin.getline(s,51) ;
		int count = 0 ;
		for ( int j = 0;  s[j]!= NULL ; j++){
			if(s[j]== '(') com[count++] = '(' ;
			else {
				if (count == 0 ) {
					count-- ;
				ans[ans_count]="NO"; ans_count ++ ; break ; }
				
				com[count--] = 0 ;
				
			}
			
		} // j 
		
		if ( count > 0 ) {
		 ans[ans_count]="NO" ; ans_count++ ;  }
		if ( count == 0 ) {
			ans[ans_count] = "YES" ; ans_count++;
		}
		
		
		
	}  // i
	for (int i = 0 ; i < ans_count ; i ++) {
		cout << ans[i] << '\n' ;
	}
	
}


