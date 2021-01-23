#include <iostream> 
#include <algorithm>
using namespace std ;
#define fastio() cin.tie(NULL) ; ios::sync_with_stdio(false) ;
char n[100001] ;
int sum ;
bool compare(char a,char b){
	return a > b ;
}
int main() {
	fastio() ;
	scanf("%s",n) ;
	int n_len = 0;
	for(int i=0; n[i]!='\0';i++){
		n_len++;
	}
	sort(n,n+n_len,compare) ;
	
	for(int i=0; i< n_len ; i++){
		sum = sum + n[i]-'0' ; 
	}
	if (sum%3==0 && n[n_len-1]=='0') {
		cout << n ;
	}
	else cout << "-1" ;
}
