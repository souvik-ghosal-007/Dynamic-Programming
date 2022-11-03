#include <bits/stdc++.h>
using namespace std;

bool f_Tab(vector<int>& nums, int k)
{
    int n = nums.size();

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n - 1][k];
}

bool subsetSumToK(vector<int>& nums)
{
    int n = nums.size();

    int sum = 0;

    for (auto it : nums) sum += it;

    return f_Tab(nums, sum);
}

int main()
{
    int n; cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // int k; cin >> k;

    cout << subsetSumToK(nums) << endl;

    return 0;
}