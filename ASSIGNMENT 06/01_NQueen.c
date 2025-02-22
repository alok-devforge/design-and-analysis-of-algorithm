#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printSolution(int *board, int N)
{
    for(int x= 0;x<N;x++)
    {
        printf("%d", board[x]+1);
        if(x<N-1)
            printf(", ");
    }
}
int check(int *board, int row, int col)
{
    for(int x= 0;x<row;x++)
    {
        if(board[x]==col||abs(board[x]-col)==abs(x-row))
            return 0;
    }
    return 1;
}
void NQueens(int *board,int row,int n,int *soln)
{
    if(row==n)
    {
        printSolution(board,n);
        *soln= 1;
        return;
    }
    for(int col= 0;col<n;col++)
    {
        if(check(board,row,col))
        {
            board[row]= col;
            NQueens(board,row+1,n,soln);
            if(*soln)
                return;
        }
    }
}
int main()
{
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    int *board= (int*)malloc(n*sizeof(int));
    int soln= 0;
    printf("Soln for %d Queens: -\n",n);
    NQueens(board, 0, n, &soln);
    if(!soln)
        printf("No solution exists for %d queens.\n", n);
    free(board);
}