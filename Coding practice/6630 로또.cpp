#include <iostream>

using namespace std; 
#define MAX 6  

int answer[MAX] ;
int arr[13] ;
int K ;

void print(int idx1,int idx2) {
	if (idx1==MAX) {
		for(int i=0 ; i< MAX ; i++)
		printf("%d ",answer[i]) ;
		printf("\n") ;
	}
	else {
		for (int i=idx2 ; i < K ;i++) {
			answer[idx1] = arr[i] ;
			print(idx1+1,i+1) ; 
		}
	}
	
}



int main() {
	while(true) {
		scanf("%d",&K) ;
		if (K==0) break;
		for(int i=0; i< K ; i++) scanf("%d",&arr[i]) ;
		print(0,0) ;
		printf("\n") ;
	}
	
}
