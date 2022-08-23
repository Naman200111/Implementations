# define int long long int
// time O(Nlogn)
bool isPrime(int x) {
    if(x==1)
        return false;
    for(int i=2; i<=sqrt(x); i++) {
        if(x%i == 0)
            return false;
    }
    return true;
}

void updatePrimeFactors(vector<int> &v, int x) 
{
	for(int i=2; i<=sqrt(x); i++) {
		while(x%i == 0) {
			x /= i;
			v[i]++;
		}
	}

	if(isPrime(x)) 
		v[x]++;
}

int power(int x, int n) {
	if(n==0)	return 1;
	int subprob = power(x, n/2);
	if(n&1) {
		// power odd
		return x * subprob * subprob;
	}
	else {
		// power even
		return subprob * subprob;
	}
}

int ncr(int n, int r) 
{
	vector<int> numPrimeFactors(n+1, 0), denomPrimeFactors(n+1, 0);
	for(int i=r+1; i<=n; i++) {
		updatePrimeFactors(numPrimeFactors, i);
	}

	for(int i=2; i<=n-r; i++) {
		updatePrimeFactors(denomPrimeFactors, i);
	}

	int ans = 1;
	for(int i=2; i<=n; i++) {
		numPrimeFactors[i] -= denomPrimeFactors[i];
		if(numPrimeFactors[i] != 0)
			ans = ans * power(i, numPrimeFactors[i]);
	}

    return ans;
}