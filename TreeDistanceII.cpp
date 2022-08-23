// https://cses.fi/problemset/task/1133
#include <bits/stdc++.h>
using namespace std; 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int

const int mxN = 200005;
int n;
vector<ll> adj[mxN], dp1(mxN), dp2(mxN);

void dfs1(int node, int par) {
    for(int c:adj[node]) {
        if(c!=par) {
            dfs1(c,node);
            dp1[node] += 1+dp1[c];
        }
    }
}

void dfs2(int node, int par) {
    for(int c:adj[node]) {
        if(c!=par) {
            dfs2(c,node);
            dp2[node] += dp2[c]+dp1[c]+1;
        }
    }
}

void dfs3(int node, int par) {
    for(int c:adj[node]) {
        if(c!=par) {
            dp2[c] = dp2[node]+n-2*(dp1[c]+1);
            dfs3(c, node);
        }
    }
}

int main()
{
	fastio;
    cin>>n;

    for(int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // dp1[i] stores the no of nodes in subtree of i including i
    // dp2[i] stores the total dist final ans

    dfs1(1,0);
    dfs2(1,0);
    dfs3(1,0);

    for(int i=1; i<=n; i++) 
        cout<<dp2[i]<<" ";

	return 0;
}