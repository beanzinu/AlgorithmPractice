/* 합집합 찾기 (Union - Find )
- 서로소 집합 알고리즘 
- 부모를 합칠때는 작은 값 쪽으로 합칩니다. 합침 (Union )
- 재귀함수를 사용 
find 알고리즘은 두개의 노드를 비교해 같은 부모를 가지고 있는지 확인  
*/

#include <stdio.h>

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

int main(){
	int parent[11] ;
	for(int i=1;i<=10;i++) {
		parent[i] = i ;
	}
	unionParent(parent,1,2);
	unionParent(parent,2,3);
	unionParent(parent,3,4);
	unionParent(parent,5,6);
	unionParent(parent,6,7);
	unionParent(parent,7,8);
	printf("?%d\n",findParent(parent,1,5));
	
}






