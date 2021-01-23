/* 너비 우선 탐색 (VFS) 
- 맹목적인 탐색
- '최단 경로 '를 찾아준다는 점 - > 최단 길이를 보장  
		1
	2		3
  4  5     6  7
  
  큐에서 하나의 노드를 꺼냅니다.
  해당 노드중 방문하지 않은 노드를 큐에 삽입.
  
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7 ;
int c[7] ;
vector<int> a[8] ;  // 인덱스 1~7 까지 이용하기위해

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true ;
	while( !q.empty())
 {
 	int x= q.front();
 	q.pop();
 	printf("%d", x );
 	for(int i=0; i < a[x].size(); i++ ) {
 		int y= a[x][i] ;
		 if(!c[y]) {
		 	q.push(y) ;
		 	c[y] = true ;
 		 } 
	 }
 }
 
 }
 
int main(void)  {

   a[1] . push_back(2) ;
   a[2] . push_back(1) ;
   
   a[1] . push_back(3) ;
   a[3] . push_back(1) ;
   
   a[2] . push_back(2) ;
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

bfs(1) ;

return 0 ; 
 
 
}

 
  

 
