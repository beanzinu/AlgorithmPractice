#include <iostream>
#include <math.h>
using namespace std;
int B ;
long long int input  ;

#define FASTIO cin.tie(NULL) ; ios::sync_with_stdio(false) ;

int main() {
  	cin >> input >> B ;
  	
  	int mul = 1 ;
  	
  	for(int i=0 ; input / (int)pow(B,mul) != 0 ; i++) mul++ ;
	mul-- ;
	while(mul >=0 ) {
		int temp = input / pow(B,mul) ;
		input =( input % (int)pow(B,mul) );
		
		mul-- ;
	
		if (temp >=0 && temp <= 9) cout << temp ;
		else {
			cout << (char)(temp+55) ;
		} 
	}  	

}
