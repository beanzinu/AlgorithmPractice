/* ���� �켱 Ž�� (DFS) 

 - ���� ( Stack ) �� ����.
 
 1. ������ �ֻ�� ��带 Ȯ���մϴ�.
 2. �ֻ�� ��忡�� �湮���� ���� ���� ��尡 ������ �׳�带 ���ÿ� �ְ� �湮ó���մϴ�. �湮���� ���� ��尡 ������ �ֻ�� ��带 ��
  
  
  */
  
#include <iostream>
#include <vector>

using namespace std;

int number = 7 ;
int c[7] ; // �湮ó��
vector<int> a[8] ;

void dfs(int x) {
	if( c[x]) return ;
	c[x] = true ;
	cout << x << ' ';
	for(int i=0; i< a [x].size(); i ++){
		int y= a[x][i] ;
		dfs(y) ;		 
	}
	
}  
  
int main(void) {
	 a[1] . push_back(2) ;
   a[2] . push_back(1) ;
   
   a[1] . push_back(3) ;
   a[3] . push_back(1) ;
   
   a[2] . push_back(3) ;
   a[3] . push_back(2) ;
   
   a[4] . push_back(2) ;
   a[2] . push_back(4) ;
   
   a[5] . push_back(2) ;
   a[2] . push_back(5) ;

   a[3] . push_back(6) ;
   a[6] . push_back(3) ;
   
   a[3] . push_back(7) ;
   a[7] . push_back(3) ;

   a[4] . push_back(5) ;
   a[5] . push_back(4) ;
   
   a[6] . push_back(7) ;
   a[7] . push_back(6) ;


  dfs (1) ;
  
	
}

