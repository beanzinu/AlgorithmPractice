#include <iostream>
#include <queue> 
using namespace std ;
vector<int> v[101] ;
bool c[101] ;
int N , M;
int count ;

void virus(int start) {
	c[start] = true ;
	queue<int> q ;
 	for (int i = 0 ; i < v[start].size() ; i++) {
		q.push(v[start][i] ) ;
		
	} 
	while(!q.empty()) {
		int temp = q.front() ;
 		q.pop() ;
		if (!c[temp]) {
			c[temp] = true ;
			for (int i= 0; i < v[temp].size() ; i++) {
				int y = v[temp][i] ;
				if (c[y])	{
					continue;
				}
				else q.push(y) ;
			}
		}
	}
 	
}




int main() {
	cin >>  N ;
	cin >> M ;
	for (int i = 0 ;i < M  ;i++) {
		int n1,n2 ;
		cin >> n1 >> n2 ; 
		v[n1].push_back(n2) ;	
		v[n2].push_back(n1) ;
	}
	virus(1) ;
	
	for (int i =2 ; i <= N ; i++) {
		if(c[i]==true) count++;
	}
	cout << count ;
	
	
	
	
	
}
