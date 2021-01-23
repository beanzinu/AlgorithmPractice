#include <iostream>
#include <algorithm>
using namespace std;

int num[100001] ;
bool search(int start,int end,int x) {
	int mid ;
	while ( start <= end ) {
		mid = (start+end) / 2 ;
		if (num[mid] == x ) return true ;
		else if (num[mid] > x) end = mid-1 ;
		else if (num[mid] < x) start=mid+1 ; 
	}
	return false ;
	
}




int main() {
	int N ;
	scanf("%d",&N) ;
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]) ;
	}
	sort(num,num+N) ;
	int M ;
	scanf("%d",&M) ;
	for(int i=0; i<M ;i++) {
		int temp ; 
		scanf("%d",&temp) ;
		if (search(0,N-1,temp)== true  ) printf("1\n") ;
		else printf("0\n") ;
	}
	
}
