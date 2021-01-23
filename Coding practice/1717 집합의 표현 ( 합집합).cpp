#include <iostream>
#include <queue>

using namespace std;
int getParent(int parent[],int x) {
	if(parent[x] == x) return x ;
	return parent[x] = getParent(parent,parent[x]);
}
int unionParent(int parent[],int a,int b) {
	a=getParent(parent,a) ;
	b=getParent(parent,b) ;
	
	if ( a < b) return parent[b] = a ;
	return parent[a] = b ;
	 	
}
int findUnion(int parent[],int a,int b) {
	a=getParent(parent,a) ;
	b=getParent(parent,b) ;
	if (a==b) return 1;
	return 0 ;	
}  

int main() {
	
	
	
	
	int n,m ;
	scanf("%d %d",&n,&m) ;
	
	int set[m] ;
	int setnum=0;
	
	int parent[n+2] ;
	
	for(int i=0;i<n+1;i++) {
		parent[i] = i ;
	}
	
	for(int i=0; i < m ; i ++) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c) ;
		if ( a== 0) 
		  unionParent(parent,b,c) ;
		else {	  // 1 ÀÏ ‹š  
			if (findUnion(parent,b,c)) {
				set[setnum] = 1; setnum++;
			}
			else {
				set[setnum] = 0; setnum++ ;
			}; 
		} 
		     	
	}
	
	for(int i=0; i< setnum;i++) {
		if(set[i]==1) printf("yes\n") ;
		else printf("no\n");
	}
	
	
}
