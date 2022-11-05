#include <bits/stdc++.h>
using namespace std;

int f_Tab(vector<int> &coins, int amt)
{
	int n = coins.size();

	vector<vector<int>> dp(n, vector<int>(amt + 1, 1e9));

	for (int i = 0; i <= amt; i++)
	{
		if (i % coins[0] == 0) dp[0][i] = i / coins[0];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= amt; j++)
		{
			int notPick = dp[i - 1][j];

			int pick = 1e9;
			if (j >= coins[i]) pick = 1 + dp[i][j - coins[i]];

			dp[i][j] = min(pick, notPick);
		}
	}

	return dp[n - 1][amt];
}

int f(int ind, vector<int> &coins, int amt)
{
	if (ind == 0)
	{
		if (amt % coins[0] == 0) return amt / coins[0];

		else return 1e9;
	}

	int notPick = f(ind - 1, coins, amt);

	int pick = 1e9;
	if (amt >= coins[ind]) pick = 1 + f(ind, coins, amt - coins[ind]);

	return min(pick, notPick);
}

int coinChange(vector<int>& coins, int amount)
{
	int n = coins.size();

	int ans = f_Tab(coins, amount);

	if (ans == 1e9) return -1;

	else return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;

	vector<int> coins(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	int amount; cin >> amount;

	cout << coinChange(coins, amount);

	return 0;
}