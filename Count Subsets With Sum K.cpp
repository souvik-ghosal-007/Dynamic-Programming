#include <bits/stdc++.h>
using namespace std;

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

	return f(n - 1, nums, k);
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