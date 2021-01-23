#include <iostream>
int count_0 ;
int count_1 ;

void check(int X) {
	
	if(X==0) count_0++ ;
	else if (X==1) count_1++;
	else {
		int X1 = X - 1;
		int X2 = X - 2;
		check(X-1) ; check(X-2) ;
	}
}

int main() {
	
	int T ;
	scanf("%d",&T) ;
	while(T--) {
		int N;
		scanf("%d",&N) ;
		check(N) ;
		printf("%d %d",count_0,count_1) ;
		count_0=0;count_1=0;
	}
	
	
}
