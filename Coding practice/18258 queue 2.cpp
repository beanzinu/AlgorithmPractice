#include <iostream>
#include <queue>
using namespace std;

queue<int> q ;
int main() {
	cin.tie(NULL) ;
	ios::sync_with_stdio(false) ;
	int n; 
	scanf("%d",&n);
	int print[n+1] ;
	int count =0 ;
	
	string temp ;
	int num;
	

for(int i=0 ; i  < n ; i ++)	{
	cin >> temp ; // push,pop,size,empty,front,back
	
	if (temp.compare("push") == 0 ) {
		cin >> num ;
		q.push(num) ;
	}
	else if (temp.compare("pop") == 0 ) {
		if (q.empty()) print[count++] = -1 ;
		else {
 		print[count++] = q.front() ;
		q.pop() ;
			}
	}
	else if (temp.compare("size") == 0 ) {
		print[count++] = q.size() ;
	}
	else if (temp.compare("empty") == 0 ) {
		if(q.empty()) print[count++] = 1 ;
		else print[count++] = 0;
	}
	else if (temp.compare("front") == 0 ) {
		if (q.empty()) print[count++] = -1 ;
		else print[count++] = q.front() ;
	}
	else if (temp.compare("back") == 0 ){
		if (q.empty()) print[count++] = -1 ;
		else print[count++] = q.back() ;
	}


}

for (int i =0 ; i < count ; i ++) {
	printf("%d\n",print[i]);
}


}


