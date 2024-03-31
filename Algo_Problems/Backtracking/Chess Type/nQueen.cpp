#include <bits/stdc++.h>
using namespace std;

class Solution{
    private: 
        vector<vector<int>> board;
        int size;
    public: 
        Solution(int n){
            board.resize(n, vector<int>(n, 0));
            size = n;
        }

        void displayBoard(){
            cout<<"Board ===================\n"<<endl;
            for(auto it: board){
                for(auto x: it) {
                    if(x==1) cout<<"Q"<<" ";
                    else cout<<"_"<<" ";
                }
                cout<<endl;
            }
            cout<<"===================\n"<<endl;
        }

        bool isSafe(int row, int col){
            for(int i=0;i<size;i++){
                if(board[row][i]==1) return false;
                if(board[i][col]==1) return false;
            }
            int i=row, j=col;
            while(i>=0 && j>=0){
                if(board[i][j]==1) return false;
                i--, j--;
            }
            i=row, j=col;
            while(i>=0 && j<size){
                if(board[i][j]==1) return false;
                i--, j++;
            }
            return true;
        }

        void util(int row){
            if(row == size){
                displayBoard();
                return;
            }
            for(int j=0;j<size;j++){
                if(isSafe(row, j)){
                    board[row][j] = 1;
                    util(row+1);
                    board[row][j] = 0;
                }
            }
        }

        void solve(){
            util(0);
        }
};

int main(){
    Solution s(6);
    cout<<"Hello World"<<endl;
    s.solve();
}