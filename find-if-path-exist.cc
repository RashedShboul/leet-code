#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n]; 
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]); 
        }
        vector<bool> vis(n,false); 
        dfs(adj,vis,source); 
        return vis[source] && vis[destination];  
    }
private: 
    void dfs(vector<int> adj[], vector<bool> &vis, int v) {
        vis[v] = true; 
        for (auto u : adj[v]) {
            if (!vis[u]) 
                dfs(adj,vis,u); 
        }
    }
};