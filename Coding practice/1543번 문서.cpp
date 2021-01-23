#include <iostream>

using namespace std ;
char s[2501] ;
char f[51] ;
int length ; // 중복 문자 총 길이  
int check ; // 중복문자  
int answer ;
int main() {
	cin.getline(s,2501) ;
	cin.getline(f,51) ;
	for(int i=0; f[i]!='\0' ; i++) length++;


	
	for (int i =0 ; s[i] != '\0' ; i++) {
		for (int j = i ; j<=i+length-1 ; j++){
			if(s[j]==f[check]) {
				check++ ;
			}
			else break ;	
		}	
		if ( check == length) {
			 check = 0; answer++ ; i = i + length-1 ;
		}	
		else {
			check = 0;
		}
	}
	printf("%d",answer) ;
}
