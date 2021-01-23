#include <cstdio>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() { 
string A ;
string B ;

cin >> A ;
cin >> B ;

char A1[A.length()];
char B1[B.length()];

strcpy(A1,A.c_str()) ;
strcpy(B1,B.c_str()) ; 

int dif = B.length() - A.length() ;

int count= 51 ; 

for (int i = 0 ; i<= dif ; i ++){
    int temp = 0 ; 
   for (int j = 0 ;  j < A.length() ; j++ ) { 
        if ( A1[j] == B1 [j+i]) continue ;
        else temp ++ ;
   }

     if ( temp < count)  count = temp ; 
}
   if (count == 51)  cout << 0 ;
   else cout << count  ;
   


}
