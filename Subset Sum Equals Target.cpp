#include <bits/stdc++.h>
using namespace std;

bool f_Tab(vector<int>& nums, int k)
{
    int n = nums.size();

    bool dp[n][k + 1];

    //1st base case
    for (int i = 0; i < n; i++) dp[i][0] = true;

    //2nd base case
    if (nums[0] <= k) dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool notPick = dp[i - 1][j];

            bool pick = false;
            if (j >= nums[i]) pick = dp[i - 1][j - nums[i]];

            dp[i][j] = pick | notPick;
        }
    }

    return dp[n - 1][k];
}

bool f_Mem(int i, vector<int>& nums, int k, vector<vector<bool>>& dp)
{
    if (k == 0) return true;

    if (i == 0) return (nums[0] == k);

    if (dp[i][k] != false) return dp[i][k];

    bool notPick = f_Mem(i - 1, nums, k, dp);

    bool pick = false;
    if (k >= nums[i]) pick = f_Mem(i - 1, nums, k - nums[i], dp);

    return dp[i][k] = notPick | pick;
}

bool f(int i, vector<int>& nums, int k)
{
    if (k == 0) return true;

    if (i == 0) return (nums[0] == k);

    bool notPick = f(i - 1, nums, k);

    bool pick = false;
    if (k >= nums[i]) pick = f(i - 1, nums, k - nums[i]);

    return notPick | pick;
}

bool subsetSumToK(vector<int>& nums, int k)
{
    int n = nums.size();

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    return f_Tab(nums, k);
}

int main()
{
    int n; cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k; cin >> k;

    cout << subsetSumToK(nums, k) << endl;

    return 0;
}