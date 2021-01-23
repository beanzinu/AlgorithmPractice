/*  6. 10 . 2020
병합 정렬  
- '분할 정복  ' 방법을 채택한 알고리즘 ( 퀵정렬과 비슷함 )
- 최악의 경우에도  O ( N * log N ) 보장 가능

  일단 반으로 나누고 나중에 합쳐서 정렬하면 어떨까 ??

- 항상 반을 나눈다는 특징

ex ))   7 6 5 8 3 5 9 1

 7 6 5 8 3 5 9 1
 67 58  35 19
  5678   1359
    13556789

-합치는 단계에서 정렬을 수행 
- 정렬 배열은 전역변수로  선언
 
 */
 
 #include <stdio.h> 
 
 int number;
 int sorted[1000001];
 int input[1000001] ;
 
 void merge(int a[],int m,int middle,int n) {
 	int i= m ;
 	int j= middle +1 ;
 	int k= m ;
 	
 	while (i <= middle && j <= n ){
 		if (a[i] <= a[j] ) {
 			sorted[k] = a[i] ; 
 			i++;
		 }
 		else{
 			sorted[k] = a[j] ;
 			j++;
		 }
		 k++ ;
	}
		 
		 // 한쪽이 바닥났을 때  
  		if (i > middle ){
  			for ( int t=j; t <= n ; t++){
			  sorted[k] = a[t] ;
			  k++;
			  }
		     }
		else {
			for ( int t=i; t <=middle ; t++){
			  sorted[k] = a[t] ;
			  k++;
			  }
		}
  		
  		for(int t=m; t<=n ; t++)
  		  a[t] = sorted[t] ;
	 	
 } 
 
 //  재귀함수를 통한 정 렬  
 
void mergeSort(int a[],int m, int n){
	
	
	if (m < n){
		int middle = (m+n)/2 ;
	mergeSort(a,m,middle);
	mergeSort(a,middle+1,n);
	merge(a,m,middle,n) ;
     } 	
}


int main(void){
	scanf("%d",&number) ;
	
	for(int i=0;i < number ; i++){
		scanf("%d",&input[i]) ;
	}
	
	mergeSort(input,0,number-1) ;
	
	for(int i=0;i<number; i++) {
		printf("%d\n",input[i]);
	}

} 

