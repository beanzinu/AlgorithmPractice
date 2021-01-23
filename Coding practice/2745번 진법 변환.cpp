#include <iostream>
#include <math.h>
using namespace std;
int B ;
char s[100] ;  
long long int result ;
#define FASTIO cin.tie(NULL) ; ios::sync_with_stdio(false) ;

int main() {
 // (int)A - 55 = 10 
  
 cin >> s ; 
 cin >> B ;
 int size = 0;
 for (int i = 0 ; s[i]!='\0' ; i++) size++ ;
 size-- ;
 for (int i = 0 ; s[i]!= '\0' ; i++) {
 	if ( s[i]- '0' >=0 && s[i]-'0' <= 9) 
 	result = result + ( pow(B,size--) * (s[i]-'0') ) ;
 	else result = result + ( pow(B,size--) * (s[i]-55) ) ;
 	
 }
 cout << result ;
	
	
}
