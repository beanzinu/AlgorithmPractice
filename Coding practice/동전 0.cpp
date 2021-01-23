#include <stdio.h>

int main(int args,char** argv){
	
	int N, K ;
	
	int count=0 ; 
	
	scanf ("%d %d",&N,&K);
	
	int num[N];
	
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	
	for(int i=N-1;i>=0;i--){
		if( num[i]  > K  ) continue;
		while(num[i] <= K ) {
			K= K - num[i];
			count ++ ;
		}
	}
	printf ("%d",count);

}
