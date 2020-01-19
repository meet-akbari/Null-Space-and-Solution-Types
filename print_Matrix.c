#include<stdio.h>
#include<stdlib.h>

void print_Matrix(int m,int n,float A[m][n+1])
{
    int i,j;  
    printf("\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j <= n; j++)
        {
        	if(j==n){printf("|");}
            printf("%0.2f\t",A[i][j]);            
        }
        printf("\n");
    }   
}
