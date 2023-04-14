#include <time.h>
#include <stdio.h>

#ifndef N
#define N 20 //numbers of queens
#endif

int solveQueens(int board[N][N],int col);
int isSafe(int board[N][N],int row,int col);
void printBoard(int board[N][N]);


int main(int argc, char const *argv[])
{

	int board [N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			board[i][j] = 0;
		}
	}
	clock_t start, end;
    double cpu_time_used;
	start = clock();
	solveQueens(board,0);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo: %.3f s\n", (cpu_time_used));
	return 0;
}

int solveQueens(int board[N][N],int col){
	if (col>=N)
	{
		printBoard(board);
		return 1;
	}
	for (int row=0; row<N; row++) {
			if (isSafe(board,row,col)){
				board[row][col] = 1;
				if (solveQueens(board,col+1)==1) {
					return 1;
				}
				board[row][col] = 0;
			}
		}
	return 0;
}
int isSafe(int board[N][N],int row,int col){
	for (int i=0; i<col;i++ )
			if (board[row][i]==1) 
				return 0;
		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return 0;
        for (int i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j] == 1)
                return 0;
	return 1;
}
void printBoard(int board[N][N]){
	for (int i=0; i<N;i++ ) {
		for (int j=0; j<N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}