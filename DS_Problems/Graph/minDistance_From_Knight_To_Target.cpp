#include <bits/stdc++.h>
using namespace std;

struct cell{
    int x, y;
    int dist;
    cell(){}; // Blank constructor
    cell(int x, int y, int dist) // Constructor with initial values
    : x(x), y(y), dist(dist){

    }
};

bool isInside(int x, int y, int N){
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

void findMinDistance(int kPos[], int tPos[], int N){
    cell c;
    queue<cell> q;
    int x, y;
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    vector<vector<int>> vis(N+1, vector<int> (N+1, 0));
    int ans;

    q.push(cell(kPos[0], kPos[1], 0));
    vis[kPos[0]][kPos[1]] = 1;

    while(!q.empty()){
        c = q.front();
        q.pop();

        if(c.x == tPos[0] and c.y == tPos[1]) {
            ans = c.dist;
            break;
        }
        for(int i=0;i<8;i++){
            x = dx[i]+c.x;
            y = dy[i]+c.y;

            if(isInside(x, y, N) and !vis[x][y]){
                vis[x][y] = 1;
                q.push(cell(x, y, c.dist+1));
            }
        }
    }

    cout<<"The min steps required = "<<ans<<endl;
}

int main(){
    int kPos[] = {1,1};
    int tPos[] = {30, 30};
    int N = 30;
    findMinDistance(kPos, tPos, N);

}