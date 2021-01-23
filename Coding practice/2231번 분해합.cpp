#include <iostream>
#include <algorithm>
using namespace std;
char arr[8] ;
int N ;
bool print ;
int main() {
	cin >> N ;
	for (int i =0 ; i < N ; i++) {
		sprintf(arr,"%d",i) ;
		int temp = i ;
		for (int j = 0; arr[j]!='\0' ; j++) {
			temp = temp + (arr[j]-'0') ;
		}
		if (temp == N ) {
		cout << i ;
		print = true ;
		break ;
		}
	}
	if (!print) printf("0") ;
	
	
}
