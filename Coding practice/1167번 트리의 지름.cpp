#include <iostream>
#include <vector>
using namespace std;
int V , answer ;
vector<pair<int,int> > v[100001] ;
bool c[100001] ; // visit 
#define des first 
#define val second 

int dfs(int node,int value,int edge) {
	c[node] = true ;
	int temp[2] = { 0,};
	int ret_val = 0 ;
	for(int i=0 ; i< v[node].size() ;i++) {
		if(c[v[node][i].des] == true ) continue;
		temp[i] = dfs(v[node][i].des,value+v[node][i].val,v[node][i].val) ;
	}
	
	int sum = temp[0] + temp[1] ;
	if (sum > value+temp[0] || sum > value+temp[1]) {
		if(sum > answer) answer = sum ;
	}
	if( temp[0] > temp[1] ) ret_val =  temp[0] ;
	else ret_val = temp[1] ;
	if ( value + ret_val > answer ) answer = value + ret_val ;
	return edge + ret_val ; 
}


int main() {
	cin >> V ;
	int node,x1,x2;
	while(V--) {
		cin >> node ;
		while(true) {
			cin >> x1 ;
			if(x1 == -1) break;
			cin >> x2 ;
			v[node].push_back(make_pair(x1,x2)) ;
		}
	}
	int d = dfs(1,0,0);
	cout << answer ;
	return 0 ;
		
}
