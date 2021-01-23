#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
int start;
int c[1000] ;
int d[1000] ;
vector<int> a[1001] ;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true ;
	while(!q.empty() ) {
		int x = q.front();
		q.pop();
		printf("%d ",x) ;
	    for(int i=0 ;i < a[x].size();i++){
	    	int y= a[x][i];
	    	if(!c[y]){
	    		q.push(y);
	    		c[y] =true ;
			}
		}		
	}
		
}

void dfs(int x){
	if (d[x]) return ;
	d[x] = true ;
	printf("%d ",x) ;
	for(int i=0; i < a[x].size();i++){
		int temp = a[x][i] ;
		dfs(temp) ; 
	}
	
	
}
 
int main(void) {
	
 scanf("%d %d %d",&n,&m,&start) ;
 
 for(int i=0; i< m ; i++) {   // 입력 
 	
 	int tem1,tem2 ;
 	
 	scanf("%d %d",&tem1,&tem2) ;
 	
 	a[tem1].push_back(tem2);
 	a[tem2].push_back(tem1);
 }
 
 for(int i=1; i<= n; i++){    // 작은 정점 번호부터 방문   
 	if(!a[i].empty())
 	sort(a[i].begin(),a[i].end() ) ;
 }
 
 dfs(start) ;
 printf("\n") ;
 bfs(start) ;
 return 0; 
	
}
