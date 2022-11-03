#include <bits/stdc++.h>
using namespace std;

bool f_Tab(vector<int>& nums, int k)
{
    int n = nums.size();

    bool dp[n][k+1] = {0};

    //1st base case
    for(int i = 0; i < n; i++) dp[i][0] = true;

    //2nd base case
    if(nums[0] <= k) dp[0][nums[0]] = true;

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            bool notPick = dp[i - 1][j];

            bool pick = false;
            if(j >= nums[i]) pick = dp[i-1][j - nums[i]];

            dp[i][j] = pick | notPick;
        }
    }

    return dp[n-1][k];
}


bool canPartition(vector<int>& nums)
{
    int sum = 0;
    for(auto it: nums) sum += it;

    if(sum % 2 != 0) return false;

    else return f_Tab(nums, sum/2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n; cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }



    return 0;
}