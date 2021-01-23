#include <stdio.h>
int n ;
int temp ; // input
int sum = -1001 ;  // result ;
int sum_temp ;
int minus ; // minus
bool check = false ;

int main() {
	scanf("%d",&n) ;
	while(n--) {
		scanf("%d",&temp) ;
		
		if ( temp >= 0 ){
		check= true ;	
		sum_temp = sum_temp + temp ;
		}
		else { // minus
			
			
			minus = temp ;
			
			if ( minus > sum ) sum = minus ; 
			if (sum_temp > 0 && sum < sum_temp) sum = sum_temp ;
			
			if ( sum_temp + minus >=0 ) sum_temp = sum_temp + minus ;
			else sum_temp= 0 ;
		}
		
		
	}
	if ( sum_temp > 0 && sum < sum_temp) sum = sum_temp ;
	
	if (check==true && sum <= 0 ) printf("0") ;
	else printf("%d",sum) ;
	
	
	
	
}
