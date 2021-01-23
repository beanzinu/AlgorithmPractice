#include <stdio.h>

int N ; //" N "kg of sugar
int d[5001] ;


int main() {
	scanf("%d",&N) ;
	d[3]=1,d[5]=1 ;
	for (int i = 6; i<=N ; i++) {
		if (d[i-3]==0 && d[i-5]==0) continue;
		if (d[i-3]!=0) d[i] = d[i-3]+1 ;
		if (d[i-5]!=0) {
			if (d[i] == 0 || d[i-5]+1 < d[i]) d[i] = d[i-5] + 1;
		}
	}
	printf("%d",d[N]? d[N]:-1) ;

}
