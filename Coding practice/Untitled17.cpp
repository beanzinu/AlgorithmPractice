#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> numbers ;
char s[1001][11]  ;
bool c[1001] ; 
int Round ;

bool compare(int a,int b) {
	char A[11],B[11];
	 sprintf(A,"%d",a) ;
	 sprintf(B,"%d",b) ;
	if(A[Round]-'0'> B[Round]-'0') return a>b ;
	else return a<b ;
}

void big(int start,int end,int round) {
	Round = round ;
	sort(numbers[start],numbers[end],compare);
	
	
	
}




int main() {
	numbers.push_back(6) ;
	numbers.push_back(10) ;
	numbers.push_back(2);
	for(int i=0 ; i<numbers.size() ;i++) {
		sprintf(s[i],"%d",numbers[i]) ;
	}
	
	
	
	

}
