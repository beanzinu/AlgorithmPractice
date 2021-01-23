#include <cstdio>
int N , M ;
int x1 , x2 ;

int main() {
	scanf("%d %d",&N,&M) ;
	int Psum[N+1] ;
	int temp ;
	
	Psum[0] = 0;
	for(int i=1;i<=N;i++) {
		scanf("%d",&temp) ;
		Psum[i] = Psum[i-1] + temp ;
	}
	for(int i=0;i<M ;i++) {
		scanf("%d %d",&x1,&x2) ;
		printf("%d",Psum[x2]-Psum[x1-1]) ;
		
	}
}
