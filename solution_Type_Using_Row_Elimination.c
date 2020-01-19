#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "print_Matrix.c"
#include "back_Substitution.c"
#include "zero_Raw_Checker.c"
#include "swap_Rows.c"

void solution_Type_Using_Row_Elimination(int m,int n,float A[m][n+1])
{
	printf("--------------------------------- Row Elimination ------------------------------------\n");
	
	int min = 0,i,j,k,l;          	// m : rows
	if(n > m) {			  			// n : columns
		min = m;
	} else {
		min = n;
	}
	
	for(i = 0; i < min; i++)
	{	
		float pivot = A[i][i];	
		if(pivot != 0){	
			for(j = i + 1; j < m; j++)
			{
				float coeff = A[j][i]/pivot;
				for(k = 0; k < n+1; k++)
				{
					A[j][k] -= coeff*A[i][k];
				}
			}
		}
		else if(pivot == 0){
			int check = 0;
			for(k=i+1; k<m; k++){
				if(A[k][i]!=0){
					check++;
				}
			}
			if(check > 0){
				swap_Rows(m,n,A,i);
			}
			
			pivot = A[i][i]; //this is extra....................
			if(pivot != 0){
				for(j = i + 1; j < min; j++)
				{
					float coeff = A[j][i]/pivot;
					for(k = 0; k < n+1; k++) //changed m to n................
					{
						A[j][k] -= coeff*A[i][k];
					}
				}
			}
		}
		print_Matrix(m,n,A);
		
	}
	int count = 0;
	for(i=0; i<min; i++)
	{
		if(A[i][i] != 0)
		{
			count++;
		}
	}
	if(m < n)    // Fat Matrix Logic..
	{
		printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Type Of Solution -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"); 
		printf("\n>>>>>>>>>>>>>>>      This System has INFINITE solution.       <<<<<<<<<<<<<<<\n");
		back_Substitution(m, n,A,2); // 2 suggests INFINITE solution.
	}
	else if(m == n) {               // Square Matrix Logic..
		if(count < n)              // count : Number of Pivots   
		{
			int i, j, Pivotyes = 0, PivotNo = 0;
			for(i=0; i<m; i++) {
				if(zero_Raw_Checker(m, n, A, i) == 1 && A[i][n] == 0){
					Pivotyes++;
				}
				if(zero_Raw_Checker(m, n, A, i) == 1 && A[i][n] != 0){
					PivotNo++;
				}
			}
			printf("%d",Pivotyes); // prints how many pivots.............................
			printf("%d",PivotNo); // prints how many non-pivots.............................
			
			if(PivotNo >= 1) {
				printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Type Of Solution -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"); 
				printf("\n>>>>>>>>>>>>>>>      This System has NO solution.       <<<<<<<<<<<<<<<\n");
		
				back_Substitution(m, n, A, 0); // 0 suggests NO Solution.
			}
			else if(Pivotyes >= 1) {
				printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Type Of Solution -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"); 
				printf("\n>>>>>>>>>>>>>>>      This System has INFINITE solution.       <<<<<<<<<<<<<<<\n");
		
		
				back_Substitution(m, n, A, 2); // 2 suggests INFINITE Solution.
			} 
			
		
		}
		else if(count == n)
		{
			printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Type Of Solution -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"); 
			printf("\n>>>>>>>>>>>>>>>      This System has UNIQUE solution.       <<<<<<<<<<<<<<<\n");
		
			back_Substitution(m,n,A,1);       // 1 suggests UNIQUE solution.
			
		}
	}
	else if(m > n){                         // Tall Matrix Logic..
		int cnt = 0;
		for(i = count; i<m; i++){
			if(A[i][n] == 0){
				cnt++;
			}
		}
		if(cnt == m-count){
			printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Type Of Solution -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"); 
			printf("\n>>>>>>>>>>>>>>>      This System has UNIQUE solution.       <<<<<<<<<<<<<<<\n");
		
			back_Substitution(m, n, A,1); // 1 suggests UNIQUE Solution.
			
		}
		else{
			printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Type Of Solution -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"); 
			printf("\n>>>>>>>>>>>>>>>      This System has NO solution.       <<<<<<<<<<<<<<<\n");
			back_Substitution(m, n, A,0); // 0 suggests NO Solution.
		}			
	} 
}

