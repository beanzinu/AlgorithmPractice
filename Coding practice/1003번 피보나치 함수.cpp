#include <stdio.h>


int T ; // test_case
int d[41][2] ; // dp

int main() {
	scanf("%d",&T) ;
	int N ;
	d[0][0] = 1; d[0][1] = 0;
	d[1][0] = 0; d[1][1] = 1;
	for (int i=2 ; i<= 40 ; i++) {
		d[i][0] = d[i-1][0] + d[i-2][0] ;
		d[i][1] = d[i-1][1] + d[i-2][1] ; 
	}
	while(T--) {
		scanf("%d",&N) ;
		printf("%d %d'\n",d[N][0],d[N][1]) ;
	}
	
}


