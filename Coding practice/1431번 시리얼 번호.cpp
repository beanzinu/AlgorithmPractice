#include <iostream>
#include <vector>
#include <algorithm>

int num ;

using namespace std;
// getSum 함수 만들기
// 중요 !! 
int getSum(string a) {
	int sum = 0;
	for(int i=0; i< a.length(); i++ ){
		// 숫자인 경우에만 더합니다 .
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0 )   // a[i] - '0' ( char 데이터형을 int 형으로 변환하는법 ) 
		  sum = sum + (a[i] - '0') ;
	}
	 return sum;
}

bool compare(string a,string b)  {
	
	if ( a.length() == b.length() ){
		int aSum = getSum(a) ;
		int bSum = getSum(b) ;
		if (aSum != bSum) {
			return aSum < bSum ;
		}
		else return a < b ;
	}
	else return a.length() < b.length() ;
	
}

int main(void) {
	
	vector <string> v ;
	
	cin >> num ;
	
	for(int i=0;i<num;i++){
		string temp;
		cin >> temp;
		v.push_back(temp) ;
	}
	
	sort(v.begin(),v.end(),compare);
	
	for(int i=0; i <num; i++) 
	  cout << v[i] << endl;
	

	
	
}


