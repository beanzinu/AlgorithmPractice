#include <iostream>


int N , M ;
int arr[9] ;
void print(int index,int count) {
	if (count == M) {
		for (int i =0 ; i < count-1 ; i++) {
			if (arr[i] <= arr[i+1]) ;
			else return ;
		}
		
		for(int i = 0 ; i<  count ; i++)
		printf("%d ",arr[i]) ;
		printf("\n") ;
		return ;
	}
	
	for(int i = 1 ; i <= N ; i++) {
	
		arr[count] =  i ;
		print(i,count+1) ;
		
	} 
	
}


int main () {
	scanf("%d %d",&N,&M) ;
	print(0,0) ;
}
