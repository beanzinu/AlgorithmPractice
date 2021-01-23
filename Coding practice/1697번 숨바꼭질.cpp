#include <iostream>

using namespace std;
int N ,  K ;
int answer ;

int  find(int x) {
	int MIN = K - x  ;
	int rep =0 ;
	while (true) {
		x = x*2 ;
		rep++;
		int count = rep ;
		if ( x < K) {
			for (int i = x ; i < K ; i++ )
			count++ ;
		}
		else  {
			for(int i = x ; i > K ; i--)
			count++ ;
		}
		if ( count < MIN ) MIN = count; 
		else break;
	}
		return MIN ;	
	
	
}


int main() {
	cin >> N  >> K ;
	if ( N > K ) cout << N - K ;
	else if ( N == K ) cout << "0" ;
	else {
		int min1 = find(N) ;
		for(int i=N-1 ; i > N /2 ; i--) {
			int temp = N-i + find(i) ;
			if (temp < min1 ) min1 = temp ;
			else break;	
		}
		int min2 = find(N) ;
		for (int i =N+1 ; i < 2 * N ; i++) {
			int temp = i - N + find(i) ;
			if ( temp < min2) min2 = temp ;
			else break ;
		}
		if ( min1 > min2 ) cout << min2 ;
		else cout << min1 ;
			
	}
	
	
}
