/* C++ STL sort()  함수
 # include <iostream
 # include <vector> 
 # include <algorithm>
 
 using namespace std;
 
 int main(void) { 
 
 vector<pair<int,stirng > > v ;
 v.push_back(pair<int,string>(90,"박 한 울"));
 
 '''
 '''
 '''
 '''
 
 '''
 sort(v.begin(),v.end());
 
 for(int i=0; i<v.size() ;i++){
  cout << v[i].second << ' ';
   }
   
(second 는 두번째 데이터 -> string 타입의 정보를 의미)
   
   // 짧게 코딩하는 방법은 '숏코딩' 이라고 합니다.
   
   -벡터 STL은 원소를 선택적으로 삽입 및 삭제를 할수 있습니다.
     배열을 보다 사용하기 쉽게 개편한 자료구조 
   -페어 STL은 한쌍의 데이터를 처리할 수 있는 자료구 
  
  bool compare(pair<string,pair<int,int>> a, ''' b)
  
  if (a.second.first == b.second.first) {
  return a.sencond.second > b.sencond.second ;
}
  else { 
  return a.second.first > b.second.first ;
}
  
  vector<pair<string,pair<int,int>> v; 
  
  
  sort(v.begin(),v.end(),compare) ;
