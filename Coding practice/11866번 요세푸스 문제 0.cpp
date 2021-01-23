#include <iostream>
#include <queue>

using namespace std;

queue<int> q ;
int main() {
	
 int n ;
 cin >> n ;
 int ans[n+1];
 int ans_count = 0; 
 
 for(int i = 1 ; i <= n  ; i ++){
 	q.push(i);
 }
 int m ; 
 cin >> m ;
 int count=1 ;
 while(!q.empty())	{
 	if(count % m == 0 ) {
 		ans[ans_count++] = q.front();
 		q.pop();
 		count ++;
	 }
	 else {
	 	int temp = q.front();
	 	q.pop();
	 	q.push(temp) ;
	 	count++ ;
	 }
 	
 }
 cout << '<' ;
 for(int i =0 ; i < ans_count ; i ++) {
 	if(i == ans_count-1) cout << ans[i] << '>'; 
	else  cout << ans[i] << ", ";
 	
 }
 
	
}

