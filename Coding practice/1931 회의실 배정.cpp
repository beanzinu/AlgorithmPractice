#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > v;
int Con_count;
bool compare(pair<int,int> a,pair<int,int> b) {
	int First = a.second - a.first ;
	int Second = b.second - b.first ;
	if ( First== Second  ) return a.first < b.first ;
	else return First < Second ;
}

int main() {
	
	int N ;
	scanf("%d",&N) ;
	int N1,N2;
	for(int i = 0 ; i  <  N ; i++) {
	scanf("%d %d",&N1,&N2) ;
	v.push_back(make_pair(N1,N2)) ;
	}
	sort(v.begin(),v.end(),compare) ;
	
	int end_max =0;
	for(int i=0 ; i < N ; i ++) {
		if (v[i].second > end_max) end_max = v[i].second;
	}
	bool T_table[end_max+1] ; // 1 ~ end_max ±îÁö 
	for(int i=0 ; i <=end_max; i ++) {
		T_table[i] = false ;
	}
	
	for(int i=0; i < N ; i ++) {
		int start = v[i].first ;
		int end = v[i].second ;
		bool check_err  = false ;
		for (int j = start ;  j <= end ; j ++) {
			if(j== start || j== end) continue ;
			else if(T_table[j]== true){
				 check_err = true ; break;
			}
		}
		if (!check_err){
		for (int j = start ; j <=end ; j ++){
			T_table[j] = true ;
		}
		Con_count++;
		}
		else continue ;
		
		
	}
	printf("%d",Con_count) ;
}
