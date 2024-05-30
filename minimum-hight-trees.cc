#include<vector>
#include<queue>
#include<utility> // for move function 
#include<algorithm>
using namespace std; 
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; 
        vector<int> adj[n]; 
        vis.resize(n); 
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]); 
        }
        vector<int> path = dfs(dfs(0,adj)[0],adj); 
        if (path.size() % 2 != 0) 
            return {path[path.size() / 2]}; 
        return {path[path.size()/2], path[path.size() / 2 - 1]}; 

    }
private:
    vector<bool> vis;
    vector<int> dfs(int v, vector<int> adj[]) {
        vector<int> longestPath,path; 
        vis[v] = true; 
        for (auto u : adj[v]) {
            if (!vis[u]) {
                //path = dfs(u,adj); 
                if (size(path = dfs(u,adj)) > size(longestPath))
                    longestPath = move(path); 
            }
        }
        vis[v] = false; //ensures that if the same vertex is reachable from a different path, it can be visited again.
        longestPath.push_back(v); 
        return longestPath; 
    } 
};