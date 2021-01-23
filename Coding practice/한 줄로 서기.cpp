# include <stdio.h>

int main (int argc, char** argv ){
	 int Person ; 
	 
	 scanf("%d",&Person); 
	 
	 int height[Person]={0};
	 int number[Person]={0}; 
	 
	 for(int i=0;i<Person;i++)
	    scanf("%d",&number[i]);  
	 
	 
	 for (int i=1; i<=Person ; i++){
          
		  	 for ( int j=0; j < Person ; j ++){
			   
	 	       if ( number[i-1] > 0 &&  height[j]== 0) {
                        number[i-1]--; continue;
						}
				    else if ( number[i-1] > 0 && height[j]!= 0 ) continue;
					else if ( number[i-1] == 0 && height[j]!=0) continue;
					else if ( number[i-1] == 0 && height[j]==0) {
						height[j]=i;
						break;
						}
	         }
		
		}
	
	for ( int i=0; i<Person ; i++) printf("%d ",height[i]);
}

	 


