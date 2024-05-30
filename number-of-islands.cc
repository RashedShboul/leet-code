//Basic DFS problem 
//Fri 19 Apr 7:17pm 
//Time complixty at the worst case where all the grid is 1's O(nm)
#include<iostream>
#include<vector>
using namespace std; 

class Solution {
private: 
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j) {
        vis[i][j] = 1; 
        for (int k = 0; k<4; ++k) {
            int x = i + dx[k]; 
            int y = j + dy[k]; 
            if (x >= 0 && y >= 0 && x < grid.size()
                && y < grid[0].size() && grid[x][y] == '1' && !vis[x][y])
                    dfs(grid,vis,x,y); 
        }
    }

    //Function to check the boundery of a node in the matrix
    /*bool validBound(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m; 
    }*/
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        int ans = 0; 
        vector<vector<bool> > vis(n ,vector<bool>(m,false)); 
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid,vis,i,j); 
                    ans++; 
                }
            }
        }
        return ans; 
    }
};