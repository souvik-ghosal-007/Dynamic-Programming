#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &heights)
{
    if(n == 0) return 1;

    if(n < 0) return 0;

    int one = abs(heights[n] - heights[n - 1]) + f(n-1, heights);
    int two = abs(heights[n] - heights[n-2]) + f(n-2, heights);

    return one + two;
}

int jump(int n, vector<int> &heights)
{
    return f(n, heights);
}

int main()
{
    int n; cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cout << jump(n, heights);
    return 0;
}
