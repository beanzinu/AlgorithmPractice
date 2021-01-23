#include <iostream>
#include <algorithm> 
using namespace std;

int arr[9][9] ;
int temparr[9][9] ;
int wall[3] ;
int N,M ;

int Max ; int temp ;
void make_virus(int i,int j) {
	if (i+1 < N && arr[i+1][j]==0) {
		arr[i+1][j]=1 ; make_virus(i+1,j) ;
	}
	if (j+1 < M && arr[i][j+1]==0) {
		arr[i][j+1]=1 ; make_virus(i,j+1) ;
	}
	if (i-1 >=0 && arr[i-1][j]==0) {
		arr[i-1][j]=1 ;make_virus(i-1,j) ;
	}
	if ( j-1 >=0 && arr[i][j-1]==0) {
		arr[i][j-1]=1 ; make_virus(i,j-1) ;
	}
}
void make_wall(int index1,int index2,int count) {
	
	if (count == 3) {
		copy(arr,arr+9,temparr) ;
		
		for (int i=0 ; i < count ; i++) {
			int n1 = wall[i] /10 ;
			int n2 = wall[i] %10 ;
			arr[n1][n2] = 1;
		
 		}
 	
		for (int i=0; i < N ; i++) {
			for (int j=0 ; j < M ; j++) {
				if(arr[i][j]==2) arr[i][j]= 1 ; make_virus(i,j) ;
			}
		}
		for (int i = 0 ; i  < N ; i++) {
			for (int j =0 ; j < M ; j++ ) {
				if(arr[i][j]==0)  temp++ ;
			}
		}
		cout << temp << ' ' ;
		copy(temparr,temparr+9,arr) ;
		if ( temp > Max )  {
			Max = temp ; temp = 0 ;
		}
		else temp = 0 ;
		return ;
	}
	
	
	for (int i=index1 ; i < N ; i++) {
		if ( i == index1) ;
		else index2 = 0;  
		for (int j=index2; j < M ; j++) {
			if (arr[i][j]==0) {
				wall[count] = 10*i + j ;
				make_wall(i,j+1,count+1) ;
			}	
		}
	}	
}



int main() {

	cin >> N >> M ;
	for (int i =0 ; i < N ; i++) {
		for (int j= 0 ; j <  M ; j++) {
			cin >> arr[i][j] ;
		}
	}
	make_wall(0,0,0) ;
	printf("%d",Max) ;
}
