#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct node{
	int value ;
	vector<node*> next;
	
};

int main() {
		string a="123";
		char s[100] ;
		strcpy(s,a.c_str());
		for(int i=0; s[i]!='\0';i++) {
			cout << s[i] ;
		}
		cout << "fin" ;
}
