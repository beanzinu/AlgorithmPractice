#include <iostream>
#include <stack>
#include <sstream> 

using namespace std; 
stack<int> v; 

int answer [10001] ;

int main() {
	for(int i =0 ; i < 10001 ; i ++)
	 answer[i] = -2 ;
	 
	int number;
	scanf("%d",&number) ;
	cin.ignore(256,'\n') ;
	
	
	for(int i=0; i< number ; i ++){
	 string temp1 ;
	 getline(cin,temp1) ;
	 if (temp1.compare("pop") == 0){
	 	if(v.empty()) answer[i] = -1 ; 
		else{
		answer[i] = v.top() ;
	 	v.pop() ;
			}
	}
	 else if (temp1.compare("size") == 0){
	 	answer[i] = v.size();
	 }
	 else if (temp1.compare("empty")==0) {
		if(v.empty()) answer[i] = 1;
		else answer[i] = 0;
	 }
	 else if (temp1.compare("top")==0){
	 	if(v.empty()) answer[i] = -1 ;
	 	else answer[i] = v.top();
	 }
	 else {
	 
	 string temp2;
	 temp2=temp1.substr(5) ;
	 int num;
	 stringstream ssInt (temp2) ;
	 ssInt >> num ;
	 
	 v.push(num) ;
	   
     }
 		
			   
		
	}  // for(i) 
	
	for(int i=0; i < number ; i ++){
		if(answer[i]==-2) continue;
		printf("%d\n",answer[i]) ;
	}
	
		
}
