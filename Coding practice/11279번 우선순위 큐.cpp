#include <iostream>
using namespace std;

int N , temp ;
int arr[100001] ;
int arr_count ;
void swap(int *a ,int *b) {
	int temp = *a ; *a = *b ; *b = temp ;
}

void push(int num) {
	arr[++arr_count] = num ;
	
	int child = arr_count ;
	int parent = child /2 ;
	
	while ( child > 1 && arr[child] < arr[parent]) {   // 최대 -> 최 소   
		swap(&arr[child],&arr[parent]) ;
		child = parent ;
		parent = child /2 ;
	}
} 
void pop() {
	cout << arr[1] << '\n';
	swap(&arr[1],&arr[arr_count--]) ;
	arr[arr_count+1] = 0;
	
	int parent = 1 ;
	int child = parent*2 ;
	if (child+1 <= arr_count) {  // 최대 -> 최 
	child = (arr[child] < arr[child+1]) ? child : child+1 ;
	}
	while ( child <= arr_count && arr[parent] > arr[child]){  // 최대 -> 최 소  
		swap(&arr[parent],&arr[child]) ;
		parent = child ;
		child = child*2 ;
		if (child+1 <=arr_count) {  // 최대 -> 최 소  
		child = (arr[child] < arr[child+1]) ? child : child+1 ;
		}
	}

}



int main() {
	cin.tie(NULL) ; ios::sync_with_stdio(false) ;
	cin >> N ;
	
	while(N--) {
	cin >> temp ;
	if ( temp  > 0)  push(temp) ;
	else if (temp == 0 && arr_count == 0 ){
		cout << "0" << '\n' ;
	}
	else {
		pop() ;
	}
	}
}
