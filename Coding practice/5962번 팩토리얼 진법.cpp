#include <iostream>

using namespace std; 


int arr[6] ;
int count =1;
int result ;
int main() {
cin.tie(NULL) ; ios::sync_with_stdio(false) ;


  
while ( 1 ){
	char temp = getchar() ;
	if (temp == '\n' ) {

		for (int i= count-1 ; i >=1 ; i--) {
			int mul = 1;
			for (int j = count - i ; j >=1 ; j--) {
				mul = mul *  j ;
			}
			result = result + ( mul * arr[i] ) ;
		}
		cout << result << '\n' ;
		result = 0 ;
		count =1 ;
		continue; 
	}
	arr[count++] = temp-'0' ;
	if (arr[1] == 0 ) break;
}



}

