#include <bits/stdc++.h>
using namespace std;

int f_SOP(int n)
{
    int a = 1;
    int b = 1;

    int c = 0;
    for(int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int f_dp(int n, vector<int> &dp)
{
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        int one = dp[i-1];
        int two = dp[i-2];

        dp[i] = one + two;
    }

    return dp[n];
}

int f(int n)
{
    if(n == 0) return 1;

    if(n < 0) return 0;

    int one = f(n-1);
    int two = f(n-2);

    return one + two;
}

int climbStairs(int n)
{
    vector<int> dp(n+1, 0);
    return f_SOP(n);
}

int main()
{
    int n;
    cin >> n;

    int ans = climbStairs(n);

    cout << ans;

    return 0;
}