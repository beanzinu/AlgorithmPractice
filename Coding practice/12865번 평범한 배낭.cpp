#include <stdio.h>
int result ;
int N , K  ;
int W[101] ;
int V[101] ;
int d[101][2] ; 
int main() {
	scanf("%d %d",&N,&K) ;
	int n1,n2 ;
	for (int i = 0 ; i  < N  ;i++) { // input 
		scanf("%d %d",&n1,&n2) ;
		W[i] =n1 ; V[i] = n2 ;
	}
	for (int i = 0 ; i  < N ; i++) {
		int W_MAX = 0 , V_MAX = 0 ;
		for (int j= i-1 ; j >= 0 ; j--) {
			if (d[j][0]!= 0) { // �ִ� K �� ���� W�� �ѱ��� ���� ��  
				if (d[j][0] + W[j] <= K && d[j][1] > V_MAX ){
					W_MAX = d[j][0] ; V_MAX = d[j][1] ;
				}
			}
			// always 
			if ( W[j] + W[i] <= K && V[j] > V_MAX) {
				W_MAX = W[j] ; V_MAX = V[j] ;
			}
			
		} //j 
		d[i][0] = W[i] + W_MAX ; 
		d[i][1] = V[i] + V_MAX ;
		if ( d[i][1] > result ) result = d[i][1] ;
		
	} // i 
	printf("%d",result) ;
}
