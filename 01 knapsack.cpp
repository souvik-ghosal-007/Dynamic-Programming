#include <bits/stdc++.h>
using namespace std;

int f_Tab(int wt[], int val[], int capacity, int n)
{
	int dp[n][capacity + 1];

	for (int i = 0; i <= capacity; i++)
	{
		if (wt[0] <= i) dp[0][i] = val[0];
		else dp[0][i] = 0;
	}

	for (int i = 0; i < n; i++) dp[i][0] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			int notTake = dp[i - 1][j];

			int take = -1e9;
			if (j >= wt[i]) take = val[i] + dp[i - 1][j - wt[i]];

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n - 1][capacity];
}

int f(int ind, int wt[], int val[], int capacity)
{
	if (ind == 0)
	{
		if (capacity >= wt[0]) return val[0];

		else return 0;
	}

	int notTake = f(ind - 1, wt, val, capacity);

	int take = -1e9;
	if (capacity >= wt[ind]) take = val[ind] + f(ind - 1, wt, val, capacity - wt[ind]);

	return max(take, notTake);
}

int knapSack(int W, int wt[], int val[], int n)
{
	return f_Tab(wt, val, W, n);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;

	int price[n];
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}

	int weights[n];
	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	int capacity;
	cin >> capacity;

	cout << knapSack(capacity, weights, price, n) << endl;

	return 0;
}