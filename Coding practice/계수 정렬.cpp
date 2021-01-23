/* 계수 정렬

 '범위 조건 ' 이 있는 경우에 한해서 굉 장히 빠르 알고리즘
 
 속도 : O ( N ) 
 
 크기를 기준으로 갯수를 세면 어떨까 ?
 
 크기1 크기2 크기3 크기4 크기5 
 
 
 
 */
 
 #include <stdio.h>
 
 int main(void) {
 	int temp;
 	int count[5] ;  // 범위가 5이하일 경우 
 	int array[30] = {
	 1,3,2,4,3,2,5,3,1,2,
	 3,4,4,3,5,1,2,3,5,2,
	 3,1,4,3,5,1,2,1,1,1};
 	for ( int i=0; i<5 ; i++) {
 		count [i] = 0 ;
	 } // 배열 초기화
	 for ( int i=0; i<30; i++) {
	 	count[array[i]-1] ++ ;
	 } 
	 for (int i=0; i< 5 ; i ++) {
	 	if(count[i]!=0) {
	 		for(int j=0; j < count[i]; j++)
	 		  printf("%d",i+1);
		 }
	 }
	 
	 return 0;
 } 
