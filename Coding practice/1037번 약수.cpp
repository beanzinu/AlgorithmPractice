#include <stdio.h>
int number ;
int MAX= 0 ; int MIN = 1000001 ; 
int main() {
		scanf("%d",&number) ;
		int i = 0 ;
		for(int i = 0 ; i  < number ; i++) {
			int temp ; 
			scanf("%d",&temp) ;
			if ( temp  > MAX ) MAX = temp ;
			if ( temp < MIN ) MIN = temp ;
			
		}
		printf("%d",MIN*MAX) ;
		
} 
