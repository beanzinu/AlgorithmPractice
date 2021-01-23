#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	int amount, coin =0 ;
	
	cin >> amount ;
	
	amount = 1000 - amount ;   // ÀÜµ·  
	
	while (1){
		if (amount >=500 ) {
			amount = amount - 500 ;
			coin ++;
		}
		else if ( amount >=100){
			amount = amount - 100 ; 
			coin ++;
		}  
		else if ( amount >=50){
			amount = amount - 50 ; 
			coin ++;
		}  
		else if ( amount >=10){
			amount = amount - 10 ; 
			coin ++;
		}  
		else if ( amount >=5){
			amount = amount - 5 ; 
			coin ++;
		}  
		else if ( amount >=1){
			amount = amount - 1 ; 
			coin ++;
		}  
		else break;
	}
	
	cout << coin ;
	
	return 0;
}
