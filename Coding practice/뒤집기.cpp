
#include <string>
#include <bits/stdc++.h>

using namespace std;
int main ()   { 

string temp;

cin >> temp ;  


char S[temp.length()] ;
strcpy(S,temp.c_str()) ; 

int a=0 ;int b =0 ;
for(int i =0; i<temp.length() ; i ++) {   // 0 �� 1 �߿� ������ ������ ?  
	if(S[i]  == '0' ) a++ ;
	else b++ ;
}
char x;                    
    if ( a>=b )  x='1' ;
    else x='0';


int count =0 ;  int tem=0 ; 
for(int i=0;i<temp.length();i++) {
	
	if (S[i] != x  ) {       // 0 �϶�    
	  tem = 0 ;
	}
	else{   // 1�϶� 
		if (tem == 0 ) { 
	   count++ ; tem = 1;	
          }
          
	} 
	
}

 
   cout << count ;

}
