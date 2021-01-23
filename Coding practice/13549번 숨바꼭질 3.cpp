#include <iostream>
#include <queue>
using namespace std;
int N ,K ;
int d[100001] ;
const int INF = 1000001;
void bfs(int start) {
	queue<int> q;
	d[start]=0;
	q.push(start);
	while(!q.empty()) {
		int cur = q.front(); q.pop() ;
		if(2*cur<=100000 && d[cur] < d[2*cur]) {
			d[2*cur] = d[cur] ;
			q.push(2*cur) ;
		}
		if(cur+1<=100000&& d[cur]+1 < d[cur+1]) {
			d[cur+1] = d[cur]+1 ;
			q.push(cur+1) ;
		}
		if(cur-1>=0&& d[cur]+1 < d[cur-1]) {
			d[cur-1] = d[cur]+1;
			q.push(cur-1) ;
		}
	}
	
	
}


int main() {
	cin >> N >> K ;
	for(int i=0;i<=100000;i++) d[i] = INF ;
	bfs(N) ;
	cout << d[K] ;		
}
