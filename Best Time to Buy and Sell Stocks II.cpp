#include <bits/stdc++.h>
using namespace std;

int f_Tab(vector<int> &prices, int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));

	dp[n][0] = dp[n][1] = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= 1; j++)
		{
			int profit = 0;
			if (j)
			{
				profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
			}
			else
			{
				profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
			}

			dp[i][j] = profit;
		}
	}
	return dp[0][1];
}

int f(int ind, vector<int> &prices, int buy, int n)
{
	if (ind == n) return 0;

	int profit = 0;
	if (buy)
	{
		profit = max(-prices[ind] + f(ind + 1, prices, 0, n), f(ind + 1, prices, 1, n));
	}
	else
	{
		profit = max(prices[ind] + f(ind + 1, prices, 1, n), f(ind + 1, prices, 0, n));
	}

	return profit;
}

int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	return f_Tab(prices, n);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;

	vector<int> prices(n);
	for (int i = 0; i < n; i++)
	{
		cin >> prices[i];
	}

	cout << maxProfit(prices) << endl;

	return 0;
}