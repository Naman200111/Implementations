#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x // precision of is x and places is y

bool canPlace(int i, int j, vector<vector<int>> &grid, int n)
{
	int row[8] = {-1,-2,-2,-1,1,2,2,1};
	int col[8] = {-2,-1,1,2,2,1,-1,-2};

	for(int k=0; k<8; k++) {
		int x = i+row[k];
		int y = j+col[k];

		if(x>=0 && x<n && y>=0 && y<n && grid[x][y] == 1)
			return false;
	}
	return true;
}

void nKnight(int n, int &config, vector<vector<int>> &grid, int placed)
{
	// cout<<col<<endl;

	if(placed == n)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout<<grid[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";

		config++;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			if(grid[i][j])
				continue;

			if(canPlace(i, j, grid, n)) 
			{
				grid[i][j] = 1;
				nKnight(n, config, grid, placed+1);
				grid[i][j] = 0;
			}
			
		}
	}



}



int32_t main()
{
	int n;
	cin>>n;

	int config = 0;
	vector<vector<int>> grid(n, vector<int>(n, 0));

	nKnight(n, config, grid, 0);

	cout<<config<<endl;

}