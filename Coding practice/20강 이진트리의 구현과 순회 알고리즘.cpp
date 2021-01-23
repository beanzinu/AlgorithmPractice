/* 이진트리 
1) 전위 순회 
1. 자기 자신을 처리
2. 왼쪽자식
3.오른쪽 자식
 
2) 중위 순회 
1. 왼쪽
2.자기 자신 
3. 오른쪽

3. 후위 순회   ( 계산기 ) 
1. 왼쪽
2. 오른쪽  
3. 자기 자신 
*/
#include <iostream>

using namespace std;

int number = 15 ;

// 하나의 노드 정보를 선언합니다 .
typedef struct node *treePointer ;
typedef struct node {
	int data;
	treePointer leftChild,rightChild ;
}node;

void preorder(treePointer ptr) {
	if(ptr) {
		cout << ptr->data << ' ' ;
		preorder(ptr->leftChild) ;
		preorder(ptr->rightChild) ;
	}
} 
void inorder(treePointer ptr) {
	if(ptr) {
		preorder(ptr->leftChild) ;
		cout << ptr->data << ' ' ;
		preorder(ptr->rightChild) ;
	}
} 
void postorder(treePointer ptr) {
	if(ptr) {
		preorder(ptr->leftChild) ;
		preorder(ptr->rightChild) ;
		cout << ptr->data << ' ' ;
	}
} 


int main(void) {
	node nodes[number+1] ;
	for(int i=1 ; i <= number ;  i ++) {
		nodes[i].data = i ;
		nodes[i].leftChild = NULL ; 
		nodes[i].rightChild = NULL ; 
	}
	for (int i =1 ;  i <= number ; i ++) {
		if (i%2 == 0 ) {
			nodes[i/2].leftChild = &nodes[i] ;	
		}
		else {
			nodes[i/2].rightChild = &nodes[i] ;
		}
	}
	preorder(&nodes[1]) ;
	
	
}



