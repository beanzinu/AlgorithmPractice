#include <iostream> 
#include <algorithm>
#include <cmath>
using namespace std;

int sum_average(int num[],int x) {  // 산술 평 균   
	int sum = 0 ;
	for(int i=0; i < x ; i++){
		sum= sum + num[i] ;
	}
	sum = round((double)sum/(double)x) ;
	return sum ;
}

int middle_num(int num[],int x) { // 중앙 값  
	sort(num,num+x) ;
	return num[x/2] ;
}

int frequency_num(int num[],int x) {  // 최빈값  
	
	int count[x] ;
	for(int i=0; i< x ; i ++) {  // 초기화 
		count[x] = 0 ;
	}
    
    sort(num,num+x) ; // 오름차순 정렬
	
	pair<int,int> max1,max2 ;
	max1 = make_pair(0,0) ; max2= make_pair(0,0) ;
	for (int i=0 ; i < x ; i ++) {
			int j = i+1 ;
			int count =1 ;
			
		while(true) {
			if(num[j] == num[i] ) {
				j++; count ++ ;
			}
			else break;
		}  // while 
		
		if (count > max1.first){
			max1.first = count  ; max1.second = i ;
		}
		else if ( count == max1.first && count > max2.first){
			max2.first = count ; max2.second = i ;
		}
		else ; // count == max1 && count == max2
		
		
		i= i+count-1;
		
		
	} // i 
	
	if ( max1.first == max2.first ) return num[max2.second] ;
	else return num[max1.second] ;
	
	
} 


int max_min(int num[],int x) {
	
	// 최대 값  
	int max = -4001 ;
	for(int i=0; i < x ; i++) {
	if( num[i] >=  max ) max = num[i]  ;
	}
	int min = 4001 ;
	for (int i=0; i < x ; i++) {
		if( min >= num[i] ) min = num[i] ;
	}
	return max-min ;
}


int num[500001] ;
int main() {
	int number;
	scanf("%d",&number) ;
	for (int i=0; i < number ; i++ ){
		scanf("%d",&num[i]) ;
	}
	printf("%d\n",sum_average(num,number)) ;
		printf("%d\n",middle_num(num,number)) ;
			printf("%d\n",frequency_num(num,number)) ;
				printf("%d\n",max_min(num,number)) ;
				
	
}
