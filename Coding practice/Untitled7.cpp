#include <iostream>
#include <vector>
#include <string.h> 
using namespace std;
vector<string> phone_book;
int TC;
struct node{
	
	int value ;
	vector<node*> next;
	
};
bool check[10];
node* n ;
int main() {
	cin >> TC ;
	
	bool answer ;
	while(TC--){
		answer = true ;
	int rep ;
	string input ; 
	cin >> rep ;
	while(rep--) {
		cin >> input ;
		phone_book.push_back(input);
	}	
	
	n=new node[11];
	
	
	for(int i=0;i<phone_book.size();i++){
	
	char ch[30];
	strcpy(ch,phone_book[i].c_str());
	
	node *current;
	
	bool hit = false;
	node *new_node ; 
	
	for(int j=0;ch[j]!='\0';j++){
		if(j==0){
			current= &n[ch[j]-'0'] ;
			if(check[ch[j]-'0']||(current->next.size()>0 && ch[j+1]=='\0')) {
				answer = false; hit =true ; break;
			}
			
			if(ch[j+1]=='\0') check[ch[j]-'0'] = true ;
		}
		
	
		current->value = ch[j]-'0';
		
		
		if(hit&&(current->next.size()==0||ch[j+1]=='\0')) {
			answer=false; break;
		}
		if(ch[j+1]=='\0') break;
		
		if(current->next.size()==0 && ch[j+1]!='\0'){
			new_node = new node;
			current->next.push_back(new_node) ;  
			current = new_node ;
			hit = false ;
			continue ;
		}
		else {
			for(int k=0; k<current->next.size();k++){
				//hit
				if(current->next[k]->value==ch[j+1]-'0') {
					
					current = current->next[k] ;
					hit = true ;
					break;
				}
				//no hit
				if(k==current->next.size()-1) {
					
					new_node =new node; 
					current->next.push_back(new_node) ;  
					current = new_node ;
					hit = false ;
				} 
			}	
		}
	}//j
	
	if(hit) break;
 }//i
 	
	if(answer) cout << "YES\n" ;
	else cout << "NO\n" ; 
	phone_book.clear();	
	
	
}//TC

}
