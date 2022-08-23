#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define mod 1000000007
#define pp pair<int, int>
#define ps(x, y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
 
long enter[200005];
long exitt[200005];
long lt[200005];
long timee = 1;
vector<long> adj[200005];
long BIT[200005];
 
 
void precompute(long node, long par) {
	enter[node] = timee;
	lt[timee] = node;
	timee++;
 
	for(long nbr:adj[node]) {
		if(nbr != par) 
			precompute(nbr, node);
	}
 
	exitt[node] = timee-1;
	lt[timee] = node;
}
 
void updateBIT(long i, long inc, long len) {
	while(i <= len) {
		BIT[i] += inc;
		i += (i&(-i));
	}
}
 
long sumBIT(long val) {
	long sum = 0;
	while(val > 0) {
		sum += BIT[val];
		val -= (val&(-val));
	}
	return sum;
}
 
int main()
{
	fastio;
	int n,q;
	cin>>n>>q;
 
	vector<long> arr(n+1);
	for(long i=1; i<=n; i++)
		cin>>arr[i]; 
 
	for(long i=1; i<=n-1; i++) {
		long a,b;
		cin>>a>>b;
 
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	precompute(1,0);
    for(long i=1; i<=n; i++)
		cout<<lt[i]<<" ";
	cout<<"\n";
	// buildBIT
	for(long i=1; i<=n; i++)
		updateBIT(i, arr[lt[i]], n);
    for(long i=1; i<=n; i++)
		cout<<BIT[i]<<" ";
	cout<<"\n";
	
	for(long i=0; i<q; i++) {
		long type;
		cin>>type;
 
		if(type == 2) {
			// find sum of all elements from in subtree of node
			long node;
			cin>>node;
    
			long sum1 = sumBIT(exitt[node]); 
			long sum2 = sumBIT(enter[node]-1); 
			long sum = sum1-sum2;
			cout<<sum<<"\n";
		}
		else {
			// increment the value at ith index by val
			long node, new_val;
			cin>>node>>new_val;
 
			long inc = new_val-arr[node];
			arr[node] = new_val;
			updateBIT(enter[node], inc, n);
		}
	}
 
	return 0;
}




// 2*n wala code
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define mod 1000000007
#define pp pair<int, int>
#define ps(x, y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
 
long enter[200005];
long exitt[200005];
long lt[400005];
long timee = 1;
vector<long> adj[200005];
long BIT[400005];
 
 
void precompute(long node, long par) {
	enter[node] = timee;
	lt[timee] = node;
	timee++;
 
	for(long nbr:adj[node]) {
		if(nbr != par) 
			precompute(nbr, node);
	}
 
	exitt[node] = timee;
	lt[timee] = node;
	timee++;
}
 
void updateBIT(long i, long inc, long len) {
	while(i <= len) {
		BIT[i] += inc;
		i += (i&(-i));
	}
}
 
long sumBIT(long val) {
	long sum = 0;
	while(val > 0) {
		sum += BIT[val];
		val -= (val&(-val));
	}
	return sum;
}
 
int main()
{
	fastio;
	int n,q;
	cin>>n>>q;
 
	vector<long> arr(n+1);
	for(long i=1; i<=n; i++)
		cin>>arr[i]; 
 
	for(long i=1; i<=n-1; i++) {
		long a,b;
		cin>>a>>b;
 
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	precompute(1,0);
	
	// buildBIT
	for(long i=1; i<=2*n; i++) {
		updateBIT(i, arr[lt[i]], 2*n);
	}
 
	// for(long i=1; i<=2*n; i++)
	// 	cout<<BIT[i]<<" ";
	// cout<<"\n";
 
	for(long i=0; i<q; i++) {
		long type;
		cin>>type;
 
		if(type == 2) {
			// find sum of all elements from in subtree of node
			long node;
			cin>>node;
			
			// long sum = 
			long sum1 =sumBIT(exitt[node]); 
			long sum2 =sumBIT(enter[node]-1); 
			// sum -= sumBIT(enter[node]-1);
			// cout<<sum1<<" "<<sum2<<"\n";
			long sum = sum1-sum2;
			cout<<sum/2<<"\n";
		}
		else {
			// increment the value at ith index by val
			long node, new_val;
			cin>>node>>new_val;
 
			long inc = new_val-arr[node];
			arr[node] = new_val;
			updateBIT(exitt[node], inc, 2*n);
			updateBIT(enter[node], inc, 2*n);
			// for(long i=1; i<=2*n; i++)
			// 	cout<<BIT[i]<<" ";
			// cout<<"\n";
		}
	}
 
	return 0;
}