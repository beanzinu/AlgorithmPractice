#include <iostream>
using namespace std;
int N ;
char arr[51][51] ;
int MIN = 3000 ;

// dir  1 = right 2= left 3= up 4 = down
void light(int i,int j,int dir,int count) {
	if (i == -1 || i == N) return ;
	if (j == -1 || j == N ) return ;
	
	if (arr[i][j] == '#') {
		if (count < MIN ) MIN = count ;
		return;
	}
	
	if (dir == 1) {
		if (arr[i][j+1] == '*') return ;
		else if (arr[i][j+1] == '!') {
			light(i,j+1,1,count) ;
			light(i,j+1,3,count+1) ;
			light(i,j+1,4,count+1) ;
		}
		else light(i,j+1,1,count) ;
	}
	else if (dir == 2) {
		if (arr[i][j-1] == '*') return ;
		else if (arr[i][j-1] == '!') {
			light(i,j-1,2,count) ;
			light(i,j-1,3,count+1) ;
			light(i,j-1,4,count+1) ;
		}
		else light (i,j-1,2,count) ;
	}
	else if (dir == 3) {
		if (arr[i-1][j] == '*') return ;
		else if (arr[i-1][j] == '!' ) {
			light(i-1,j,3,count) ;
			light(i-1,j,1,count+1) ;
			light(i-1,j,2,count+1) ;
		}
		else light(i-1,j,3,count) ;
	}
	else { // dir == 4
		if (arr[i+1][j] == '*') return ;
		else if (arr[i+1][j] == '!' ) {
			light(i+1,j,4,count) ;
			light(i+1,j,1,count+1) ;
			light(i+1,j,2,count+1) ;
		}
		else light(i+1,j,4,count) ;
	}
	
}




int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	
	cin >> N ; 
	for (int i = 0 ; i < N ; i++) {
		for (int j = 0 ; j < N ; j++) {
			cin >> arr[i][j] ;
		}
	}
	
	for (int i = 0 ; i < N ; i++) {
		bool PASS = false ;
		for (int j = 0 ; j < N ; j++) {
			if (arr[i][j]=='#'){
				arr[i][j] = '.' ;
				light(i,j,1,0) ;
				light(i,j,2,0) ;
				light(i,j,3,0) ;
				light(i,j,4,0) ;
				PASS = true ;
				break;
			}	
		}
		if ( PASS ) break;
	}
	cout << MIN ;
	
	
}


