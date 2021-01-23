/* 힙 정렬
- 힙 트리 구조 ( Heap Tree Structure )

힙을 이용하면 정렬 이 빠르지 않을까 ??

힙 ?? 이진 트리 ??
- 완전 이진 트리 
  -  ' 최대 힙 '  은 '부모 노드'가 '자식 노드 ' 보다 큰 힙 
  - 최대 힙이 붕괴되는 경우 ? 자식노드와 부모노드로 바꾼다 ! 

힙 정렬을 수행하기 위해서 힙 생성 알고리즘을 사용 !
힙 생성 알고리즘의 시간 복잡도 O( log N ) 

전체 트리를 힙으로 만드는 시간은 사실상 O ( N )   1/2* N * log N

//
배열에 트리를 삽입 
0 1 2 3 4 5 6 7 8
7 6 5 8 3 5 9 1 6

  Heapify -> 첫번째원소와 마지막 원소를 바꿈 -> 마지막 원소를 제외하고 Heapify - > '''
  
  
  한번의 Heapify -> log N 
  전체 원소 - > N
  
  시간 복잡도 N * log N
  
  
 */
 
 
 #include <stdio.h> 
 
 int number = 9;
 int heap[9] = { 7 , 6, 5 , 8 , 3 , 5, 9 ,1 ,6} ;
 
int main(void) {
 	// 먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다. 
 	for(int i=1; i < number ; i ++) {
 		int c = i ;
		 do{
		 	int root = (c-1)/2 ;
		 	if (heap[c] > heap[root]) {
		 		int temp=heap[c];
		 		heap[c]=heap[root];
		 		heap[root]= temp ;
			 }
		 	c= root ;
		 } while ( c!= 0);
 		
	 }
 	
 // 크기를 줄여 가며 반복적으로 힙을 구성 
 for (int i= number-1; i>=0;i--){
 	int temp = heap [0] ;
 	heap[0] = heap[i] ;
 	heap [i] = temp ;
 	int root =0 ;
 	int c= 1;
 	
 	do {
 	   c= 	2 * root +1 ;
 	     // 자식 중에 더 큰 값 찾 
 	   if (heap[c] < heap[c+1]&& c < i-1){
 	   	 c ++ ;
		}
 		// 루트 보다 자식이 더 크다면 교환
		if(heap[root]< heap[c]&& c < i){
			int temp= heap[root] ;
			heap[root] = heap [c] ;
			heap[c] = temp ;
		} 
		root = c ;
	 } while ( c < i) ;
 }	
 
for( int i=0; i< number ; i ++) {
	
	printf("%d", heap[i]); 
	
	}
 
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 } 
