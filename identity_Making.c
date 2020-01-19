#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void identity_Making(int m,int n,float A[m][n+1],int solution_Type)
{   
	
	int min = 0;
	if(n > m){
		min=m;
	}else{
		min = n;
	}
	int i,j,k;
	for(i=0;i<min;i++)
	{
		float row_pivot = A[i][i];
		if(row_pivot)
		{
			for(j=0;j<n+1;j++)
			{
				A[i][j] /= row_pivot;
			}
			
		}
		
	}
	if(solution_Type == 1 || solution_Type == 2) // 1 for Unique Solution, 2 for Infinite solution
	{
		printf("\n-----------------------------------------------------------------------------------------\n"); 
		printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Solution Of Equations -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
		if(m==n)
		{
			for(i=0;i<n;i++)
			{
				if(A[i][i] != 0)
				{
					printf("x%d = %.3f\n",i+1,(A[i][n])/A[i][i]);
				}
			}
		}
		else if(m<n)
		{
			for(i=0;i<n;i++)
			{
				
				if(A[i][i] != 0)
				{
					printf("x%d = %.3f\n",i+1,((A[i][n]-(A[i][n-1]))/A[i][i]));
				}
			}
		}
		else if(m>n)
		{
			for(i=0;i<n;i++)
			{
				if(A[i][i] != 0)
				{
					printf("x%d = %.3f\n",i+1,(A[i][n]/A[i][i]));
				}
			}
		}
	}
}
