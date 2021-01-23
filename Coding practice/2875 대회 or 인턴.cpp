#include <iostream>

using namespace std;
int N,M,K ;
int k_count ;
bool fin ;
int main() {
	cin >> N >> M >> K ;
	
	if (N >= 2*M) {  // N>=2M 인 경우 
		while (N!=2*M&&k_count!=K) {
			N--; k_count++;
			if(k_count==K) break;
		}
		//확 인  
		if (k_count == K ) fin = true ;
		 
		bool m= true ;
		int n_count =0;
		while (k_count!=K && !fin){
			if (m) {
				M--; k_count++; m=false ;
			}
			else {
				N--; k_count ++; n_count++;
				if (n_count  == 2) {
					m=true ; n_count =0 ;
				}
			}
		}
		// 결과 출력
		cout << M ; 
	}
	else {
		while ( N < 2*M&&k_count!=K) {
			M-- ; k_count++;
			if(k_count==K) break;
		}
		//확인  
		if (k_count==K) fin = true ;
		
		if (N>2*M &&!fin ) {
			N--; k_count++;
		}
		if (k_count==K) fin = true ;
		
		bool m= true ;
		int n_count =0;
		while (k_count!=K && !fin){
			if (m) {
				M--; k_count++; m=false ;
			}
			else {
				N--; k_count ++; n_count++;
				if (n_count  == 2) {
					m=true ; n_count =0 ;
				}
			}
		}
		if ( N < 2*M) cout << 2/N ;
		else cout << M; 
		
	}

	
}
