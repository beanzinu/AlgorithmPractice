#include <iostream>

using namespace std;

int count[10001] ;   // 전역변수로 만들면 0으로 초기화 됨. 
int number ;
int main(void) {
	
	scanf("%d", &number) ;
	for(int i=0; i < number ; i++){
		int temp;
		scanf("%d",&temp) ;
		count[temp-1] ++ ;
				
	}
	 
	for (int i=0; i< 10001 ; i++) {   // num 보다 10001 이 시간이 더 적게걸림 ?? 
	
		while(count[i]!= 0) {
			printf("%d\n",i+1) ;
			count[i] -- ;	
		    }
		}
	}  
	  
	    
	
	

