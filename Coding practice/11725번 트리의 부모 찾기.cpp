#include <iostream>
#include <vector> 
using namespace std;

int N ;

struct node{
	int value ;
	vector<node*> next;
};
int* parent ; // answer 
node* n ;  // nodes in tree
bool* visit ; // visited node

void dfs(int root) {
	visit[root]= true ;
	for(int i=0;i<n[root].next.size();i++){
		int child = n[root].next[i]->value ;
		if(!visit[child]) {
		parent[child] = root;
		dfs(child);
		}
	}
	
}


int main() {
	cin >> N;
	parent = new int[N+1] ;
	n=new node[N+1] ;
	visit = new bool[N+1] ;
	for(int i=1;i<=N;i++) visit[i]= 0;
	for(int i=1;i<=N;i++) n[i].value = i;
	
	int a,b ;
	for(int i=0;i<N-1;i++) {
		cin >> a >> b ;
		n[a].next.push_back(&n[b]);
		n[b].next.push_back(&n[a]);
	}
	dfs(1);
	for(int i=2;i<=N;i++) cout << parent[i] << '\n' ;
	
	
}
