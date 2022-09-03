// matrix exponentialization
// this is k^3logn approach k=> number of terms current term depends on
// mod = 1e9+7
#include <bits/stdc++.h>
using namespace std;

# define int  long long int
# define mod  1000000007

vector<vector<int>> matrixMultiplication(vector<vector<int>> A, vector<vector<int>> B)
{
	int n = A.size(), m = B[0].size();
	vector<vector<int>> ans(n, vector<int>(m));

	for(int row=0; row<n; row++) {
		for(int col=0; col<m; col++) {
			int ele = 0;
			for(int i=0; i<A[0].size(); i++) {
				ele += (A[row][i]%mod * B[i][col]%mod)%mod;
				// cout<<ele<<endl;
			}
			ans[row][col] = ele%mod;
		}
	}
	return ans;
}

vector<vector<int>> fastExponential (vector<vector<int>> T, int m) 
{
	// T^m
	if(m == 1)	return T;

	if(m&1) {//odd
		return matrixMultiplication(T, fastExponential(T, m-1));
	}
	else {
		vector<vector<int>> ans = fastExponential(T, m/2);
		return matrixMultiplication(ans, ans);
	}
}

void fastFibonacci (int n) {
    vector<vector<int>> T = {{1, 0}, {1, 1}}; // transformation matrix
    vector<vector<int>> expont = fastExponential(T, n-1);
	 
    vector<vector<int>> ans = matrixMultiplication(expont, {{1}, {1}});
    cout << ans[0][0] % mod<< endl;
}

int32_t main() {
	int n;
	cin>>n;

	// cout<<999999973%mod<<endl;
	fastFibonacci(n);
	return 0;
}