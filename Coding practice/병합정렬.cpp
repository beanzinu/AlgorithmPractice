/*  6. 10 . 2020
���� ����  
- '���� ����  ' ����� ä���� �˰��� ( �����İ� ����� )
- �־��� ��쿡��  O ( N * log N ) ���� ����

  �ϴ� ������ ������ ���߿� ���ļ� �����ϸ� ��� ??

- �׻� ���� �����ٴ� Ư¡

ex ))   7 6 5 8 3 5 9 1

 7 6 5 8 3 5 9 1
 67 58  35 19
  5678   1359
    13556789

-��ġ�� �ܰ迡�� ������ ���� 
- ���� �迭�� ����������  ����
 
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
		 
		 // ������ �ٴڳ��� ��  
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
 
 //  ����Լ��� ���� �� ��  
 
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

