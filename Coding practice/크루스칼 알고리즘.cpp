/* 크루스칼 알고리즘

노드 = 정점 = 도시 
간선 = 거리 = 비용 

 최소 비용 신장 트리 만들때 사용 됨  .
 
 간선 정보를 '거리' 기준으로 오름차순으로 정렬
 비용이 적은 간선부터 차근차근 그래프에 포함시킴 .
 
 ----- 사이클이 발생하면 안됨 !
 - 사이클이 발생할 경우 그래프에 포함 X
 
 사이클 테이블 생성
 부모 - 자 
 
 
  
*/
#include <stdio.h>
#include <vector>
#include <algorithm> 
using namespace std;
int getParent(int parent[],int x) {
	if (parent[x]==x) return x;
	return parent[x] = getParent(parent,parent[x]) ;
}

// 두 부모 노드를 합치는 함수
int unionParent(int parent[],int a, int b) {
	a= getParent(parent,a) ;
	b= getParent(parent,b);
	if( a < b ) parent[b] = a;
	else parent[a] = b ;
} 

// 같은 부모를 가지는지
int findParent(int parent[],int a, int b){
	a= getParent(parent,a) ;
	b= getParent(parent,b);
	if ( a== b)  return 1 ;
	return 0;

}
 // 최소 비용 신장 트리
 class Edge {
 	public:
 		int node[2] ;
 		int distance ;
 		Edge(int a,int b, int distance) {
 			this->node[0] = a ;
 			this->node[1] = b ;
 			this->distance = distance ;
		 }
		 bool operator <(Edge &edge)   { // 비용을 기준으로 정렬 
		 	return this->distance < edge.distance ;
		 }
 }; 
int main(void)   {
	int n= 7;
	int m = 11;
	
	vector<Edge> v;
	v.push_back(Edge(1,7,12));
	v.push_back(Edge(1,4,28));
	v.push_back(Edge(1,2,67));
	v.push_back(Edge(1,5,17));
	v.push_back(Edge(2,4,24));
	v.push_back(Edge(2,5,62));
	v.push_back(Edge(3,5,20));
	v.push_back(Edge(3,6,37));
	v.push_back(Edge(4,7,13));
	v.push_back(Edge(5,6,45));
	v.push_back(Edge(5,7,73));
	
	sort(v.begin(),v.end()) ;
	
	int parent [n] ;
	for(int i=0; i < n ; i ++) {
		parent[i] = i ;
	}
	
	int sum = 0; 
	for(int i=0;i <v.size();i++) {
		//  사이클에 발생하지 않는 경우 
		if(!findParent(parent,(v[i].node[0])- 1,(v[i].node[1]) -1)) {
			sum= sum+ v[i].distance ;
		    unionParent(parent,(v[i].node[0])-1,(v[i].node[1])-1) ; 
		}
				
	}
	
	
	printf("%d",sum) ;
	
	
	
	
	
	
	
	
}  
  
