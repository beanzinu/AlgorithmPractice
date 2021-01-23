/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <math.h>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int number ;
		cin >> number; 
		int arr[number+1] ;
		
		for(int i=0 ; i < number ; i++) cin >> arr[i] ;
		
		int dif = 0;
		int dif_temp ;
		bool PASS = false ;
		for (int i= 0 ; i < number-1 ; i++) {
		    dif_temp = arr[i+1] - arr[i] ;
		    
		    if ( i== 0 ) {
		    	dif = dif_temp ; continue ;
			}
		    
		    if (dif == 0 && dif_temp == 0) continue ;
		    else if ( dif != 0 && dif_temp == 0 ) {
		    	PASS = true ; break ;
			}
		    else if (dif == 0 && dif_temp != 0) {
		    	PASS = true ; break ;
			}
		    else {
		    	if (dif % dif_temp == 0 || dif_temp % dif == 0) {
		    		if ( dif > dif_temp)  dif = dif_temp ;
				}
				else {
					PASS= true ; break; 
				}
			}
		    
		}
		if (PASS) Answer = 0 ;
		else if ( dif == 0) Answer = 1 ;
		else {
		    int count = 0;
		    for (int i=1 ; i<=sqrt(dif) ; i++) {
		        if ( i == sqrt(dif) ) count++ ;
		        else if (dif % i == 0) count = count + 2;
		    }
		    Answer = count ;
		}
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
