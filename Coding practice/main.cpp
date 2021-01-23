#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int line[1000000001] ;

vector<pair<pair<int,int>,pair<int,int> > > v;

bool compare(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b) {
	return a.second.first < b.second.first ;
	
}

int main(void) {
	int N ;
	cin >>  N ;
	int i = 1 ;
	while (N--) { // ют ╥б  
		int n1,n2,n3  ;
		cin >> n1 >> n2 >> n3 ;
		v.push_back(make_pair(make_pair(n1,n2),make_pair(n3,i++))) ;
	}
	sort(v.begin(),v.end(),compare) ;
	
	for(int i=0 ; i < N ; i++) {
		int start = v[i].first.first ;
		int end = v[i].first.second ;
		int height = v[i].second.first ;
		bool change = false ;
		
		for (int j=start ;  j <=end ; j++ ){
			if (height > line[j] ) {
				line[j] = height; change = true ;
			}
		}
		if (!change) v[i].second.second = 0 ;
	} // i
	int count = 0;
	for (int i= 0 ; i <  N ; i++) {
		if (v[i].second.second != 0) count++ ;
	}
	cout << count <<'\n' ;
	for (int i=0 ; i < N ; i++ ) {
		if (v[i].second.second != 0) cout << v[i].second.second << ' ';
	}
	return 0;
	
	
}
