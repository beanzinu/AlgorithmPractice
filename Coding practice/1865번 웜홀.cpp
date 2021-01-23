#include <iostream>
using namespace std;
int TC;
int N,M,W ;
bool answer ;
const int INF = 100000001;
int main() {
	cin >> TC ;
	while(TC--) {
		int s,e,t ;
		cin >> N >> M >> W ;
		int arr[N+1][N+1] ;
		// √ ±‚»≠
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++){
				if (i==j) arr[i][j] = 0;
				else arr[i][j]=INF;
			}
		} 
		while(M--) {
			cin >> s >> e >> t ;
			if(arr[s][e]==0 || arr[s][e] > t ) {
			arr[s][e] = t;
			arr[e][s] = t;
			}
		}
		while(W--) {
			cin >> s >> e >> t ;
			if(arr[s][e]==0 || arr[s][e] > -t ) arr[s][e] = -t;
		}
		// floyd-warshall
		for(int k=1;k<=N;k++){
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					
					arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]) ;
					
				}
			}
		}
		// check 
		for(int i=1;i<=N;i++) if(arr[i][i] < 0 ) answer = true ;
		if(answer) cout << "YES" << '\n' ;
		else cout << "NO" << '\n';
		
		answer = false ;
		
	}	
	
	
}
