/* �� ���� �˰���  
- ���� ���� �˰��� : �ð� ���⵵  O (N* logN ) 
- log N �̶�� ���� �ſ� �����Ƿ� N * logN �� �ſ� ���� �ӵ�

Ư���� ���� �������� ū���ڿ� ���� ���ڸ� ������ ��� ?? 

���� ? �ǹ� (PIVOT )

ex ) 3 7 8 1 5 9 6 10 2 4

pivot :3     3 7 8 1 5 9 6 10 2 4   ���ʿ���  pivot(3) ���� ū ���� , �����ʿ��� pivot(3)���� ���� ���� 
"			 3 2 8 1 5 9 6 10 7 4    switch ����. 
             3 2 1 8 5 9 6 10 7 4     8 �� 1 �� ������ .  
             1 2 3 8 5 9 6 10 7 4   pivot�� 1�� switch.
			 -------------------- pivot (3 ) �������� ������ ��
pivot : 1	 1 2 3 8 5 9 6 10 7 4
			 1 2 3 8 5 9 6 10 7 4  1�� 2�� ������ . pivot(1 )�� 1�� switch - ��������� �״��		
pivot : 8    1 2 3 8 5 4 6 10 7 9
             1 2 3 8 5 4 6 7 10 9
             1 2 3 7 5 4 6 8 10 9
               .....
               
����  �� �� ���� �м� > 
int number = 10; 
int data [10] = {1,10 ,5 ,8 , 7 ,6 ,4 ,3 ,2 ,9 }
  
  start > = end   return ; (���Ұ� 1���� ��� ) 
  
  key = start ;   key �� pivot  
  
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
   
   �Ѱ��� : �־� �ð� ���⵵�� O  ( N*2 ) �ϼ��� �ִ�.
   
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
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
