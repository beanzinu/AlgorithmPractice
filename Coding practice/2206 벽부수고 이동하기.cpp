#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int INF = 10000001;
int N,M ;
char arr[1001][1001] ;
int MIN[1001][1001][2] ;
int dx[4]={1,0,-1,0} ;
int dy[4]={0,1,0,-1} ;

void bfs() {
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(make_pair(1,1),0));
	while(!q.empty()) {
		
		int x = q.front().first.first;
		int y = q.front().first.second;
		int destroyed= q.front().second;
		
		q.pop();
	
		for(int i=0;i<4;i++) {
			int nx= x +dx[i] ;	
			int ny= y +dy[i] ;
			if(nx<1 || nx>M) continue;
			if(ny<1 || ny>N) continue;
			int new_destroyed = destroyed + arr[ny][nx]-'0' ; 
			if(new_destroyed>1) continue;
			
			if(MIN[y][x][destroyed]+1 < MIN[ny][nx][new_destroyed] ) {
				MIN[ny][nx][new_destroyed] = MIN[y][x][destroyed] + 1 ;
				if(nx==M && ny==N) return ;
				q.push(make_pair(make_pair(nx,ny),new_destroyed));
			}	
		}	
	}	
}

int main() {
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M ;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++){
			cin >> arr[i][j] ;	
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++){
			MIN[i][j][0] = INF ;
			MIN[i][j][1] = INF ;
		}
	}
	MIN[1][1][0] = 1;
	MIN[1][1][1] = 1;
	bfs(); 
	int answer = min(MIN[N][M][0],MIN[N][M][1]) ;
	if(answer==INF) cout << "-1";
	else cout << answer ;
	
}
