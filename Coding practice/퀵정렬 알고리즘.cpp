/* 퀵 정렬 알고리즘  
- 분할 정복 알고리즘 : 시간 복잡도  O (N* logN ) 
- log N 이라는 것은 매우 작으므로 N * logN 은 매우 빠른 속도

특정한 값을 기준으로 큰숫자와 작은 숫자를 나누면 어떨까 ?? 

기준 ? 피벗 (PIVOT )

ex ) 3 7 8 1 5 9 6 10 2 4

pivot :3     3 7 8 1 5 9 6 10 2 4   왼쪽에서  pivot(3) 보다 큰 숫자 , 오른쪽에서 pivot(3)보다 작은 숫자 
"			 3 2 8 1 5 9 6 10 7 4    switch 해줌. 
             3 2 1 8 5 9 6 10 7 4     8 과 1 이 엇갈림 .  
             1 2 3 8 5 9 6 10 7 4   pivot과 1을 switch.
			 -------------------- pivot (3 ) 기준으로 분할이 됨
pivot : 1	 1 2 3 8 5 9 6 10 7 4
			 1 2 3 8 5 9 6 10 7 4  1과 2가 엇갈림 . pivot(1 )과 1을 switch - 결과적으로 그대로		
pivot : 8    1 2 3 8 5 4 6 10 7 9
             1 2 3 8 5 4 6 7 10 9
             1 2 3 7 5 4 6 8 10 9
               .....
               
구현  및 한 계점 분석 > 
int number = 10; 
int data [10] = {1,10 ,5 ,8 , 7 ,6 ,4 ,3 ,2 ,9 }
  
  start > = end   return ; (원소가 1개인 경우 ) 
  
  key = start ;   key 는 pivot  
  
  int i = start +1 ;
  int j = end ;  
  int temp;
  
  while ( i <= j  )  {
     while ( data[i] <= data[key] ) {
     i++; }
     while ( data[j] >= data[key]  &&  j > start ) {
     j++; } 
     if ( i > j ) {
     temp = data[j]; 
     data[j] = data[key] ;
     data[key] = temp ;
       }
      else { 
      temp =data[j] ;
      data[j]=data[i];
      data[i] = temp ; 
       }
   }
   
   한계점 : 최악 시간 복잡도는 O  ( N*2 ) 일수도 있다.
   
   */ 
   
#include <cstdio>  
int array[1000001] ,num ;

void quicksort(int *array,int start,int end){
	
	if (start >= end) return ;
	
 	int key = start;
	int i = start +1 , j= end , temp ;
	
	while ( i<= j ) {
		while (array[i]<= array[key]){
			i ++ ;
		}
		while (array[j]>=array[key] && j  > start ) {
		    j-- ;
		}
		if ( i > j) { 
		   temp = array[j] ;
		   array[j]  = array[key] ;
		   array[key] = temp; 
		}
		else {
			temp = array[i] ;
			array[i]  = array[j] ;
			array[j] = temp ; 
		}
		
	}
	
	quicksort(array,start, j-1) ;
	quicksort(array,j+1,end) ; 
	
	
}  
   
   
int main(void) {
	scanf("%d",&num) ;
	
	for(int i=0; i< num; i++) {
		scanf("%d",&array[i]) ;
	}
	
	quicksort(array,0,num-1) ;
	
	for(int i=0; i< num; i++) {
		printf("%d\n",array[i]) ;
	}
	
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
