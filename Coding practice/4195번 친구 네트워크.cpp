#include <iostream>
#include <vector>

using namespace std;



int getParent(int parent[],int x) {
	if(parent[x] == x) return x ;
	return parent[x] = getParent(parent,parent[x]);
}
int unionParent(int parent[],int a,int b) {
	a=getParent(parent,a) ;
	b=getParent(parent,b) ;
	
	if ( a < b) return parent[b] = a ;
	return parent[a] = b ;
	 	
}
int findParent(int parent[],int a,int b) {
	a=getParent(parent,a) ;
	b=getParent(parent,b) ;
	if (a==b) return 1;
	return 0 ;	
}  
/* ���Ͽ� ���ε� */ 


int main (void) {
	int test_case ;
	scanf("%d",&test_case ) ;
	for (int i=0; i < test_case ; i ++) {
		
		int friend_case ; 
		scanf("%d",&friend_case) ;
		
		int count = 0 ;
		string Friend[friend_case*2+1] ; // ģ������� F*2  �� �ִ� ģ�� ��  + 1 
		int parent[friend_case*2+1] ;
		for(int i=0; i< friend_case*2+1 ; i ++) {  // �ʱ� ȭ    
			parent[i] = i ;
		}
		
		for(int j= 0 ; j < friend_case ; j ++) {
			string tem1,tem2 ;
			cin >> tem1 >> tem2 ;
			 
			if(count!=0){
				bool same= true ;
				for(int k=0; k < count ; k++) {
					if(tem1.compare(Friend[k])) { 
					same = false ; // ù��°�� ��ĥ ��� 
						Friend[count] = tem2 ;
						unionParent(parent,count,k) ;
					     count ++ ;
					     	int num=0 ;
						for(int t=0; t < count ; t ++ ) {
						
							if(findParent(parent,t,k)) num ++ ;
						}	
							cout << num <<endl; 				 
						}
							
				     else if(tem2.compare(Friend[k])) {  
					 same = false; // �ι� °�� ��ĥ ��� 
						Friend[count] = tem1 ;
						unionParent(parent,count,k) ;
					     count ++ ;
					     int num=0 ;
						for(int t=0; t < count ; t ++ ) {
							
							if(findParent(parent,t,k)) num ++ ;
						}
						cout << num <<endl;				 
				     }	 
					     
				}  
				// �ϳ��� �� ��ĥ ���
				if ( same){
				
				Friend[count] = tem1 ;
				Friend[count+1] = tem2;
				unionParent(parent,count,count+1) ; 
				int num = 0;
				for(int t=0; t < count ; t ++ ) {
							
							if(findParent(parent,t,count) )num ++ ;
						}
						count=count+2 ;
						cout << num <<endl;
			
			}
		}  // if (count ! = 0 )
			
			
        	else {
        		Friend[count] = tem1 ;
				Friend[count+1] = tem2;
				unionParent(parent,count,count+1) ; 
				count=count+2 ;
				
				cout << "2" <<endl;
			}
	 
	
			
			

		 	
}  // j
 
}  //i

}  

