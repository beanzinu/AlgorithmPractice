#include <stdio.h>
int arr[1001] ;
int d[1001] ;
int N ;

int main() {
	scanf("%d",&N) ;
	
	int temp ;
	for(int i=0; i <  N ; i++) {
		scanf("%d",&temp) ;
		arr[i]  = temp ; 
	}	
	
	for (int i =0 ; i <  N ; i++) {
		if ( arr[i] == 0  ) continue ;
		if ( d[i] == 0 && i != 0) continue ;
		for (int j=i+1 ; j <=i+arr[i] ; j++) {
			
			if (d[j] == 0) d[j] = d[i] + 1 ;
			if ( d[j] > d[i] + 1 ) d[j] = d[i] + 1 ;
			else continue ;
		}
		
	}
	if (d[N-1] == 0 ) printf("-1") ;
	 
	else printf("%d",d[N-1]) ;
	
}
