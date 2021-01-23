#include <iostream>
#include <algorithm> 
using namespace std; 
int N ,M;
int d[10] ;
bool ch[10] ;

void dfs(int index,int count,bool c[]) {
	for(int i=0;i<N;i++) cout << c[i] ;
	cout <<'\n' ;
	c[index] = true ;
	for(int i=0 ; i<N ;i++) {
		if(!c[i]&&count+1<=M){
			cout << d[index] << ' ' ;
			dfs(i,count+1,c);
		}
	}
	
	
}

int main() {
	cin >> N >> M ;
	for(int i=0;i<N;i++) cin >> d[i] ;
	sort(d,d+N,less<int>()) ; 
	for(int i=0;i<N;i++) {
	dfs(i,1,ch) ;
	fill_n(ch,10,false) ;
	}
	
}
