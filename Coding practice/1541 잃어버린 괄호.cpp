#include <iostream>

using namespace std;
int num[50] ;
int num_count ;
char input[51]; 
int tempX ;
int plus_count =0 ;
int main() {
	
scanf("%s",input) ;
bool plus = true ;

for(int i=0; input[i]!='\0';i++){
	if(input[i]>='0'&&input[i]<='9') {
		tempX = tempX*10 ;
		tempX = tempX+(input[i]-'0'); 
	}
	else if (input[i]=='+'||input[i]=='-'){
	num[num_count++]=tempX ;
	tempX=0;
	if (plus) {
		plus_count++ ;
	}
	if (input[i]=='-') plus = false ;
	}
	
	if(input[i+1]=='\0'&& plus){
	 num[num_count++] = tempX ; plus_count++ ; }
	else if(input[i+1]=='\0'&&!plus) {
		num[num_count++] ;
	}
}
int result =0;
for(int i=0; i< plus_count;i++){
	result = result + num[i] ;
}	
for(int i = plus_count ; i <  num_count ; i++) {
	result= result - num[i] ;
}

printf("%d",result) ;	
	
	
	
}
