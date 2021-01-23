#include <iostream>
#include <deque> 

using namespace std ;

deque<int> d ;

int main () {
	
	int n ;
	scanf("%d",&n) ;
	
	for (int i = 0 ; i  < n ;i ++) {
		string input ;
		scanf("%s",&input) ;
		if(input.compare("push_front")==0) {
			printf.flush();
			int num; scanf("%d",&num) ;
			d.push_front(num) ;	
		}
		else if (input.compare("push_back")==0) {
			int num; scanf("%d",&num); 
			d.push_back(num); 
		}
		else if (input.compare("pop_front")==0) {
			if(d.empty()) {
			printf("-1\n"); continue ; }
			printf("%d\n",d.front());
			d.pop_front();
		}
		else if (input.compare("pop_back")==0) {
			if(d.empty()) {
			printf("-1\n"); continue ; }
			printf("%d\n",d.back()) ;
			d.pop_back();
		}
		else if (input.compare("size")==0){
			printf("%d\n",d.size());
		}
		else if (input.compare("empty")==0) {
			if(d.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (input.compare("front")==0) {
			if(d.empty()) {
			printf("-1\n"); continue ; }
			printf("%d\n",d.front());
		}
		else if (input.compare("back")==0) {
			if(d.empty()) {
			printf("-1\n"); continue ; }
			printf("%d\n",d.back());
		}
	}
	
}
