#include <iostream>
using namespace std;
int N ;
struct node {
	char value;
	node *left=NULL;
	node *right=NULL;
};
node* n;
void pre_order(node *root){
	if(root->value>='A'&&root->value<='Z')cout << root->value;
	if(root->left!=NULL) pre_order(root->left);
	if(root->right!=NULL)pre_order(root->right);
}
void mid_order(node *root){
	
	if(root->left!=NULL) mid_order(root->left);
	if(root->value>='A'&&root->value<='Z')cout << root->value;
	if(root->right!=NULL)mid_order(root->right);
}

void post_order(node *root){
	
	if(root->left!=NULL) post_order(root->left);
	if(root->right!=NULL)post_order(root->right);
	if(root->value>='A'&&root->value<='Z')cout << root->value;
}
int main() {
	// 'A'=65	
	cin >> N ;
	n = new node[N+1] ;
	
	char root,left,right;
	while(N--) {
		cin >> root >> left >> right;
		n[root-64].value = root;	
		n[root-64].left = &n[left-64];
		n[root-64].right = &n[right-64];
	}
	pre_order(&n[1]) ;  cout <<  '\n';
	 mid_order(&n[1]);   cout << '\n';
	  post_order(&n[1]);  cout << '\n';
	
}	
