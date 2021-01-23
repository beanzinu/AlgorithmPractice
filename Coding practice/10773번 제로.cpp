#include <iostream>
int num[100001] ;
int main() {
	int n ; 
	scanf("%d",&n) ;
	int count = 0 ;
	for(int i = 0;  i < n ; i ++) {
		int temp ; 
		scanf("%d",&temp) ;
		if (temp == 0 ) count-- ;
		else {
			num[count++] = temp ;
		} 
		
	}
	int sum = 0 ;
	for(int i = 0 ; i < count  ; i ++) {
		sum += num[i] ;
	}
	printf("%d",sum) ;
}
