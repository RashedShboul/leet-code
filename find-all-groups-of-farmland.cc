#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
private:
    int dx[4] = {0,-1};
    int dy[4] = {1, 0};

public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();

        auto bfs = [&](int i, int j)
        {
            vector<int> tmp;
            tmp.push_back(i), tmp.push_back(j);
            queue<pair<int, int>> q;
            q.push({i, j});
            pair<int, int> xy; // bottom right
            while (!q.empty())
            {
                auto cur = q.front();
                land[cur.first][cur.second] = 0;
                q.pop();
                xy = cur;
                for (int k = 0; k < 2; ++k)
                {
                    int newX = cur.first + dx[k];
                    int newY = cur.second + dy[k];
                    if (newX < 0 || newY < 0 || newX >= n || newY >= m || land[newX][newY] == 0)
                        continue;

                    q.push({newX, newY});
                    land[newX][newY] = 0;
                }
            }
            tmp.push_back(xy.first), tmp.push_back(xy.second);
            ans.push_back(tmp);
        };

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (land[i][j] != 0)
                {
                    bfs(i, j);
                }
            }
        }
        return ans;
    }
};