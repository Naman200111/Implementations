#define int long long int
#define mod 1000000007
//time O(N)

int factorialModN(int n) 
{
	int res = 1;
	for(int i=1; i<=n; i++) 
		res = (res*i)%mod;
	return res;
}

int fastModularExponentiation(int x, int n) {
	// we traverse in bits of n
	int ans = 1;
	while(n) {
		int last_bit = (n&1);
		if(last_bit)
			ans = (ans * x)%mod;
		n = n>>1;
		x = (x*x)%mod;
	}
	return ans;
}

int inverseFactorialModN(int r) 
{
	int tmp = factorialModN(r);
	int ans = fastModularExponentiation(tmp, mod-2); // using fermet little theorem
	// a^p = a(modp) => a^(p-2) = a^-1 (modp) ; here a is r!
	return ans;
}

int ncr(int n, int r) 
{
	int a = factorialModN(n);
	int b = inverseFactorialModN(r); // ((r!)^-1)%mod => (1/(r!))%mod
	int c = inverseFactorialModN(n-r); 
	int res = (a%mod * (b%mod * c%mod)%mod) % mod;
	return res;
}