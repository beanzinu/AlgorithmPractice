#include <iostream>
#include <vector>
using namespace std ; 

vector<string> v;
int main() {
	char s[101] ;
	char com[101] ;

	
	

	
	do {
		
		cin.getline(s,101,'.') ;
		
		int count =  0 ;
		bool tem =false ; 
		 for(int j=0; s[j]!='\0' ; j ++ ){
		 
	if (s[j]== '(' || s[j] == '[')  com[count++] =s[j] ;
	else if (s[j]==')') {
		if (count ==0) {
			v.push_back("no") ; tem = true; break ;
		}
		else if(com[--count]=='(') com[count] = 0 ;
		else {
		v.push_back("no") ;  tem = true; count -- ; break ;
			 }
	}
	else if (s[j]==']') {
		if (count == 0) {
			v.push_back("no") ;  tem = true; break ;
		}
		else if(com[--count]=='[') {
		com[count] = 0 ;}
		else {
			v.push_back("no") ;  tem = true; count -- ;  break;
		} 
	}
	else continue ;
	
	
		} // j
		 
	 if (tem)  ;
	 else {
	 	if ( count > 0 ) v.push_back("no")  ;
	 	else v.push_back("yes") ;
	 }
	

	cin.ignore(256,'\n') ;
	
	}while(s[0]!='\0') ;
	
	for( int i = 0 ; i < v.size()-1 ; i++)
              cout << v[i] << '\n' ;	
              

              
}
