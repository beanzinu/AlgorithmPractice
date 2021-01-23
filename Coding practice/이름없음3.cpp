#include <stdio.h>
#include <algorithm>
using namespace std;
int  N;
int num[100000001] ;
int num_count ;
int arr[101] ;
int main() {
	scanf("%d",&N) ;
	
	for (int i = 0 ; i < N ; i++) {
		scanf("%d",&arr[i]) ;
	}
	sort(arr,arr+N) ;
	
	
	for (int i = 2  ; i <= arr[1] ; i++) {
		if (arr[0]%i == arr[1]%i ) num[num_count++] = i ;
	}
	int temp = 0;
	while (temp!=num_count) {
		for (int i =2 ; i < N ;i++) {
			if (arr[i] % num[temp] != arr[0] % num[temp]) {
				num[temp] = 0 ; break;
			}
		}
			temp ++ ;	
	}
	for (int i =0 ; i < num_count ; i++) {
		if (num[i]== 0) continue;
		printf("%d ",num[i]);
	}
	

	
}
