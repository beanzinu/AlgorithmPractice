#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int V,E,start;
const int INF = 10000001 ;
int* d;
vector<pair<int,int> >* edge;
bool* visit;
void dijkstra(int start) {
	d[start] = 0 ;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push(make_pair(0,start)) ;
	while(!pq.empty()) {
		int distance = pq.top().first ;
		int node = pq.top().second ;
		pq.pop() ;
		
		if (visit[node]) continue ;
		visit[node] = true ;
		
		for(int i=0; i<edge[node].size();i++){
			int next = edge[node][i].first ;
			if (visit[next]) continue ;
			
			if(d[next] > distance+edge[node][i].second){
				d[next] = distance+edge[node][i].second ;
				pq.push(make_pair(distance+edge[node][i].second,next)) ;
			}
			
		}
		
	}
	
}



int main() {
	scanf("%d %d",&V,&E) ;
	scanf("%d",&start) ;
	// √ ±‚»≠  
	edge = new vector<pair<int,int> > [V+1] ;
	d = new int[V+1] ;
	visit = new bool[V+1] ;
	int u,v,w ;
	while(E--) {
		scanf("%d %d %d",&u,&v,&w) ;
		edge[u].push_back(make_pair(v,w)) ;
		
	}
	for(int i=1 ;i<=V ; i++) d[i] = INF ;
	for(int i=1 ;i<=V ; i++) visit[i] = false ;
	dijkstra(start) ;

	for(int i=1 ; i<=V ;i++) {
		if (d[i]==INF) printf("INF\n");
		else printf("%d\n",d[i]) ;
	}
	
}
