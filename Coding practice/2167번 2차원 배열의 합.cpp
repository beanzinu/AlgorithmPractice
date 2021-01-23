#include <cstdio>

int N , M , K;
int x1,y1,x2,y2 ;
int input;

int main() {
	scanf("%d %d",&N,&M) ;
	int Psum[N+1][M+1] ; 
	for (int i=1; i<=N ;i++ ) {
		for(int j=1; j<=M ; j++) {
			scanf("%d",&input) ;
			if (j==1) Psum[i][j] = input ;
			else Psum[i][j] = Psum[i][j-1] + input ; 
		}
	}
	scanf("%d",&K) ;
	while(K--){
		int answer = 0 ;
		scanf("%d %d %d %d",&y1,&x1,&y2,&x2) ;
		for (int i=y1 ; i<=y2 ; i++) {
			if (x1-1 == 0) answer = answer + Psum[i][x2] ;
			else answer = answer + Psum[i][x2] - Psum[i][x1-1] ;
		}
		printf("%d\n",answer) ;
	}
	
	
}
