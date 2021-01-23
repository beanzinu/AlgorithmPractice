#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

vector<pair<pair<int,int>,pair<int,int> > > v;

bool compare(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b) {
	return a.second.first > b.second.first ;
	
}

int main(void) {
	int N ;
	cin >>  N ;
	int num = 1 ;
	int Max =0 ;
	
	for(int i =0; i < N ; i++ ) { // 입 력  
		int n1,n2,n3  ;
		cin >> n1 >> n2 >> n3 ;
		
		v.push_back(make_pair(make_pair(n1,n2),make_pair(n3,num++))) ;
		if (n1+n2 > Max) Max = n1+n2 ;
	}
	
	bool line[Max+1] = {0, } ;

	
	sort(v.begin(),v.end(),compare) ;

	
	for(int i=0 ; i < N ; i++) {
		int start = v[i].first.first ;
		int end = v[i].first.first+v[i].first.second-1 ;
		bool change = false ;
		
	if (line[start] != true || line[end] != true ){
		for (int j=start ;  j <=end ; j++ ){
			if (line[j] == false ) {
				line[j] = true ;change = true ;
			}
		}
	}
		if (!change) v[i].second.second = 0 ;
	} // i
	// 출 력  
	int count = 0;
	for (int i= 0 ; i <  N ; i++) {
		if (v[i].second.second != 0) count++ ;
	}
	cout << count <<'\n' ;
	for (int i=0 ; i < N ; i++ ) {
		if (v[i].second.second != 0) cout << v[i].second.second << ' ';
	}

	
	
}
