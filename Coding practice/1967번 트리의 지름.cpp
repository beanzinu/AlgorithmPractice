#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N ,answer ;

struct node{
	int value ;
	
	vector<node*> child;
};
node* n ;

int dfs(node *root) {
	vector<int> list;
	for(int i=0; i< root->child.size();i++) {
		int x = dfs(root->child[i]) ;
		list.push_back(x) ;
	}
	sort(list.begin(),list.end(),greater<int>()) ;
	int sum =0 ;
	if(list.size()>=2) sum =list[0]+list[1]; 
	else if(list.size()==1) sum = list[0] ;
	
	if(sum > answer) answer = sum;
	if(list.size()>0) return list[0]+root->value;
	else return root->value;
 }


int main() {
	cin >> N ;
	n =new node[N+1] ;
	
	int v,w,t ;
	n[1].value=0;
	for(int i=0;i<N-1;i++) {
		cin >> v >> w >> t;
		n[v].child.push_back(&n[w]) ;
		n[w].value = t;
	}
	
	int trash = dfs(&n[1]);
	cout << answer;
	
}
