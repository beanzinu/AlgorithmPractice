#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int N,M ;
int arr[10] ;

void dfs(int index,bool* c,deque<int> q) {

	c[index] = true;
	q.push_back(arr[index]);
	if(q.size()==M) {
		printf("fin");
		while(!q.empty()){ 
		printf("%d ",q.front()); q.pop_front();}
		printf("\n"); return ;
	}
	bool temp_c[N+1] ;
	for(int i=0;i<N;i++) temp_c[i]= c[i] ;
	for(int i=0;i<N;i++) {
		if(c[i]) continue ;
		dfs(i,c,q);
		for(int j=0;j<N;j++) c[i]=temp_c[i] ;
	}	
	
}

int main() {
scanf("%d %d",&N,&M) ; 
for(int i=0;i<N;i++) scanf("%d",&arr[i]);
sort(arr,arr+N) ;
bool c[N+1]= {0, };
deque<int> q ;
for(int i=0;i<N;i++){
dfs(i,c,q);
fill_n(c,N,0) ;
}
	
}
