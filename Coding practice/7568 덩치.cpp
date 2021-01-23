#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > v;
int N ;

int main() {
	cin >> N ;
	for (int i =0; i < N ; i++) {
		int n1,n2 ;
		scanf("%d %d",&n1,&n2) ;
		v.push_back(make_pair(n1,n2)) ;
	}
	
	for (int i=0; i< N ;i++) {
		int k = 0 ;
		for (int j=0; j < N ; j++) {
			if (v[j].first > v[i].first && v[j].second > v[i].second) k++ ;
		}	
		cout << k+1 << ' ' ;
	}
	
}
