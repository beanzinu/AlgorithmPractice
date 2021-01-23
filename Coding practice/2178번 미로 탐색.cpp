#include <iostream>
#include <queue>
using namespace std;
int N,M ;
char arr[101][101] ;
int MIN = 10001;
int find_way(int col,int row,int count) {
	arr[col][row]  = '0' ;
	queue<pair<int,int> > q ;
	q.push(make_pair(col,row)) ;
	int size = 1 ;
	while(!q.empty()) {
		int rep = size ;
		size = 0 ;
		count++ ; 
		
		while(rep--) {     // 주변 자식 큐에 삽입  
			int n1 = q.front().first ;
			int n2 = q.front().second ;
			if ( n1 == N-1 && n2 == M-1) return count ; 
			q.pop() ;
			
			if ( n1-1 >=0 && arr[n1-1][n2]=='1'){
			arr[n1-1][n2] = '0';
			 q.push(make_pair(n1-1,n2)) ; size++ ; }
 			if (n1+1 < N && arr[n1+1][n2]=='1')	{
 			arr[n1+1][n2] = '0' ;
			 q.push(make_pair(n1+1,n2)) ; size++ ; }
			if (n2+1 < M && arr[n1][n2+1]=='1'){
			arr[n1][n2+1] = '0' ;
			q.push(make_pair(n1,n2+1)) ; size++ ;}
			if (n2-1 >=0 && arr[n1][n2-1]=='1') {
			arr[n1][n2-1] = '0' ;
			q.push(make_pair(n1,n2-1)) ; size++ ; }
 		}
		
		
		
		
	}
	
	
}


int main() {
	cin >> N >> M ; 
	for(int i =0; i < N ;i++) {
		for(int j=0; j < M ; j++) {
			cin >> arr[i][j] ;
		}
	}


	cout << find_way(0,0,0)  ;
	
}
