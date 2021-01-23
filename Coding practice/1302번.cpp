#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> v;

int main() {
	int N ;
	cin >> N ;
	
	string temp ;
	for(int i=0;i<N;i++) {
		cin >> temp ;
		v.push_back(temp) ;
	}
	sort(v.begin(),v.end()) ;
	
	int max = 0 ;
	int check = 0;
	string ans ;
	string demo ;
	

	for (int i= 0 ; i < N ; i++) {
		if(v[i].compare(demo) == 0) check++ ;
		else {
			if(check > max) {
			max = check ; ans= demo ;
			}
			check = 1 ; demo = v[i] ;  
		}
		
	}
	if(check > max) {
			max = check ; ans= demo ;
			}
	
	cout << ans ;
}
