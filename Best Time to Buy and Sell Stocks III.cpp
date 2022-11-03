#include <bits/stdc++.h>
using namespace std;

int f_Tab(vector<int> &prices)
{
	int n = prices.size();

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

	for (int ind = n - 1; ind >= 0; ind--)
	{
		for (int buy = 0; buy <= 1; buy++)
		{
			for (int cap = 1; cap <= 2; cap++)
			{
				int profit = 0;
				if (buy)
				{
					profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
				}
				else
				{
					profit = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
				}

				dp[ind][buy][cap] = profit;
			}
		}
	}

	return dp[0][1][2];
}


int f_Mem(int ind, vector<int> &prices, int buy, int cap, int n, vector<vector<vector<int>>> dp)
{
	if (cap == 0) return 0;
	if (ind == n) return 0;

	if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

	int profit = 0;
	if (buy)
	{
		profit = max(-prices[ind] + f_Mem(ind + 1, prices, 0, cap, n, dp), f_Mem(ind + 1, prices, 1, cap, n, dp));
	}
	else
	{
		profit = max(prices[ind] + f_Mem(ind + 1, prices, 1, cap - 1, n, dp), f_Mem(ind + 1, prices, 0, cap, n, dp));
	}

	return dp[ind][buy][cap] = profit;
}

int f(int ind, vector<int> &prices, int buy, int cap, int n)
{
	if (cap == 0) return 0;
	if (ind == n) return 0;

	int profit = 0;
	if (buy)
	{
		profit = max(-prices[ind] + f(ind + 1, prices, 0, cap, n), f(ind + 1, prices, 1, cap, n));
	}
	else
	{
		profit = max(prices[ind] + f(ind + 1, prices, 1, cap - 1, n), f(ind + 1, prices, 0, cap, n));
	}

	return profit;
}

int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
	return f_Mem(0, prices, 1, 2, n, dp);
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