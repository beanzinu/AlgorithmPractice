#include <iostream>
#include <queue> 
#include <vector>
using namespace std;
int N,M, H ; 
queue<pair<pair<int,int>,int > > q ;
int size ;
int t_count ;
int answer ;
int arr[101][101][101] ;

void tomato(int count) {
	
	while(!q.empty()) {
		int rep = size ;
		size = 0 ;
		count++ ; 
		
		while(rep--) {     // 주변 자식 큐에 삽입  
			int n1 = q.front().first.first ;
			int n2 = q.front().first.second ;
			int n3 = q.front().second ; 
			q.pop() ;
			
			
			if ( n1-1 >=0 && arr[n1-1][n2][n3]==0){
			arr[n1-1][n2][n3]  = 1 ; t_count++; 
			q.push(make_pair(make_pair(n1-1,n2),n3)) ; size++ ;	 }
			 
 			if (n1+1 < N && arr[n1+1][n2][n3]==0)	{
 			arr[n1+1][n2][n3]  = 1 ; t_count++; 
			q.push(make_pair(make_pair(n1+1,n2),n3)) ; size++ ;	 }
			
			if (n2+1 < M && arr[n1][n2+1][n3]==0){
			arr[n1][n2+1][n3]  = 1 ; t_count++; 
			q.push(make_pair(make_pair(n1,n2+1),n3)) ; size++ ;	}
			
			if (n2-1 >=0 && arr[n1][n2-1][n3]==0) {
			arr[n1][n2-1][n3]  = 1 ; t_count++; 
			q.push(make_pair(make_pair(n1,n2-1),n3)) ; size++ ;	 }
			if (n3-1>=0 && arr[n1][n2][n3-1]==0) {
			arr[n1][n2][n3-1]  = 1 ; t_count++; 
			q.push(make_pair(make_pair(n1,n2),n3-1)) ; size++ ;	
			}
			if (n3+1 < H && arr[n1][n2][n3+1]== 0) {
			arr[n1][n2][n3+1] = 1 ; t_count++ ;
			q.push(make_pair(make_pair(n1,n2),n3+1)) ; size++ ;	
			}
 		}		
	}
	
	answer = count-1 ;
	
	
}

int main() {
	cin >> M >> N >> H ;
	for (int k = 0 ; k < H ; k++) {
	for (int i=0; i < N ; i++) {
		for (int j =0 ; j < M ; j++) {
			cin >> arr[i][j][k] ;
			if (arr[i][j][k]==1) {
				q.push(make_pair(make_pair(i,j),k)) ;
				size++ ;
				t_count++ ;
			}
			else if (arr[i][j][k] == -1) t_count++ ;
 			} // j
		} // i
	}  // k
	tomato(answer) ;

	if (t_count == N*M*H) cout << answer ;
	else if (t_count == 0) cout << "0" ;
	else cout << "-1" ;
	
}











