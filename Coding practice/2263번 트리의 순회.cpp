#include <iostream>
using namespace std;
int n;

int* In;
int* Post;


void root_find(int in_start,int in_end,int post_start,int post_end) {
	if(in_start>in_end) return ;
	int root = Post[post_end] ;
	
	cout << root << ' ' ;
	//left
		root_find(in_start,In[root]-1,post_start,post_start+In[root]-in_start-1) ;
	//right
		root_find(In[root]+1,in_end,post_start+In[root]-in_start,post_end-1);
	
	
}


int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;	
	cin >> n ;
	In = new int[n+1];
	Post = new int[n+1] ;
	int temp ;
	for(int i=1;i<=n;i++) {
		cin >> temp ; In[temp] = i ;
	}
	for(int i=1;i<=n;i++) cin >> Post[i] ;
	/// pre_order
	root_find(1,n,1,n) ; 
	

	
}
