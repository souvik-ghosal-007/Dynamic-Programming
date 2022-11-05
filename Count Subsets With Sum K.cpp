#include <bits/stdc++.h>
using namespace std;

int f_Tab(vector<int>& nums, int k)
{
	int n = nums.size();

	vector<vector<int>> dp(n, vector<int>(k + 1, 0));

	for (int i = 0; i < n; i++)
	{
		dp[i][0] = 1;
	}

	dp[0][nums[0]] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int notPick = dp[i - 1][j];

			int pick = 0;
			if (j >= nums[i]) pick = dp[i - 1][j - nums[i]];

			dp[i][j] = pick + notPick;
		}
	}

	return dp[n - 1][k];
}

int f(int i, vector<int>& nums, int k)
{
	if (i == 0)
	{
		if (k == 0 && nums[0] == 0) return 2;

		if (k == 0 || k == nums[0]) return 1;

		else return 0;
	}

	int notPick = f(i - 1, nums, k);

	int pick = 0;
	if (k >= nums[i]) pick = f(i - 1, nums, k - nums[i]);

	return pick + notPick;
}

int countSubsetSumToK(vector<int>& nums, int k)
{
	int n = nums.size();

	int sum = 0;
	for (auto it : nums)
	{
		sum += it;
	}

	int target = (sum - k) / 2;

	return f_Tab(nums, target);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;

	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	int k; cin >> k;

	cout << countSubsetSumToK(nums, k) << endl;

	return 0;
}