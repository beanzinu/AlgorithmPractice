#include <iostream>
#include <math.h>
using namespace std;
int K , num, dir , answer;
char s[5][9] ;
int Left[5] ;
int Right[5] ;

void Clockwise(int index) {
	Left[index]--;
	Right[index]--;
	if(Left[index]==0) Left[index] = 8;
	if(Right[index]==0) Right[index] = 8;
}
void CounterClockwise(int index) {
	Left[index]++;
	Right[index]++;
	if(Left[index]==9) Left[index] = 1;
	if(Right[index]==9) Right[index] = 1;
}

void CheckRight(int index,int dir) {
	if(index <=4 && s[index][Left[index]] != s[index-1][Right[index-1]])
	CheckRight(index+1,-dir) ;
	else return ;
	if (dir == 1) Clockwise(index) ;
	else CounterClockwise(index);
	
		
}

void CheckLeft(int index,int dir) {
	if(index >=1 && s[index][Right[index]] != s[index+1][Left[index+1]])
	CheckLeft(index-1,-dir) ;
	else return ;
	if (dir == 1) Clockwise(index) ;
	else CounterClockwise(index);
		
}

int main(){
	for(int i=1 ; i<=4 ; i++) {
		for(int j=1 ; j<=8 ; j++) {
			cin >> s[i][j] ;	
		}
	}
	
	for(int i=1;i<=4 ; i++) {
		Left[i] = 7 ; Right[i] = 3 ;
	}
	cin >> K ;
	while(K--) {
		cin >> num >> dir ;
	// ¿À¸¥ÂÊ Åé´Ï¹ÙÄû
	CheckRight(num+1,-dir) ;
	// ¿ŞÂÊ Åé´Ï¹ÙÄû 
	CheckLeft(num-1,-dir) ; 
	// num Åé´Ï¹ÙÄû  
	if (dir==1) Clockwise(num) ;
	else CounterClockwise(num) ;
	}
	
	for(int i=1 ; i<=4 ; i++) {
		int target = Right[i];
		for (int j=1 ; j<=2 ; j++) {
				target-- ;
			if(target == 0) target = 8 ;
		}
		if(s[i][target]=='1') answer = answer + pow(2,i-1) ;
	}
	
	cout << answer ;
	
	
}
