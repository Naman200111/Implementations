// log(n)
ll powerFind(ll a, ll b)
{
	ll ans = 1;
	for (ll i = 0; i < b; i++)
		ans *= a;
	return ans;
}

// log(n)
ll power(int x, int n)
{
	if (n == 0)
		return 1;
	ll subprob = power(x, n / 2);
	if (n & 1)
	{
		// power odd
		return x * subprob * subprob;
	}
	else
	{
		// power even
		return subprob * subprob;
	}
}

// log(n) bit manupulation
ll power(int x, int n)
{
	// we traverse in bits of n
	ll ans = 1;
	while (n)
	{
		int last_bit = (n & 1);
		if (last_bit)
			ans = ans * x;
		n = n >> 1;
		x = x * x;
	}
	return ans;
}
