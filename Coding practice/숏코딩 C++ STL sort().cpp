/* C++ STL sort()  �Լ�
 # include <iostream
 # include <vector> 
 # include <algorithm>
 
 using namespace std;
 
 int main(void) { 
 
 vector<pair<int,stirng > > v ;
 v.push_back(pair<int,string>(90,"�� �� ��"));
 
 '''
 '''
 '''
 '''
 
 '''
 sort(v.begin(),v.end());
 
 for(int i=0; i<v.size() ;i++){
  cout << v[i].second << ' ';
   }
   
(second �� �ι�° ������ -> string Ÿ���� ������ �ǹ�)
   
   // ª�� �ڵ��ϴ� ����� '���ڵ�' �̶�� �մϴ�.
   
   -���� STL�� ���Ҹ� ���������� ���� �� ������ �Ҽ� �ֽ��ϴ�.
     �迭�� ���� ����ϱ� ���� ������ �ڷᱸ�� 
   -��� STL�� �ѽ��� �����͸� ó���� �� �ִ� �ڷᱸ 
  
  bool compare(pair<string,pair<int,int>> a, ''' b)
  
  if (a.second.first == b.second.first) {
  return a.sencond.second > b.sencond.second ;
}
  else { 
  return a.second.first > b.second.first ;
}
  
  vector<pair<string,pair<int,int>> v; 
  
  
  sort(v.begin(),v.end(),compare) ;
