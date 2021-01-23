#include <iostream>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std ;
deque<int> d; 

int main () {
	cin.tie(NULL);
	ios::sync_with_stdio(false) ;
	int t_case ; 
	cin >> t_case ;
	
	
	for (int i =0 ; i < t_case ; i ++) {
		bool check = false ;
		int n ;
		string temp1,temp2 ;
	 
		cin >> temp1 ;
		char func[temp1.length()+1];
		strcpy(func,temp1.c_str()) ;
		cin >> n ;  
		int tempX=0;
		while (1) {
			char temp = getchar();
			if (temp >= '0' && temp <= '9') {
				tempX *= 10;
				tempX += temp - '0';
			}
			else if (temp == ',') {
				d.push_back(tempX);
				tempX = 0;
			}
			else if (temp == ']') {
				if (tempX != 0) {
					d.push_back(tempX);
				}
				tempX = 0;
				break;
			}
		}

		
		for (int j=0 ; func[j]!='\0' ; j ++) {
			if (func[j]=='R') {
					reverse(d.begin(),d.end());
			}
			else { // 'D'
				if(d.empty()) {
					cout << "error\n" ; check = true ; 
							
		deque<int> empty ;
		swap(d,empty) ;
		
					break ;
					
				}
				else {
					d.pop_front() ;
				}
			}
		} // j (func)
		
		if (!check) {
			int rep = d.size() ;
			cout <<"[" ;
			for(int j=0; j < rep ; j ++) {
				if ( j== rep-1) cout << d.front() ;
				else cout << d.front() << ",";
				d.pop_front();
			}
			cout << "]\n" ;
		}
		

		
	}
	
	
}
