#include <bits/stdc++.h>
using namespace std;

int f_Tab(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int dp[n][m];

    for(int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int lDia = 1e9;
            if(j > 0) lDia = matrix[i][j] + dp[i - 1][j - 1];

            int rDia = 1e9;
            if(j < m-1) rDia = matrix[i][j] + dp[i - 1][j + 1];

            dp[i][j] = min(up, min(lDia, rDia));
        }
    }

    int mini = dp[n-1][0];

    for(int j = 1; j < m; j++)
    {
        mini = min(mini, dp[n-1][j]);
    }

    return mini;
}

int f(int i, int j, vector<vector<int>>& matrix, int n)
{
    if (j < 0 || j >= n) return 1e9;

    if (i == 0) return matrix[0][j];

    int up = matrix[i][j] + f(i-1, j, matrix, n);

    int lDia = matrix[i][j] + f(i-1, j-1, matrix, n);

    int rDia = matrix[i][j] + f(i-1, j+1, matrix, n);

    return min(up, min(lDia, rDia));
}

int minFallingPathSum(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = 1e9;

//    for (int j = 0; j < m; j++)
//    {
//        ans = min(ans, f_Tab(matrix));
//    }

    ans = f_Tab(matrix);

    return ans;
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

    cout << minFallingPathSum(grid) << endl;

    return 0;
}