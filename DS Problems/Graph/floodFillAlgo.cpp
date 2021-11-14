#include<bits/stdc++.h>
using namespace std;
 
// Dimensions of paint screen
#define M 8
#define N 8
 

void dfs(int screen[][N], int srcX, int srcY, int newC, 
int oldC, int m, int n, vector<vector<int>> &vis){
    if(srcX<0 or srcY<0 or srcX>=n or srcY>=m) return;
    if(vis[srcX][srcY] or screen[srcX][srcY] != oldC) return;
    vis[srcX][srcY] = 1;
    screen[srcX][srcY] = newC;
    dfs(screen, srcX+1, srcY, newC, oldC, m, n, vis);
    dfs(screen, srcX-1, srcY, newC, oldC, m, n, vis);
    dfs(screen, srcX, srcY+1, newC, oldC, m, n, vis);
    dfs(screen, srcX, srcY-1, newC, oldC, m, n, vis);
}


void floodFill(int screen[][N], int x, int y, int newC, int m, int n)
{
    int prevC = screen[x][y];
    if(prevC==newC) return;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    dfs(screen, x, y, newC, prevC, m, n, vis);
}
 
// Driver code
int main()
{
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
    int x = 4, y = 4, newC = 3;
    floodFill(screen, x, y, newC, M, N);
 
    cout << "Updated screen after call to floodFill: \n";
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
           cout << screen[i][j] << " ";
        cout << endl;
    }
}