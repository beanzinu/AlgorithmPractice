#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std; 

vector<pair<int,pair<string,int> > > v ;

bool compare(pair<int,pair<string,int> > a,pair<int,pair<string,int> > b) {
	
	if ( a.first != b.first)
	   return a.first < b.first ;
	else 
	   return a.second.second < b.second.second ;   
	
}


int main() {
	
	int num ;
	scanf("%d",&num) ;
	
	int count =0;
	
	for(int i=0; i < num ; i++) {
		
		int age; string name ;
		cin >> age >> name ;
		v.push_back(make_pair(age,make_pair(name,count))) ;
		count ++ ;
			
	}
	
	sort(v.begin(),v.end(),compare) ;
	
	for(int i=0;i<num;i++) {
		
		cout << v[i] .first << ' ' << v[i].second.first << '\n' ;
		
	}
	
	
}
