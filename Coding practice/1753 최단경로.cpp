
#include <iostream>

using namespace std;
#define INF 1000000000

int getSmallIndex(int a[],int x,bool v[]) {
	int min = INF ;
	int index = 0 ;
	for(int i=1 ; i<= x ; i ++) {
		if ((a[i] < min )&& !v[i]) {
			min = a[i] ;
			index= i;
		}
	}
	if ( min == INF ) {
		for(int i=1 ; i <=x ; i++) {
			if(!v[i]) {
				index = i ;
				break ;
			}
		}
	}
	
	return index ;
	
}


int main() {
	
	int V,E ;
	cin >> V >> E ;
	int edge[V+1][V+1] ={0, } ;
	bool v[V+1] = {0, } ;
	int d[V+1] = {0, } ;
	
	int start ;
	cin >> start ;
	// 초기화
	for(int i=0; i < E ; i ++) {
		int v1,v2,n ;
		cin >> v1 >> v2 >> n ;
		if (edge[v1][v2]> n|| edge[v1][v2]==0) { 
		edge[v1][v2] = n;
		}
	}
	// 다익스트라 알고리즘
	for (int i = 1 ; i <= V ; i ++) {
		for(int j= 1; j<= V;j++) {
			if(edge[i][j]==0&& i!=j) edge[i][j] = INF ; 
		}
	}
	for (int i = 1 ; i <= V ; i++) { // d[i] 초기화 
		d[i] = edge[start][i] ;
	}
	// 0 2 3 INF INF 
	v[start] = true ;
	for (int i = 0 ; i < V-2 ; i++) {
		int current = getSmallIndex(d,V,v) ;
		cout << current <<'\n' ; // 2 5 3 
		v[current] = true ;
		for (int j = 1 ; j <= V ; j ++) {
			if (!v[j]) {
				if (d[current] + edge[current][j] < d[j]) {
					d[j] = d[current] + edge[current][j] ;
				}
			}
		}
	}
	
	for(int i = 1  ; i<=V ; i++) {
		if (i== start) cout << "0\n" ;
		else {
		if ( d[i]==INF) cout <<"INF\n" ;
		else cout << d[i] << '\n' ;
		}
	}
	
	
	
	 
	
}
