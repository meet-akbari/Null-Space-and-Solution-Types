#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int zero_Raw_Checker(int m, int n,float A[m][n+1], int indexRow){
	int i, cnt = 0;
	
	for(i=0; i<n; i++){
		if(A[indexRow][i] == 0 || A[indexRow][i] == (float)(-0)) {
			cnt++;
		}
	}
	
	if(cnt == n){
		return 1;
	}
	else {
		return 0;
	}
}
