#include <bits/stdc++.h>
using namespace std;

class Solution{
    private: 
        vector<vector<int>> board;
        int size;
        bool solved = false;
    public: 
        Solution(vector<vector<int>> b){
            board = b;
            size = 9;
        }

        void displayBoard(){
            cout<<"Board ===================\n"<<endl;
            for(auto it: board){
                for(auto x: it) {
                    cout<<x<<" ";
                }
                cout<<endl;
            }
            cout<<"===================\n"<<endl;
        }

        bool isSafe(int row, int col, int num){
            for(int i=0;i<size;i++){
                if(board[row][i]==num) return false;
                if(board[i][col]==num) return false;
            }
            int rs=(row/3)*3, cs=(col/3)*3;

            for(int i=rs;i<rs+3;i++){
                for(int j=cs;j<cs+3;j++){
                    if(board[i+rs][j+cs]==num) return false;
                }
            }
            return true;
        }

        void util(int row){
            if(solved){
                return;
            }
            if(row == size){
                displayBoard();
                solved = true;
                return;
            }
            for(int j=0;j<size;j++){
                if(board[row][j]!=0) continue;
                for(int n=1;n<=9;n++){
                    if(isSafe(row, j, n)){
                        board[row][j] = n;
                        util(row+1);
                        board[row][j] = 0;
                    }
                }
            }
        }

        void solve(){
            util(0);
        }
};

int main(){
    Solution s({
        {0,0,1,0,3,9,0,0,0},
        {0,7,2,0,0,0,0,9,0},
        {0,0,0,0,0,6,0,8,0},
        {0,5,0,0,0,0,0,0,0},
        {0,0,0,2,0,0,0,5,0},
        {3,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,3,0,0},
        {0,4,0,0,0,0,0,0,0},
        {9,0,0,0,4,0,0,0,5}
    });
    cout<<"Hello World"<<endl;
    s.solve();
}