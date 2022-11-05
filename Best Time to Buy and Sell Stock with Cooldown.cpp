#include <bits/stdc++.h>
using namespace std;

int f_Tab(vector<int> &prices, int n)
{
	vector<vector<int>> dp(n + 2, vector<int>(2, 0));

	for (int ind = n - 1; ind >= 0; ind--)
	{
		for (int buy = 0; buy <= 1; buy++)
		{
			int profit = 0;
			if (buy)
			{
				profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
			}
			else
			{
				profit = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
			}

			dp[ind][buy] = profit;
		}
	}

	return dp[0][1];
}

int f(int ind, int buy, vector<int>& prices, int n)
{
	if (ind >= n) return 0;

	int profit = 0;
	if (buy)
	{
		profit = max(-prices[ind] + f(ind + 1, 0, prices, n), f(ind + 1, 1, prices, n));
	}
	else
	{
		profit = max(prices[ind] + f(ind + 2, 1, prices, n), f(ind + 1, 0, prices, n));
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