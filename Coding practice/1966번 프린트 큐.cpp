#include <iostream>
#include <queue>

using namespace std; 


queue<pair<int,int> > q;

int main() {
	int test_case ; 
	cin >> test_case ;
	
	int ans[test_case] ;
	int ans_count = 0 ; 
	
	for(int i = 0 ; i < test_case ; i ++) {
		
		int n, m ;
		cin >> n >> m ; 
		
		for(int j=0 ; j  <  n ; j ++) {
			
			
			int temp ;
			cin >> temp ;
			q.push(make_pair(j,temp)) ; // 중요도  
		}
		
		
		int count = 1 ; bool stop = true;
		
		while (stop) {
			int max = 0 ;
			
			for(int j=0; j < q.size() ; j ++){   // 중요도 제일 높은 값 찾기 
				if(q.front().second >= max ) max = q.front().second ;
				pair<int,int> r = make_pair(q.front().first,q.front().second) ;
				q.pop() ;
				q.push(r) ; 
			}
			
			for (int j = 0 ;  j  < q.size() ; j ++) {  // 몇번째로 인쇄되는지 찾 기   
				if (q.front().second == max ) {
					if (q.front().first== m) {
						ans[ans_count++] = count ;
						stop = false ;
						break ; 
					}		
					else {
					q.pop() ;
					count ++ ;
					break ;
						}
				}
				else {
					pair<int,int> r = make_pair(q.front().first,q.front().second) ;
					q.pop() ;
					q.push(r) ;
				}
			}	 
			
			
		} // while 
		
		queue<pair<int,int> > empty ; 
		swap(q,empty) ;
		
	} // i
	
	// 출력
	
	for (int i = 0 ; i < ans_count ; i ++) {
		
		cout << ans[i] << '\n' ;
	} 
	
	
}
