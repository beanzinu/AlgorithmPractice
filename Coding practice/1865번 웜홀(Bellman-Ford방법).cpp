#include <iostream>
#include <vector>
using namespace std;
int TC ;
int N,M,W ;
const int INF = 100000001;
int* d ;



int main() {
	cin >> TC ;
	while(TC--) {
		bool minus_cycle = false ;
		cin >> N >> M >> W ;
		vector<pair<int,int> > v[N+1] ;
		d = new int[N+1] ;
		for(int i=1 ;i<=N;i++) d[i] = INF ;
		
 		int s,e,t ;
		while(M--) {
			cin>>s>>e>>t ;
			v[s].push_back(make_pair(e,t));
			v[e].push_back(make_pair(s,t));			
		}
		while(W--){
			cin>>s>>e>>t;
			v[s].push_back(make_pair(e,-t));
		}
		//bellman-ford alg
		d[1]= 0 ;
		for(int k=0;k<N;k++) {
		for(int i=1 ; i<=N ;i++) {
			for(int j= 0;j<v[i].size();j++) {
				int next = v[i][j].first ;
				int dist = v[i][j].second ;
 					if(d[i]!=INF && d[next] > d[i]+dist) {
				 		d[next] = d[i]+dist ; 
				 		if(k==N-1) minus_cycle = true ;
					}
				}		
		}
		}
		if(minus_cycle) cout << "YES\n";
		else cout << "NO\n" ;
		minus_cycle = false ;
		
	}
	
	
} 
