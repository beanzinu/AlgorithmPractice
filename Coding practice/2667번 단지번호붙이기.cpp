#include <iostream>
#include <algorithm>
using namespace std;
int N ;
char arr[26][26] ;
int temp ;
int ans[26] ;
int ans_count ;

void number(int a,int b ) {
	arr[a][b] = '0' ;
	temp++ ;
	if ( a-1 >=0 && arr[a-1][b] == '1') {
		number(a-1,b) ;
	}
	if ( a+1 < N && arr[a+1][b] == '1' ) {
		number(a+1,b) ;
	}
	if ( b+1 < N  && arr[a][b+1]=='1') {
		number(a,b+1) ;
	}
	if ( b-1 >=0 && arr[a][b-1]== '1') {
		number(a,b-1) ;
	}
}






int main() {
	cin >> N ;
	for(int i = 0 ; i < N  ; i++) {
		for (int j = 0 ; j < N ; j++) {
			cin >> arr[i][j] ;
		}
	}
	for (int i = 0 ; i <  N ; i++) {
		for (int j =0 ; j  < N ; j++) {
			if (arr[i][j]=='1') {
				number(i,j) ;
				ans[ans_count++] = temp ;
				temp = 0 ;
			}
		}
	}
	sort(ans,ans+ans_count) ;
	cout << ans_count << '\n' ;
	for (int i =0  ; i < ans_count ; i++)
	cout << ans[i] << '\n' ;
	
}
