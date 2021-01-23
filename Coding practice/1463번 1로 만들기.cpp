#include <stdio.h>
#include <queue>
using namespace std;
int X ;
int count ;
bool c[2] ;
int MIN = 1000001 ;
queue<pair<int,int > > q ;
int main() {
	scanf("%d",&X) ;
	
	while(true) {
		if ( X == 1) {
			MIN = 0 ; break;
		}
		if ( X == 3  ) {
			if ( MIN > count+1) MIN = count +1 ;  c[0] = true ; c[1] = true ;
		}
		if ( X == 2) {
			if ( MIN > count+1) MIN = count +1 ; c[0] = true ; c[1] = true ; 
		}
		if (X % 3 == 0 && c[0] == false ) {
		q.push(make_pair(X/3,count+1)) ; c[0] = true ;
		}
		if ( X % 2 == 0 && c[1] == false) {
		q.push(make_pair(X/2,count+1)) ; c[1] = true ;
		}
		if (c[0]!=true || c[1]!= true) {
		X -- ; count++ ; 
		}
		else{
			if ( q.empty()) break; 
 			X = q.front().first ;
			count = q.front().second ;	
			q.pop() ;
			c[0]= false ; c[1] = false ;
		}		
	}
	printf("%d",MIN) ;

	
}
