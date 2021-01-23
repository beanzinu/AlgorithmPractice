#include <iostream>

int arr[300001] ;
int count ;
int MAX ;
int N , M ;

void choose(int index,int count,int temp) {
	if (count == 3) {
		if (temp > MAX && temp <=M)
		MAX = temp ; 
		return ;
	}
	
	
	for(int i=index ; i < N ; i++) {
		choose(i+1,count+1,temp+arr[i]) ; 
	}
	
	
}


int main(void){
	scanf("%d %d",&N,&M) ;
	for (int i =0; i < N ; i++) scanf("%d",&arr[i]);
	choose(0,0,0) ;
	printf("%d",MAX) ;
}
