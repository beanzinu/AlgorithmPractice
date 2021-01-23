#include <cstdio>
long long a,b,c ;

long long div(int a,int b,int c) {
	if (b==1) return a ;
	else {
		long long temp = div(a,b/2,c) ;
			if(b % 2 == 0) return (temp*temp)%c ;
			else return ((temp*temp)%c*a)%c ;
		
	}
}

int main() {
	scanf("%ld %ld %ld",&a,&b,&c) ;
	
	printf("%ld",div(a%c,b,c)) ;
	
	
	
}
