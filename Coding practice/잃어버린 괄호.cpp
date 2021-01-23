#include <cstdio>
#include <sstream>
#include <iostream>
#include <cctype>



using namespace std;


int check(char x){
	if ( x>=0 && x<=9)
	return 1;
	else return 0;
}
	
	
int main() {

char temp[50] = { -1 };
int num[50];
int count = 0 ;

scanf("%s",&temp);

    int i = 0;  int j = 0 ;
	while ( 1 ){
		if (!check(temp[i]))   break;
		
		if ( check(temp[i+4]) && check(temp[i+3])&&check(temp[i+2])&&check(temp[i+1])){
		       num[j]= temp[i+4]*10000+temp[i+3]*1000+temp[i+2]*100+temp[i+1]*10+temp[i]; 
		       j++; count ++ ;  i = i +6 ;
	     }
	     else if (  check(temp[i+3])&&check(temp[i+2])&&check(temp[i+1])){
		       num[j]= temp[i+3]*1000+temp[i+2]*100+temp[i+1]*10+temp[i]; 
		       j++; count ++ ;  i = i +5 ;
	     }
	     else if ( check(temp[i+2])&&check(temp[i+1])){
		       num[j]= temp[i+2]*100+temp[i+1]*10+temp[i]; 
		       j++; count ++ ;  i = i +4 ;
	     }
	     else if (check(temp[i+1])){
		       num[j]= temp[i+1]*10+temp[i]; 
		       j++; count ++ ;  i = i +3 ;
	     }
	     else if (check(temp[i])){
		       num[j]=(int)temp[i];
		       j++; count++; i=i+2; 
		 }
	}
    
    int answer= num[0];
    for (int i=1; i<count; i++){
    	answer= answer - num[i];
	}

     cout << answer ; 

} 
