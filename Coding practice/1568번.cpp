#include <iostream>
using namespace std;

int count ;
int main() {

	int N ; 
	cin >> N;
	
	int K=1 ;
	while(N!=0) {
		if ( N < K ) K=1;
		N= N - K ; K++ ;
		count++; 
	}
	
	cout << count ;
}
