#include <stdio.h>
#include <stdbool.h>

#define N 5

int sol[N][N] = {0};
int visited[N][N] = {0};

bool isSafe(int M[N][N], int i, int j);
bool solveMaze(int M[N][N], int x, int y, int sol[N][N]);

void print(int sol[N][N]){
    int i,j;
    for( i=0; i<N; i++){
        printf("\n");
        for(j=0; j<N; j++){
            printf("%d ", sol[i][j]);
        }
    }
}

bool isSafe(int M[N][N], int i, int j){
    if( i>=0 && i<N && j>=0 && j<N && M[i][j]==1){
        return true;
    }
    return false;
}

bool Mazepath(int M[N][N]){
    if(!solveMaze(M, 0, 0, sol)){
            printf("Solution doesn't exist");
            return false;
    }
    print(sol);
    return true;
}

bool solveMaze(int M[N][N], int x, int y, int sol[N][N]){
    if(x==N-1 && y==N-1){
        sol[x][y] = 1;
        return true;
    }



    if(isSafe(M, x, y) == true){
        sol[x][y] = 1;
        visited[x][y] = 1;

        if(!visited[x+1][y] && solveMaze(M, x+1, y, sol)) return true;
        if(!visited[x][y+1] && solveMaze(M, x, y+1, sol)) return true;
        if(!visited[x-1][y] && solveMaze(M, x-1, y, sol)) return true;
        if(!visited[x][y-1] && solveMaze(M, x, y-1, sol)) return true;

        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main(){

int M[N][N] = 	{ {1, 1, 1, 0, 1},
                  {0, 0, 1, 1, 1},
                  {1, 1, 1, 0, 1},
                  {1, 0, 0, 0, 1},
                  {1, 1, 1, 1, 1}
                };
    Mazepath(M);
    return 0;
}


