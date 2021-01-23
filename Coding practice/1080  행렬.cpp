#include <iostream> 

using namespace std;
int count ;
bool err ;
char change(char a) {
	if (a == '0') a= '1' ;
	else a= '0' ;
	
	return a; 
}

int main() {
	int N, M ;
	scanf("%d %d",&N,&M) ;
	char arr1[N][M+1] ;
	char arr2[N][M+1] ;
	
	for(int i=0 ; i < N ; i++) {
		scanf("%s",arr1[i]) ; 
	}
	for(int i=0 ; i < N ; i++) {
		scanf("%s",arr2[i]) ; 
	}
	// reverse 
	int col,row =0 ;
	while (1) {
	if ( col+2 <= N-1 && row+2 <= M-1) {
		if (arr1[col][row] != arr2[col][row]) {		
		for (int i= col ; i<= col+2 ; i++) {
			for (int j=row ; j <=row+2 ; j++) {
				 arr1[i][j] = change(arr1[i][j]) ;
			}
		}
		count++ ;
		}
		if (row +2 <= M-1 ) row++ ;
		}
		else if ( col+2 <= N-1 && row+2 > M-1) {
			col++; row= 0;
		}
		else if ( col+2 > N-1  ) break ;
	} // while(1)
	for (int i =0 ; i< N ; i++){
		for (int j=0 ; j < M ; j++) {
			if ( arr1[i][j] != arr2[i][j] ) err = true ;
		}
	}
	if (err) printf ("-1") ;
	else printf ("%d",count) ;
		
}
