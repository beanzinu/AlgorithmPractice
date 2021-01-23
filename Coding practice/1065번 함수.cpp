#include <stdio.h>
int count ;
int main() {
	int N; 
	scanf("%d",&N) ;
	
	for (int i=1; i<=N ; i++) {
		if ( i >= 1 && i <= 9) count++ ;
		else if (i>= 10 && i<=99) {
			count ++ ;
			int a = i/10 ;
			int b = i%(a*10) ;
			int c = 2*b-a ;
			int number = a*100+b*10+c ;
			if ( (c >=0 && c<=9) && number <= N) count++ ;
		}
		else break;
	}
		
		printf("%d",count) ;
		return 0;
	
	
}
