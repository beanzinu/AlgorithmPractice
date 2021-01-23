#include <cstdio>
#include <stack>
using namespace std;
char s[101];
stack<char> St;

int main(){
	scanf("%s",s) ;
	for(int i=0;s[i]!='\0';i++) {
		
		
		if(s[i]>='A'&&s[i]<='Z') printf("%c",s[i]);
		else {
			if(s[i]=='+'|| s[i]=='-') {
				while(!St.empty()&&St.top()!='(') {
					printf("%c",St.top());St.pop();
				}
				St.push(s[i]);
			}
			else if(s[i]=='*'|| s[i]=='/') {
				while(!St.empty()&&(St.top()=='*'||St.top()=='/')){
				printf("%c",St.top());St.pop();
				}
				St.push(s[i]);
			}
			else St.push(s[i]) ;
		}
			
			
		
		if(!St.empty()&&St.top()==')'){
			St.pop();
			while(St.top()!='('){
			printf("%c",St.top()); St.pop();}
			St.pop();
		}
		
	}	
		while(!St.empty()){
			printf("%c",St.top()); St.pop();}
			
}
