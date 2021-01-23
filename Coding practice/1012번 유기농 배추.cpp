#include <iostream>
using namespace std; 
int T ;
int N , M , K ;
int arr [51][51] ;
int count ;
void insect(int a,int b) {
	arr[a][b]= 0 ; 
	
	if ( a-1 >=0 && arr[a-1][b]==1) insect(a-1,b) ;
	if (a+1 < N && arr[a+1][b]==1) insect(a+1,b) ; 
	if (b+1 < M && arr[a][b+1]==1) insect(a,b+1) ;
	if (b-1 >=0 && arr[a][b-1]==1) insect(a,b-1) ;
	
	
}





int main() {
	cin >> T  ;
	
	
	for(int k= 0 ; k < T ; k++) // test case 
	 {
	 	cin >> M >> N >> K ;
	 	int X1,X2 ;
	 	for (int i = 0 ; i < K ; i++) {
	 		cin >> X1 >> X2 ;
	 		arr[X2][X1] = 1 ;		
		 }
	 	for (int i =0 ; i < N ; i++) {
	 		for (int j = 0 ; j < M  ; j++) {
	 			if (arr[i][j]==1) {
	 				insect(i,j) ;
	 				count++;
				 }
			 }
		 }
	 	cout << count << '\n' ;
		count = 0 ; 
	 	
	 	
	 }
	
}
