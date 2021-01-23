#include <iostream>
using namespace std;
int n,m ;
const int INF = 100000001 ;
int main() {
	cin >> n >> m ;
	int d[n+1][n+1] ; 
	for(int i=1 ;i<=n ;i++ ){
		for(int j=1;j<=n ;j++) {
			if (i==j) d[i][j] = 0 ;
			else d[i][j] = INF ;
		}
	}
	int a,b,c ;
	while(m--) {
		cin >> a >> b >> c ;
		if(d[a][b]==INF||c < d[a][b] )	d[a][b] = c ;
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n ;i++) {
			for(int j=1;j<=n;j++) {
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]) ;
			}
		}
	}
	for(int i=1;i<=n ;i++) {
		for(int j=1;j<=n;j++) {
			if(d[i][j]==INF) cout << 0 << ' ' ;
			else cout << d[i][j] << ' ' ;
		}
		cout <<'\n' ;
	}
	
}
