// Problem Statement  =>   https://leetcode.com/problems/game-of-life/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printBoard(vector<vector<int>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        
        int neighbours[board.size()][board[0].size()];
        
        // counting neighbours for each cell
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int curr_neigh = 0;
                
                if(i - 1 >= 0)
                    curr_neigh += board[i-1][j];
                if(i + 1 < board.size())
                    curr_neigh += board[i+1][j];
                if(j - 1 >= 0)
                    curr_neigh += board[i][j-1];
                if(j + 1 < board[i].size())
                    curr_neigh += board[i][j+1];
                if(i - 1 >= 0 && j - 1 >= 0)
                    curr_neigh += board[i-1][j-1];
                if(i + 1 < board.size() && j + 1 < board[i].size())
                    curr_neigh += board[i+1][j+1];
                if(i + 1 < board.size() && j - 1 >= 0)
                    curr_neigh += board[i+1][j-1];
                if(i - 1 >= 0 && j + 1 < board[i].size())
                    curr_neigh += board[i-1][j+1];
                
                neighbours[i][j] = curr_neigh;
            }
        }
        
        // updating state of each cell based on neighbours
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 0 && neighbours[i][j] == 3)
                    board[i][j] = 1;

                if(board[i][j] == 1){
                    if(neighbours[i][j] < 2)
                        board[i][j] = 0;
                    if(neighbours[i][j] > 3)
                        board[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution sol;

    vector<vector<int>> board
    {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };

    cout << "\nCurrent State of Board:\n";
    sol.printBoard(board);

    sol.gameOfLife(board);

    cout << "\nNext State of Board:\n";
    sol.printBoard(board);

    return 0;
}