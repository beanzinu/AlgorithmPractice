#include <stdio.h>
#include <algorithm>
using namespace std; 
int answer ;
int main() {
	int N ;
	scanf("%d",&N) ;
	while(N--) {
		char s[101] ;
		char a[101] ;
		int count =0 ;
		int temp ;
		scanf("%s",s) ;
		for (int i=0 ; s[i]!='\0' ; i++) {
			a[count++] = s[i] ;
			for (int j= i ; s[j] == s[i] ; j++,temp = j) ; 
			i = temp-1 ;
		}
		sort(a,a+count) ;
		printf("%s",a) ;
		answer++;
		for (int i =0 ; i < count-1 ; i++) {
		 if (a[i] == a[i+1] ) {
		 	answer--; 	break;
		 }
		}
	}
	printf("%d",answer) ;
	
}
