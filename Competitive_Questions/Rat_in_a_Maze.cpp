// Problem Statement => https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool isSafe(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> visited){
        if( (x >= 0 && x < n) && (y >= 0 && y < n) && m[x][y] == 1 && visited[x][y] == 0 ){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m, int n, vector<vector<int>> visited, int x, int y, vector<string> &ans, string path){
        // base case => when dest is reached then add path in ans and return
        if(x == n - 1 && y == n - 1){
            ans.push_back(path);
            return;
        }
        
        // at location (x,y) so mark visited as true
        visited[x][y] = 1;
        
        
        // 4 ways to move at (x,y) which is down, left, right, up
        
        // for down
        int newX = x + 1, newY = y;
        if(isSafe(newX, newY, m, n, visited)){
            path.push_back('D');
            solve(m, n, visited, newX, newY, ans, path);
            path.pop_back();
        }
        
        // for left
        newX = x, newY = y - 1;
        if(isSafe(newX, newY, m, n, visited)){
            path.push_back('L');
            solve(m, n, visited, newX, newY, ans, path);
            path.pop_back();
        }
        
        // for right
        newX = x, newY = y + 1;
        if(isSafe(newX, newY, m, n, visited)){
            path.push_back('R');
            solve(m, n, visited, newX, newY, ans, path);
            path.pop_back();
        }
        
        // for up
        newX = x - 1, newY = y;
        if(isSafe(newX, newY, m, n, visited)){
            path.push_back('U');
            solve(m, n, visited, newX, newY, ans, path);
            path.pop_back();
        }
        
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0){
            return {};
        }
        
        vector<string> ans;
        string path = "";
        int srcX = 0, srcY = 0;
        
        vector<vector<int>> visited = m;
        for(int i = 0; i < m.size(); i++){
            for(int j = 0; j < m[0].size(); j++){
                visited[i][j] = 0;
            }
        }
        
        solve(m, n, visited, srcX, srcY, ans, path);
        return ans;
    }
};