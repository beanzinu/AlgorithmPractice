#include <iostream>
#include <algorithm>
#include <vector>

 
using namespace std;

bool compare(string a,string b){
	if (a.length() == b.length()){
		return a < b; 
	 }
	else   
	return a.length() < b.length() ;
	
	
}



int main(void) {
	int number;
	cin >> number;
	
	vector <string> v ;
	
	for(int i=0; i< number; i++) {
		string temp;
		cin >> temp;
		v.push_back(temp) ;
	}
	
	sort(v.begin(),v.end(),compare) ;
	
	string temp;
	for(int i=0; i< v.size(); i++) {
		if ( temp.compare(v[i]) == 0 ) continue ;
		temp = v[i] ;
		
		cout << v[i] << '\n' ;
	}
	
}
