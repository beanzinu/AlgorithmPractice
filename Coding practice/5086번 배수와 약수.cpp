#include <stdio.h>

int n,m ;
int main() {
	while (true) {
		scanf("%d %d",&n,&m) ;
		if ( n== 0 && m == 0 ) break ;
		
		if ( m % n == 0 ) printf("factor\n") ;
		else if ( n % m == 0) printf("multipe\n") ;
		else printf("neither\n") ;
	}
	
	
	
}
