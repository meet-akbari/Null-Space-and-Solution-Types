#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap_Rows(int m,int n,float A[m][n+1], int rowIndex)
{
	printf("\t-----------> Entered in the Row Swapping Method...\n");
	float temp;
	int i, j, k, l;
	for(i=rowIndex + 1; i < m; i++){
		if(A[i][rowIndex] != 0){
			int temp;
			for(j=0; j<=n; j++){
				temp = A[i][j];
				A[i][j] = A[rowIndex][j];
				A[rowIndex][j] = temp;
			}
			break;
		}
	}	
}
