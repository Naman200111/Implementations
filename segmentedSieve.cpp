#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int l,r;
vector<int> prime_less_than_sqrtR;
void sieve(int n) {
	// find primes till length n
	prime_less_than_sqrtR.clear();
	vector<int> primes(n+1,1);
	primes[1] = 0;
	for(int i=2; i<=sqrt(n); i++) {
		if(primes[i]) {
			for(int j=i*i; j<=n; j+=i) 
				primes[j] = 0;
		}
	}
	for(int i=2; i<=n; i++) {
		if(primes[i])
			prime_less_than_sqrtR.push_back(i);
	}

}

void segmentedsieve(int l, int r) { 
	vector<int> primes_in_range(r-l+1,1);
	for(int i=0; i<prime_less_than_sqrtR.size(); i++) {
		int prime = prime_less_than_sqrtR[i];
		int ff = l/prime * prime;
		if(ff<l)
			ff += prime;

		if(ff <= sqrt(r)) // here when we get the prime it is itself a prime but we are marking it to be non prime
		//as the loop starts from ff, rather start marking the non primes from 2*ff in this case
		// check when l=1 and r=100
			ff = 2*ff;
		for(int j=ff ; j<=r; j+=prime) 
			primes_in_range[j-l] = 0;
	}

	for(int i=l; i<=r; i++) {
		if(primes_in_range[i-l] && i!=1)
			cout<<i<<" ";
	}
	cout<<"\n";
}

int main(){
	cin>>l>>r;
	sieve(sqrt(r));
	segmentedsieve(l,r);
	return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// #define int long long int

// vector<int> helper(100001, 1); // mark all values from 1 to 100000 as prime
// vector<int> primes;

// void sieve()
// {
//     helper[1] = 0;
//     for (int i = 2; i <= 100000; i++)
//     {
//         if (helper[i])
//         {
//             primes.push_back(i);
//             for (int j = i * i; j <= 100000; j += i)
//             {
//                 helper[j] = 0;
//             }
//         }
//     }
// }

// void segmentedSieve(int m, int n)
// {
//     vector<int> primeInRange(n - m + 1, 1);
//     for (int i = 0; i < primes.size(); i++)
//     {
//         int prime = primes[i];
//         if (prime * prime > n)
//             break;

//         int firstFactor = (m / prime) * prime;
//         if (prime >= m && prime <= n)
//             firstFactor = 2 * prime;

//         for (int j = firstFactor; j <= n; j += prime)
//         {
//             if (j - m >= 0)
//                 primeInRange[j - m] = 0;
//         }
//     }

//     for (int i = 0; i <= n - m; i++)
//     {
//         if (primeInRange[i] && i + m != 1)
//             cout << i + m << endl;
//     }
// }

// int32_t main()
// {
//     sieve();

//     int m, n;
//     cin >> m >> n;

//     // print all primes from m to n
//     segmentedSieve(m, n);

//     return 0;
// }