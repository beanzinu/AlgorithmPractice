#include <stdio.h>
#include <algorithm> 
using namespace std;

int N , K  ;
int answer ;

struct jew{
	int weight ;
	int value ;

};

bool compare(jew a,jew b) {
	return a.value > b.value ;
}
bool compare2(int a ,int b) {
	return a > b ;
}

int main() {
scanf("%d %d",&N,&K) ;
jew A[N+1] ;
int B[K+1] ;
bool C[K+1] = { 0, } ;

for (int i = 0 ; i<N ; i++) {
	
	scanf("%d %d",&A[i].weight,&A[i].value) ;
	
}

sort(A,A+N,compare) ;

for (int i=0 ; i< K ; i++) {
	scanf("%d",&B[i]) ;	
	
}
sort(B,B+K,compare2) ;


int j = 0 ;
int i = 0 ;
while(  i != N ) {
	int temp = -1 ;
	while (A[i].weight <= B[j] ) {
		if (C[j] == false) temp = j ; 
		j++;
	}
	if (temp != -1 ) {
		C[temp] = true ;
		answer = answer + A[i].value ; 
	}
	i++ ;
	j = 0;
}

printf("%d",answer) ;
	
	
}
