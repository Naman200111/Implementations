# define mod 1000000007
// if can go big then mod version else non mod version
// mod version
vector<vector<int>> matrixMultiplication(vector<vector<int>> A, vector<vector<int>> B)
{
	int n = A.size(), m = B[0].size();
	vector<vector<int>> ans(n, vector<int>(m));

	for(int row=0; row<n; row++) {
		for(int col=0; col<m; col++) {
			int ele = 0;
			for(int i=0; i<A[0].size(); i++) 
				ele += (A[row][i]%mod * B[i][col]%mod)%mod;
			ans[row][col] = ele;
		}
	}
	return ans;
}


// non mod version
vector<vector<int>> matrixMultiplication(vector<vector<int>> A, vector<vector<int>> B)
{
	int n = A.size(), m = B[0].size();
	vector<vector<int>> ans(n, vector<int>(m));

	for(int row=0; row<n; row++) {
		for(int col=0; col<m; col++) {
			int ele = 0;
			for(int i=0; i<A[0].size(); i++) 
				ele += A[row][i] * B[i][col];
			ans[row][col] = ele;
		}
	}
	return ans;
}