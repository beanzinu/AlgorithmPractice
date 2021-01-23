#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > v ;
int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	int T ;
	cin >> T;
	for(int i = 0 ; i < T ; i++ ) {
		int N ;
		cin >> N ;
		bool result[N+1] = {false, } ;
		int answer = 0 ;
		
		for (int j = 0 ; j < N ; j++) {
			int n1,n2 ;
			cin >> n1 >> n2;
			v.push_back(make_pair(n1,n2));
		}
		sort(v.begin(),v.end());
		int min = N+1;
		for (int j=0 ; j < v.size(); j++)  {
			if ( v[j].second < min) {
				min = v[j].second ;
				result[j] = true;
			}
			if (v[j].second == 1) break;
		}
		
		for(int j=0; j< N;j++){
			if(result[j]==true) answer++ ;
		}
		cout << answer << '\n' ;
		
		// º¤ÅÍ ÃÊ±âÈ­
		v.clear() ; 
	}
}
