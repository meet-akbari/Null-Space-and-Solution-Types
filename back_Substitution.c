#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "identity_Making.c"

void back_Substitution(int m,int n,float A[m][n+1],int solution_Type)
{	
	int min = 0;
	if(n>m){
		min=m;
	}else{
		min = n;
	}
	
	int i,j,k,l, count=0;
	printf("\n-------------------------------------------------------------------------------------\n");   
	printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Back Substitution -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	for(i = 0; i < min; i++){
		if(A[i][i] != 0){
			count++;
		}
	}
	
	for(i=min-1; i>=0; i--)
	{
		float pivot=A[i][i];
		if(pivot)
		{
			for(j=i-1;j>=0;j--)
			{			
				float coeff = A[j][i]/pivot;
				for(k=n;k>=0;k--)
				{
					A[j][k] -= coeff*A[i][k];
				}
			}
			print_Matrix(m,n,A);	
		}	
				
	}
	
	identity_Making(m,n,A,solution_Type);	
	
}
