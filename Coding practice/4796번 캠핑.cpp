#include <stdio.h>


int L , P  , V ;
int answer ;
int main() {
	int num = 1;
	while(true) {
	
	scanf("%d %d %d",&L,&P,&V ) ;
	if ( (L == 0 && P == 0 ) && V == 0)  break;
	
	while(true) {
	if ( P <= V) {
		answer= answer + L ;
		V = V - P ;
	}
	else {
		if ( L > V ) answer = answer +  V ;
		else answer = answer + L ;
		break ;	
	}
	}
	
	// output
	printf("Case %d: %d\n",num++,answer) ;
	answer = 0 ;
	}
	
}
