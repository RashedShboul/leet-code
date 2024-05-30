#include<iostream>
#include<vector>
#include<queue>
using namespace std; 

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(); 
        int m = land[0].size(); 
        vector<vector<int>> ans; 
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!land[i][j])
                    continue;
                
                int x = i; 
                int y = j; 
                while (y < m && land[i][y]) ++y;//find the right most col 
                while (x < n && land[x][j]) ++x;//find the bottom most row
                //x and y after the wile loops will be +1 
                y = !y ? y = y : y-1; 
                x = !x ? x = x : x-1;   
                ans.push_back({i,j,x,y});
                for (int k=i; k<=x; ++k) {
                    for (int q=j; q<=y; ++q)
                        land[k][q] = 0; 
                } 
            }
        }
        return ans; 
    }
};