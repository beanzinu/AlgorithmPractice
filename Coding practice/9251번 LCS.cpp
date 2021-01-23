#include <stdio.h>



int MAX ;

char A[1001] ;
char B[1001] ;

void dp(int A_start,int B_start,int count) {
	if ( MAX < count) MAX = count ;
	for(int i=A_start+1 ; A[i] !='\0' ; i++ ){
		int B_limit = -1 ;
		for(int j=B_start+1 ; B[j] != '\0' ; j++){
			if (A[i] == B[j] && j > B_limit) {
			B_limit = j ;	
			dp(i,j,count+1) ; break ; }
		}
	
	}
}


int main() {
	scanf("%s",&A) ;
	scanf("%s",&B) ;
	
	dp(-1,-1,0) ;
	
	printf("%d",MAX);
}

