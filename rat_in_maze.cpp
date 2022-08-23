#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x // precision of is x and places is y

int path[1005][1005] = {0};

bool solve(vector<vector<char>> &grid, int i, int j, int n, int m)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return false;

	path[i][j] = 1;

	if (i == n - 1 && j == m - 1)
		return true;

	if (grid[i][j + 1] == 'O' && solve(grid, i, j + 1, n, m))
		return true;

	if (grid[i + 1][j] == 'O' && solve(grid, i + 1, j, n, m))
		return true;

	path[i][j] = 0;
	return false;
}

int32_t main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> grid(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			grid[i][j] = s[j];
		}
	}

	if (grid[0][0] == 'X' || grid[n - 1][m - 1] == 'X')
	{
		cout << -1 << endl;
		return 0;
	}

	if (solve(grid, 0, 0, n, m))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << path[i][j] << " ";
			}
			cout << "\n";
		}
		return 0;
	}

	cout << -1 << endl;

	return 0;
}