#include <stdio.h>
using namespace std;
int Node[51] ;
int Node_count[51] ;
bool c[51] ;
int count ;
int N ;
void deleteNode(int start){
	c[start] = false ;
	for (int i = 0 ; i < N; i++) {
		if(Node[i]==start) {
			deleteNode(i) ; c[i]=false ;
		}
	}
}



int main() {
	scanf("%d",&N) ;
	for(int i=0 ; i<N ;i++) {
	 	int temp ; scanf("%d",&temp) ;
		Node[i] = temp ; c[i] = true;
	}
	
	int del ;
	scanf("%d",&del) ;
	deleteNode(del) ;
	 
	for (int i=0 ; i < N ;i++) {
		if(c[i]==true) {
			Node_count[Node[i]]++;
		}	
	}
	for (int i=0 ;i < N ; i++) {
		if(c[i]==true && Node_count[i]==0) count++ ;
	}
	printf("%d",count) ;
}
