/* 스택 
 삽입 ( 7 ) 삽입 ( 5 ) 삽입(4) 삭제 삽입(6) 삭제
 
 
                        4   5  7   
						 (삭제)
						    5    7
						6   5   7 	 
						(삭제) 
						    5   7 
						     
#include <stack> 

stack<int> s;
s.push(7)
s.pus(5);
s.push(4);
s.pop();
s.push(6);
s.pop();
whilel(!s.empty()){
cout << s.top() << ' ' ;
s.pop();  }

*큐

-FIFO   

#include <queue>

queue<int> q ;
q.push(7)
q.push(5) 
'''

while(!q.empty()){
cout << q.front() << ' ' ;
q.pop() ; 
}






