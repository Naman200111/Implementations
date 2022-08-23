#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x // precision of is x and places is y

bool canPlace(int i, int j, vector<vector<char>> &grid, int n)
{
	// cout<<i<<" "<<j<<endl;
	for(int p=0; p<j; p++)
	{
		if(grid[i][p] == 'Q')
			return false;
	}

	int x=i-1, y=j-1;
	while(x>=0 && y>=0 && x<n && y<n) 
	{
		if(grid[x][y] == 'Q')
			return false;
		x--;
		y--;
	}

	x = i+1;
	y = j-1;

	while(x>=0 && y>=0 && x<n && y<n) 
	{
		if(grid[x][y] == 'Q')
			return false;
		x++;
		y--;
	}


	return true;
}

void nQueen(int n, int &config, int col, vector<vector<char>> &grid)
{
	// cout<<col<<endl;

	if(col == n)
	{
		// for(int i=0; i<n; i++)
		// {
		// 	for(int j=0; j<n; j++)
		// 	{
		// 		cout<<grid[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		// cout<<"\n";

		config++;
	}

	for(int i=0; i<n; i++)
	{
		if(canPlace(i, col, grid, n)) 
		{
			grid[i][col] = 'Q';
			nQueen(n, config, col+1, grid);
			// cout<<i<<" "<<col<<endl;
			grid[i][col] = '.';
		}
	}



}



int32_t main()
{
	int n;
	cin>>n;

	int config = 0;
	vector<vector<char>> grid(n, vector<char>(n, '.'));

	nQueen(n, config, 0, grid);

	cout<<config<<endl;

}