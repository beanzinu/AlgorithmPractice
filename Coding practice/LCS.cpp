#include <iostream>
using namespace std; 
char s1[1001] ;
char s2[1001] ;
int arr[1001][1001] ;
int s1_size,s2_size ;

int main() {
	cin >> s1 >> s2 ;
	for(int i=0; s1[i]!='\0' ;i++) s1_size++ ; 
	for(int i=0; s2[i]!='\0' ;i++) s2_size++ ; 
	
	for(int i=0; i<s1_size ; i++) {
		for(int j=0; j<s2_size ;j++) {
			if (i==0 && j==0)arr[i][j] = s1[i]==s2[j]? 1:0 ; 
			else if(s1[i] == s2[j]) {
				if(i-1 <0 || j-1 <0) arr[i][j]=1;
				else arr[i][j]= arr[i-1][j-1]+1 ;
			}
			else { // s1[i] != s2[j]
				if(i==0) arr[i][j] = arr[i][j-1] ;
				else if(j==0) arr[i][j] = arr[i-1][j] ;
				else arr[i][j] = max(arr[i-1][j],arr[i][j-1]) ;
			}
			
		}
	}
	cout << arr[s1_size-1][s2_size-1] ;
	
	
}
