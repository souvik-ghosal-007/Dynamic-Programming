#include <bits/stdc++.h>
using namespace std;

int f_Tab(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int dp[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else
            {
                int up = 1e9, left = 1e9;

                if (i > 0) up = grid[i][j] + dp[i - 1][j];

                if (j > 0) left = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n-1][m-1];
}

int f(int x, int y, vector<vector<int>>& grid)
{
    if(x == 0 && y == 0) return grid[0][0];

    if(x < 0 || y < 0) return 1e9;

    int up = grid[x][y] + f(x-1, y, grid);
    int left = grid[x][y] + f(x, y-1, grid);

    return min(up, left);
}

int minPathSum(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    return f_Tab(grid);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << minPathSum(grid) << endl;

    return 0;
}