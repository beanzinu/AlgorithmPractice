#include <stdio.h>
int count ;
int x ;
int main(void) {
	int rep =71 ;
	bool white = true ;
	
	do {
	if( x== 8 ) {
		white =!white ; x=0;
	}
	
	char temp = getchar() ; 
	if (temp == '\n') continue;
		if(white) {
			printf("w") ;
			if ( x%2 == 0 && temp == 'F') count++ ; 
		}
		else {
			printf("b") ;
			if( x%2 == 1 && temp == 'F') count++ ;
		}
		x++ ; 
	
}while(rep--) ;

printf("%d",count) ;

}
