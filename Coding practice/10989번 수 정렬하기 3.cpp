#include <iostream>

using namespace std;

int count[10001] ;   // ���������� ����� 0���� �ʱ�ȭ ��. 
int number ;
int main(void) {
	
	scanf("%d", &number) ;
	for(int i=0; i < number ; i++){
		int temp;
		scanf("%d",&temp) ;
		count[temp-1] ++ ;
				
	}
	 
	for (int i=0; i< 10001 ; i++) {   // num ���� 10001 �� �ð��� �� ���԰ɸ� ?? 
	
		while(count[i]!= 0) {
			printf("%d\n",i+1) ;
			count[i] -- ;	
		    }
		}
	}  
	  
	    
	
	

