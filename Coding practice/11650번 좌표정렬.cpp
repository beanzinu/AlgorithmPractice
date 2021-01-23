#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int> > v ;


bool compare(pair<int,int> a,pair<int,int> b) {
	if(a.second == b.second)
	return a.first < b.first ;
	else return  a.second < b.second ;
	
}

int main() {
	int num;
	scanf("%d",&num) ;
	
	for(int i=0; i < num ; i ++) {
		
	int x,y ;
	scanf("%d %d",&x,&y) ;
	v.push_back(make_pair(x,y)) ;	
		
	}
	sort(v.begin(),v.end(),compare) ;
	
	for(int i=0; i< v.size() ; i ++) {
		
		printf("%d %d\n",v[i].first,v[i].second) ;
	}
	
}
