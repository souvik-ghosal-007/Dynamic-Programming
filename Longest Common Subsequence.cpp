#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string a, string b)
{

}

int lcs(string a, string b)
{
	int n = a.size();
	int m = b.size();

	return f(n - 1, m - 1, a, b);
}

int main()
{
	string a, b;

	cin >> a;
	cin >> b;

	cout << lcs(a, b) << endl;

	return 0;
}