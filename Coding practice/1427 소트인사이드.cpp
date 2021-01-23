#include <iostream> 
#include <algorithm>

using namespace std;
bool compare(char a,char b){
	return a > b;
}

char num[1000000001] = { 'a' , };

int main(void) {
	int temp ;
	scanf("%d",&temp) ;
	sprintf(num,"%d",temp) ;   // int to char array Çüº¯È¯ 
	
	for(int i=0; num[i] != 'a' ; i ++)
	 printf("%d",num[i]) ;  
	 
	for(int i=0; num[i] !=0 ; i ++ ) {
		
		if(num[i+1]==0) {
			sort(num,num+i,compare) ;
		}
	
	}
	
	for(int i=0; num[i] != 0 ; i ++)
	 printf("%d",num[i]) ;  
	
}
