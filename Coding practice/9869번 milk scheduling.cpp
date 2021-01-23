#include <iostream>
#include <algorithm>
using namespace std;
int N ,target;
bool ch[10001] ;
int arr[10001] ;

typedef struct cow {
	int deadline ;
	int profit ;
	
}cow;
bool compare(cow a,cow b) {
	return a.profit > b.profit ;
}
//balaced tree
typedef struct Node{
	int node ;
	struct Node *left ;
	struct Node *right;
}Node;
Node *create_node(int v) {
	Node *n = new Node ;
	if(n!=NULL) {
		n->node = v ;
		n->left = NULL;
		n->right = NULL ;
	}
	return n ;
}
void create_BT(Node **root,int* arr,int start,int end) {
	
	if(start<=end) {
		int mid = (start+end+1) / 2 ;
		*root= create_node(arr[mid]) ;
		create_BT(&((*root)->left),arr,start,mid-1) ;
		create_BT(&((*root)->right),arr,mid+1,end) ;
	}
}
void find(Node *root,int T) {
	if (root->node == T && ch[T]==false) {
		target = T ; return;}
	if(root->left==NULL && root->right == NULL){
		if(ch[root->node]==false&& root->node > target)  target = root->node ;
		 return ;
	}
	if(root->node < T ) {
		if(ch[root->node]==false&& root->node > target)  target = root->node ;
		if(root->right != NULL)find(root->right,T) ;
	} 
	else {
		if(root->left!=NULL)find(root->left,T) ;
	}
	
}



int main() {
	cin >> N ;
	cow c[N+1] ; 
	for(int i=0;i<N ;i++) {
	cin >> c[i].profit >> c[i].deadline ;
	}
	sort(c,c+N,compare) ;
	for(int i=1 ; i<=10000 ;i++) arr[i] = i ;
	// make Balancd Tree
	Node *root = NULL ;
	create_BT(&root,arr,1,10000) ;
	
	int sum = 0 ;
	for(int i=0;i<N;i++) {
		find(root,c[i].deadline);
		ch[target] = true ;
		if(target!=0)sum += c[i].profit ;
		target = 0 ;
	}	
	cout << sum ;
}
