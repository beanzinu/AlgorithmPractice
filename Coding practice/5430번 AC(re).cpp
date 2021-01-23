#include <iostream>
#include <string.h>
using namespace std;


int main() {
	cin.tie(NULL) ;
	int T ;
	cin >> T ;
	
	for (int i = 0 ; i  < T ; i++) {
	string temp1;
	cin >> temp1 ;
		char CharArr[temp1.length()+1];
		strcpy(CharArr,temp1.c_str()) ; 
	
	 	
	 int n ;
	 cin >> n ;   // 배열에 들어있는 수 
	 int num[n+1] ;
	 int num_count= 0;
	 int tempX = 0;
	 
	 while (1) {  // [1,2,3,4] 
	 	char temp = getchar() ;
	 	if (temp >= '0' && temp <= '9') {
	 		tempX = tempX *10 ;
	 		tempX = tempX + (temp - '0');
		 }
		else if(temp==','){
			num[num_count++] = tempX;
			tempX = 0 ;
		}
		else if(temp==']') {
			if(tempX!=0) {
				num[num_count++] = tempX;
			}
			break;
		}
		else continue ; 
		 
	 }
	int head = 0 ;
	int tail = num_count -1 ;

	int R_count = 0 ;
	bool err = false ;
	for (int j = 0 ; CharArr[j]!='\0' ; j++) {
		if( CharArr[j]== 'R') R_count ++ ;
		else if ( CharArr[j] == 'D' && head > tail ) {
		cout << "error\n" ; err = true ; break ;}
		else if ( CharArr[j]=='D' && R_count % 2 == 0) {
			num[head] = 0; head++ ;
		}
		else if ( CharArr[j]=='D' && R_count % 2 == 1) {
			num[tail] = 0 ; tail -- ;
		}
	}
	
	if (!err) {
		bool back = false ;  // Reverse 유 
	if (R_count%2 == 1) back = true;
	
 	cout << "[" ;
 	if (!back){
	for( int j = head  ; j  <= tail ; j++) {
		cout << num[j] ; 
		
		if ( j == tail ) break;
		else cout << "," ;
	}
	cout << "]\n" ;
		
	}
	else {
		for( int j = tail  ; j  >= head ; j--) {
		cout << num[j] ;
		
		if ( j == head ) break;
		else cout << "," ;
	}
	cout << "]\n" ;
		
	}
	}
	
	}  // i
	
	
	
}
