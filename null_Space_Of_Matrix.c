#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void null_Space_Of_Matrix(int m,int n,float A[m][n+1])
{
	int i,number_of_pivots=0,j=0,k=0,l=0,s=0;
	int minimum_row_column;
	if(m < n) {
		minimum_row_column = m;
	} else {
		minimum_row_column = n;
	}
	for(i=0;i<minimum_row_column;i++)
	{
		if(A[i][i]!=0)
		{
			number_of_pivots++;
		}
	}
	
	int rawzero=0;
	
	int pivot=0;
	
	if(n > m) {			  
		minimum_row_column = m;
	} else {
		minimum_row_column = n;
	}
	for(l=0;l<m;l++)
	{
		if(zero_Raw_Checker(m,n,A,l) == 1)
		{
			printf("called");
			rawzero++;
		}
	}
	int rows_new = m - rawzero;
	float mat_zero_row[rows_new][n]; // logic for descarding the whole zero row
	
	int z=0;
	for(l=0;l<m;l++)
	{
		if(zero_Raw_Checker(m,n,A,l) == 0)
		{
			for(j=0;j<n;j++)
			{
				mat_zero_row[z][j] = A[l][j];
			}
			z++;
			
		}
	
	}
	/*
	swapping if  whole column is zero than we have to swap with pivot column for finding null space.
	*/
	int *swap_column = (int *)calloc(n,sizeof(int));
	float temp=0;
	int cnt=0;
	for(i=0; i<n-1; i++)
	{
		for(j=i; j<rows_new; j++)
		{
			if(mat_zero_row[j][i]==0){
				cnt++;
			}
		}
		if(cnt==rows_new-i){
			int pivot_column = i;
			while(pivot_column<n){
				int next_col = pivot_column+1;
				if(cnt==rows_new-i && mat_zero_row[i][next_col]!=0)
				{
					for(k=0; k<rows_new; k++)
					{
						temp = mat_zero_row[k][i];
						mat_zero_row[k][i] = mat_zero_row[k][next_col];
						mat_zero_row[k][next_col] = temp;
					}
						swap_column[i] = next_col;
						swap_column[next_col] = i;
						break;
				}
				else{
					pivot_column++;
				}
			}
		}
		
		cnt = 0;
	}
	
	float F[rows_new][n-rows_new];

	int r=0,c=0;
	
	for(i=0;i<rows_new;i++)
	{
		c=0;
		
		for(j=number_of_pivots;j<n;j++)
		{
			F[i][c] = -mat_zero_row[i][j];
			
				c++;
			
		}
		printf("\n");
		
	}
	printf("\n-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+ Null Space Of Matrix -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"); 
	
		
	
	
	float I[c][c];
	
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j)
			{
				I[i][j] =1;
				
			}
			else
			{
				I[i][j] = 0;
			}
		}
	}
	if((rows_new) >= n)
	{
		for(i =0;i<n;i++)
		{
			printf("\t0.00\t\n");
		}
		
		
	}
	else{
		
		for(i=0;i<rows_new;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("\t%.2f\t",F[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<c;i++)
		{
			if(i < (rows_new))
			{
				for(j=0;j<c;j++)
					{
						printf("\t%.2f\t",I[i][j]);
					}
					printf("\n");
			}
			
		}
	}
	
	printf("\n--------------------------------------------------------------------------------------------\n"); 
}


