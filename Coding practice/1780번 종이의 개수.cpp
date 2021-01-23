#include <iostream>
using namespace std; 
int N ;
int m1 , zero , p1 ;
int arr[2500][2500] ;
void split(int a,int b,int n) {
	bool FLAG = false ;
	int FIX = arr[a][b] ;
	
	for (int i = a ; i < a + n ; i++) {
		for (int j = b; j < b + n ; j++) {
			if (arr[i][j]!=FIX ) {
				FLAG =true ; break;
			}
		}
		if (FLAG) break;
	}
	if ( !FLAG ) {
		if (FIX == -1) m1++ ;
		else if (FIX == 0 ) zero++ ;
		else p1++;
	}
	else {
		split(a,b,n/3) ;
		split(a,b+n/3,n/3) ;
		split(a,b+2*n/3,n/3) ;
		split(a+n/3,b,n/3) ;
		split(a+n/3,b+n/3,n/3);
		split(a+n/3,b+2*n/3,n/3) ;
		split(a+2*n/3,b,n/3) ;
		split(a+2*n/3,b+n/3,n/3);
		split(a+2*n/3,b+2*n/3,n/3) ;
		
	}
	
}




int main() {
	cin >>  N ;
	
	for(int i= 0 ; i <  N ; i++) {
		for (int j = 0 ; j  < N ;j++) {
			cin >> arr[i][j] ;
		}
	}
	split(0,0,N) ;
	printf("%d\n",m1) ;
	printf("%d\n",zero) ;
	printf("%d\n",p1) ;
	
}
