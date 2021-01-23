#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
char s[4] = {'0','1','2','4'} ;
int p[100] ;
int n ;
int main() {
    cin >> n ;
	string answer = "";
    int digit = 0,i=1;
    while(n>digit) {
        digit = digit + pow(3,i++) ;
    }
    i--;
    cout << i << '\n' ;
    for(int j=i ; j>=0 ; j--) {
        int k = n / pow(3,j) ;
        p[j]= k ;
		n = n - (k*pow(3,j)) ;
    }
    for(int j=0 ; j<=i-1 ; j++) {
    	if(p[j]<=0) {
    		p[j]=p[j]+3 ; p[j+1]--;
		} 	
	}
    for(int j=i-1 ; j>=0 ; j--) answer.push_back(s[p[j]]) ;
    
    
    cout<< answer;
}
