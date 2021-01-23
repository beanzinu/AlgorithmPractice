#include <iostream>
using namespace std;
int N,K ;
int a[101],b[101] ;
int answer ;
int d[105][100005] ;
void dp() {
	d[1][a[1]]= b[1] ;
	for(int i=2 ; i<=N ;i++) {
		
		for(int j=0 ; j<=K ;j++) {
			if(d[i-1][j]!=0) {
 
				if(j+a[i]<=K) d[i][j+a[i]]=max(d[i-1][j]+b[i],d[i-1][j+a[i]]);	
				d[i][j] = max(d[i][j],d[i-1][j]) ;
			}
			if (j==a[i]) d[i][j] = max(d[i][j],b[i]) ;
			 
		}
	}
	
}
int main() {
	cin >> N >> K;
	for(int i=1 ; i<=N ;i++) cin >> a[i] >> b[i] ;
	dp() ;
	for(int i=0 ; i<=K ;i++) answer = d[N][i] > answer ? d[N][i] : answer ;
	cout << answer ;
	
}
