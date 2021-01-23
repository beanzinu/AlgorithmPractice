#include <iostream>
#include <vector>

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
int findParent(int parent[],int a,int b) {
	a=getParent(parent,a) ;
	b=getParent(parent,b) ;
	if (a==b) return 1;
	return 0 ;	
}  

vector<int> v[201] ;



int main() {
	int n, m ;
	cin >> n ;
	cin >> m ; 
	int trip[ m+1] ;
	int parent[n+1] ;
 	for(int i=0; i< n;i++) {
		parent[i] = i ;
	}
	
	for(int i=0; i< n ; i++) {
	    
			for(int j= 0; j < n ; j ++ ){
			int temp;
			scanf("%d",&temp) ;
			v[i].push_back(temp) ;
	               }
	}
	
	
	for(int i=0; i< n; i++) {     // ¿¬°á  
		for(int j=0; j<n ; j++){
			if(v[i][j] ==1 ){
				unionParent(parent,i,j) ;
				}
			} 
		}
		
	for(int i=0;i<m;i++) {  // ¿©Çà °è È¹    
		scanf("%d",&trip[i]) ;				
	}	
	for(int i=0; i < m-1 ; i++) {
		if(findParent(parent,trip[i]-1,trip[i+1]-1)) continue;
		else {
			cout << "NO" ;
			return 0;
		}
	}
	cout << "YES" ;	
		
	}
	
	

