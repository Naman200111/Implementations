ll power(int x, int n) {
	if(n==0)	return 1;
	ll subprob = power(x, n/2);
	if(n&1) {
		// power odd
		return x * subprob * subprob;
	}
	else {
		// power even
		return subprob * subprob;
	}
}

bool isPrime(int x) {
    if(x==1)
        return false;
    for(int i=2; i<=sqrt(x); i++) {
        if(x%i == 0)
            return false;
    }
    return true;
}

void updatePrimeFactors(vector<ll> &v, int x) 
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

ll NthcatalanNumber(int n) {
	// nth catalan number in nlogn
	vector<ll> numPrimeFactors(2*n+1, 0), denomPrimeFactors(2*n+1, 0);
	for(int i=2; i<=2*n; i++) {
		if(i<=n) {
			// denom
			updatePrimeFactors(denomPrimeFactors, i);
		}
		else {
			// numer
			updatePrimeFactors(numPrimeFactors, i);
		}
	}

	ll ans = 1;
	for(int i=2; i<=2*n; i++) {
		numPrimeFactors[i] -= denomPrimeFactors[i];
		if(numPrimeFactors[i] != 0)
			ans = ans * power(i, numPrimeFactors[i]);
	}

    return (ans / (n+1));
}	



// another approach
int nthCatalanNumber(int n) {
	int dp[n+1];
	dp[0]=1;

	for(int i=1;i<=n;i++){
		dp[i]=0;
		
		for(int j=0;j<i;j++){
			dp[i]+=dp[j]*dp[i-j-1];
			
		}
	}
	return dp[n];
}