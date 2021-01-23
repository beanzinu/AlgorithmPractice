#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101] ;
int b[101] ;
bool compare (int a, int b) {
	return a > b;
}
int main() {
	int N ;
	scanf("%d",&N) ;
	
	for (int i=0; i<N ;i++) scanf("%d",&a[i]) ;
	for (int i=0; i<N ;i++) scanf("%d",&b[i]) ;
	
	sort(a,a+N) ;
	sort(b,b+N,compare) ;
	
	int sum = 0;
	for(int i=0; i<N ;i++) {
		sum= sum + a[i]*b[i] ;
	}
	
	printf("%d",sum) ;
	
}
