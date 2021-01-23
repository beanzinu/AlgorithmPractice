 #include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc,char** argv){
	int N,M;

	 
	scanf("%d %d",&N,&M);
	
		int count = 0 ; // 출력 2
		char answer[M]; // 출력 1 
	
	cin.ignore(256,'\n');
	
	char string1[N][M]; 
     
  
    for(int i=0;i< N ; i++){
    	scanf("%s",string1[i]);
	}  
  

	
	for(int i=0;i<M;i++)
	{
		int DNA[4]={0};
			for(int j=0;j<N;j++)
			{
				switch(string1[j][i]){
				
					case 'A': DNA[0]++; break;
					case 'C': DNA[1]++; break;
					case 'G': DNA[2]++; break;
					case 'T': DNA[3]++; break;
				}
				
			}	
			int Max=0;
			for(int t=0;t<4;t++)
			    Max=max(Max,DNA[t]);

				if(Max==DNA[0])	 answer[i]='A'; 
				else if(Max==DNA[1]) answer[i]='C'; 
				else if(Max==DNA[2]) answer[i]='G'; 
				else if(Max==DNA[3]) answer[i]='T'; 
			
			count = count +DNA[0]+DNA[1]+DNA[2]+DNA[3] - Max ;
			
			
	}   
 for(int i=0;i<M;i++)
cout << answer[i] ;
cout << endl;
cout << count ;

}
