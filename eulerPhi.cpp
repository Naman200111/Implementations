// number of values < n which are coprime with n in logn
void primeFactorize(int n, int &ans)
{
	for (int i = 2; i * i <= n; i++)
	{
		int ct = 0;
		while(n%i == 0) {
			ct++;
			n/=i;
		}

		if(ct) {
			ans = (ans/i)*(i-1);
		}
	}

	if(n!=1) {
		ans = (ans/n)*(n-1);
	}
}

int eulerPhi(int n) 
{
	int ans = n;
	primeFactorize(n, ans);
	return ans;
}