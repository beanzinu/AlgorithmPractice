#include <cstdio>

int T , K ;
int sum ;


int main() {
	scanf("%d",&T) ;
	
	while(T--) {
		scanf("%d",&K) ;
		int d[K+1] = {0, } ; 
		bool c[K+1]  = {0, } ; 
		for(int i = 0 ; i <  K  ;i ++) {
			scanf("%d",&d[i]) ;
		}
		int rep = K-1 ;
	 	while ( rep--) {
	 		int min1 =10001 ,min2 = 10001 ;
	 		int index1,index2 ;
	 		for(int i =0 ; i < K ; i++) {
	 			if (c[i]==true) continue ;
	 			if ( min1 > d[i] ) {
	 				min1 = d[i] ;
	 				index1 = i ;
				 }
			 }
	 		c[index1] = true ;
	 		for(int i =0 ; i < K ; i++) {
	 			if (c[i]==true) continue ;
	 			if ( min2 > d[i] ) {
	 				min2 = d[i] ;
	 				index2 = i ;
				 }
			 }
	 		int temp = min1 + min2 ;
	 		sum= sum + temp ;
	 		d[index1] = temp ; 
	 		d[index2] = temp ;
		 }
	 	
	 	
	 	
	 	
	 	
	 	
		printf("%d\n",sum) ;
		sum = 0 ;
	} // T
	
	
	
}
