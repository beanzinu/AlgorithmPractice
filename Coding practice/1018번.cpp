#include <iostream>
using namespace std; 
int N , M ;
int temp , MIN = 2501 ;
char arr[51][51] ;
char W = 'W' ; char B = 'B' ;
char ans[8][8] = {{W,B,W,B,W,B,W,B},
{B,W,B,W,B,W,B,W } ,
{W,B,W,B,W,B,W,B} ,
{B,W,B,W,B,W,B,W} ,
{W,B,W,B,W,B,W,B} ,
{B,W,B,W,B,W,B,W} ,
{W,B,W,B,W,B,W,B} ,
{B,W,B,W,B,W,B,W} } ;
int check(int a,int b) {
	int n1=0, n2=0 ;
	for(int i=a; i<a+8 ; i++) {
		for(int j=b ; j<b+8 ; j++) {
			cout << arr[i][j] ;
			if(arr[i][j]==ans[i][j]) n1++ ;
			else n2++ ;
		}
		cout << '\n' ;
	}
	if ( n1 > n2 ) return n2 ;
	else return n1 ;
	
	
}

void result() {
	for (int i=0 ; i+7 <  N ; i++ ) {
		for (int j =0; j+7 < M ; j++) {
			temp = 	check(i,j) ;
			if ( MIN > temp) MIN = temp ;
		}	
	}
} 

int main() {
	scanf("%d %d",&N,&M) ;
	for (int i =0 ; i < N ;i++ ) {
		scanf("%s",arr[i]) ;
	}
	result() ;
	printf("%d",MIN) ;
}
 

 
