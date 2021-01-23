#include <iostream>
using namespace std;
int N , M ;
int arr[1001][1001];

// dir  1 = right 2= left 3= up 4 = down
void light(int i,int j,int dir) {
	if ( j == -1 ) {
		cout << i+1 << ' ' ;
		return ;
	}
	else if ( i == N ) {
		cout << N+1+j << ' ' ;
		return ;
	}
	else if ( j == M) {
		cout << 2*N+M-i << ' ';
		return ;
	}
	else if ( i == -1 ) {
		cout << (2*N) + (2*M) - j  << ' ' ;
		return ;
	}
	
	if (dir==1) {
		if (arr[i][j] == 1) light(i-1,j,3) ;
		else light(i,j+1,1) ;
	}
	else if (dir == 2) {
		if (arr[i][j] == 1) light(i+1,j,4) ;
		else light (i,j-1,2) ; 
	}
	else if (dir == 3) {
		if (arr[i][j] == 1) light(i,j+1,1) ;
		else light(i-1,j,3) ;
	}
	else {  // dir == 4
		if (arr[i][j] == 1) light(i,j-1,2) ;
		else light (i+1,j,4) ; 
	}
}

int main(){
	cin.tie(NULL)  ;  ios::sync_with_stdio(false) ;
	cin >> N >>  M;
	for (int i = 0 ; i < N ; i++) {
		for (int j =0 ; j < M ; j++) {
			cin >> arr[i][j] ;
		}
	}
	for (int i = 0; i < N ; i ++) { // 1 ` N 
		light(i,0,1) ;
	}
	for (int i=0 ; i < M ; i++) { // N+1 ~ N+M
		light(N-1,i,3) ;
	}
	for (int i = 0 ; i < N ; i++) { // N+M+1 ~ 2N+M
		light(N-1-i,M-1,2) ;
	}
	for (int i = 0  ; i < M ; i++) { // 2N+M + 1 ~ 2N+2M
		light(0,M-1-i,4) ;
	}
}
