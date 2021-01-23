#include <iostream>

using namespace std; 

int main() {
	int n , m ;
	cin >> n >> m ;
	int num[n+1] ;
	int size = n ;
	
	for (int i=1 ; i <=n ; i ++ ) {
		num[i] = i ;
		
	}
	int count = 0 ; 
	for(int i = 0 ; i  < m ; i++){
		int target ;
		cin >> target ;
		
		int index ; 
		
		for(int j= 1 ; j <= size ; j ++) {
			if(num[j]== target) index = j ; 
		} 
		
		if ( index <= size/2+1 ) {
			int temp[index-1] ;
			for(int j = 0 ; j < index-1 ; j++ ) {
				temp[j] = num[j+1] ;
			}
			for(int j= index+1 ; j <=size ; j++) {
				num[j-index] = num[j] ; 
				
			}
			int k = 0 ;
			for(int j= size-index+1 ; j <= size-1 ; j ++) {
				num[j] = temp[k]; k ++ ;
			}
			count = count + index-1 ;
		}
		else {
			int temp[size-index] ; int k = 0 ;
			for(int j=index+1 ; j <=size ; j ++){
				temp[k] = num[j] ; k++;
			}
			for (int j= index-1 ; j>=0 ; j-- ){
				num[j+size-index] = num[j] ;
			}
			for (int j = 1 ; j <= size- index ;j++ ){
				num[j] =temp[j-1] ;
			}
			count= count + size-index+1 ;
			
		}
		
		size-- ;
	}
	cout << count ; 
	
}
