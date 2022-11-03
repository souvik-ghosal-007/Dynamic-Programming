#include <bits/stdc++.h>
using namespace std;

int f_SOP(vector<int> &nums)
{
    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;

    int curi = 0;

    for(int i = 1; i < n; i++)
    {
        int notPick = prev;

        int pick = nums[i];
        if(i > 1) pick += prev2;

        curi = max(notPick, pick);

        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int f_Tab(vector<int> &nums)
{
    int n = nums.size();

    int dp[n];

    dp[0] = nums[0];

    for(int i = 1; i < n; i++)
    {
        int notPick = dp[i - 1];

        int pick = nums[i];
        if(i > 1) pick += dp[i - 2];

        dp[i] = max(notPick, pick);
    }

    return dp[n-1];
}

int f(int ind, vector<int> &nums)
{
    if(ind == 0) return nums[0];

    if(ind < 0) return 0;

    int notPick = f(ind - 1, nums);

    int pick = nums[ind] + f(ind - 2, nums);

    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    return f_Tab(nums);
}

int main()
{
    int n; cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << maximumNonAdjacentSum(nums) << endl;

    return 0;
}
