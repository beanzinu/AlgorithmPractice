#include <stdio.h>
#include <algorithm>
using namespace std; 
int main() {
	
	int N ; 
	scanf("%d",&N) ;
	int Time[N+1] ;
	for(int i=0; i  < N ; i++) {
		scanf("%d",&Time[i]) ;
	}
	sort(Time,Time+N) ;
	int MIN = 0;
	int count = 1;
	for(int i= N-1 ; i>=0 ; i--) {
		MIN = MIN + Time[i] * count ++ ; 
	}
	printf("%d",MIN) ;
	
} 
