/* 깊이 우선 탐색 (DFS) 

 - 스택 ( Stack ) 이 사용됨.
 
 1. 스택의 최상단 노드를 확인합니다.
 2. 최상단 노드에게 방문하지 않은 인접 노드가 있으면 그노드를 스택에 넣고 방문처리합니다. 방문하지 않은 노드가 없으면 최상단 노드를 뱸
  
  
  */
  
#include <iostream>
#include <vector>

using namespace std;

int number = 7 ;
int c[7] ; // 방문처리
vector<int> a[8] ;

void dfs(int x) {
	if( c[x]) return ;
	c[x] = true ;
	cout << x << ' ';
	for(int i=0; i< a [x].size(); i ++){
		int y= a[x][i] ;
		dfs(y) ;		 
	}
	
}  
  
int main(void) {
	 a[1] . push_back(2) ;
   a[2] . push_back(1) ;
   
   a[1] . push_back(3) ;
   a[3] . push_back(1) ;
   
   a[2] . push_back(3) ;
   a[3] . push_back(2) ;
   
   a[4] . push_back(2) ;
   a[2] . push_back(4) ;
   
   a[5] . push_back(2) ;
   a[2] . push_back(5) ;

   a[3] . push_back(6) ;
   a[6] . push_back(3) ;
   
   a[3] . push_back(7) ;
   a[7] . push_back(3) ;

   a[4] . push_back(5) ;
   a[5] . push_back(4) ;
   
   a[6] . push_back(7) ;
   a[7] . push_back(6) ;


  dfs (1) ;
  
	
}

