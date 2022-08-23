// https://cses.fi/problemset/task/1132
#include <bits/stdc++.h>
using namespace std; 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
const int mxN = 200005;
vector<int> adj[mxN], dp1(mxN), dp2(mxN);
 
void dfs1(int node, int par) {
    for(int c:adj[node]) {
        if(c!=par) {
            dfs1(c,node);
            dp1[node] = max(dp1[node], 1+dp1[c]);
        }
    }
}
 
void dfs2(int node, int par) {
    int mx1=-1,mx2=-1;
    for(int c:adj[node]) {
        if(c!=par) {
            if(dp1[c] > mx1) {
                mx2 = mx1;
                mx1 = dp1[c];
            }
            else {
                mx2 = max(mx2,dp1[c]);
            }
        }
    }
 
    // mx1 stores maximum dist in subtree 
    // mx2 stores second maximum dist in subtree
    for(int c:adj[node]) {
        if(c!=par) {
            if(dp1[c] == mx1) 
                dp2[c] = max(1+dp2[node], 2+mx2);
            else 
                dp2[c] = max(1+dp2[node], 2+mx1);
            dfs2(c, node);
        }
    }
 
}
 
int main()
{
	fastio;
    int n;
    cin>>n;
 
    for(int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    // dp1[i] stores the answer of maximum distance of ith node in subtree of i
    // dp2[i] stores the answer of maximum distance of ith node in the ancestor part of node i
 
    dfs1(1,0);
    // cout<<"in\n";
    // for(int i=1; i<=n; i++)
    //     cout<<i<<" "<<dp1[i]<<"\n";
    // cout<<"out\n";
    dfs2(1,0);
    // for(int i=1; i<=n; i++)
    //     cout<<i<<" "<<dp2[i]<<"\n";
 
    for(int i=1; i<=n; i++) 
        cout<<max(dp1[i], dp2[i])<<" ";
 
	return 0;
}