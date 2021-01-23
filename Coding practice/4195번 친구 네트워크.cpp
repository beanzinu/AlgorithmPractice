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
/* 유니온 파인드 */ 


int main (void) {
	int test_case ;
	scanf("%d",&test_case ) ;
	for (int i=0; i < test_case ; i ++) {
		
		int friend_case ; 
		scanf("%d",&friend_case) ;
		
		int count = 0 ;
		string Friend[friend_case*2+1] ; // 친구관계수 F*2  이 최대 친구 수  + 1 
		int parent[friend_case*2+1] ;
		for(int i=0; i< friend_case*2+1 ; i ++) {  // 초기 화    
			parent[i] = i ;
		}
		
		for(int j= 0 ; j < friend_case ; j ++) {
			string tem1,tem2 ;
			cin >> tem1 >> tem2 ;
			 
			if(count!=0){
				bool same= true ;
				for(int k=0; k < count ; k++) {
					if(tem1.compare(Friend[k])) { 
					same = false ; // 첫번째가 겹칠 경우 
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
					 same = false; // 두번 째가 겹칠 경우 
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
				// 하나도 안 겹칠 경우
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

