#include <bits/stdc++.h>
using namespace std;

int f_Tab(vector<vector<int>>& triangle, int n)
{
    int dp[n][n];

    for(int j = 0; j < n; j++)
    {
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i = n-2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i+1][j];
            int dia = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down, dia);
        }
    }

    return dp[0][0];
}

int f(int x, int y, vector<vector<int>>& triangle, int n)
{
    if(x == n - 1) return triangle[n - 1][y];

    int down = triangle[x][y] + f(x+1, y, triangle, n);
    int dia = triangle[x][y] + f(x+1, y+1, triangle, n);

    return min(down, dia);
}

int minimumTotal(vector<vector<int>>& triangle)
{
    return f_Tab(triangle, triangle.size());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n;

    vector<vector<int>> triangle;

    for(int i = 0; i < n; i++)
    {
        vector<int> temp;
        while()
        {
            int x;
            cin >> x;

            temp.push_back(x);
        }

        triangle.push_back(temp);
    }

    cout << minimumTotal(triangle) << endl;

    return 0;
}