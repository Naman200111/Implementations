#include <bits/stdc++.h>
using namespace std; 

#define ll long long int 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// distance queries
vector<ll> depth;
vector<vector<ll>> up;
ll LOG;


ll lca(ll a, ll b) {
    if(depth[a] < depth[b])
        swap(a,b);

    ll gap = depth[a]-depth[b];
    for(ll j=LOG; j>=0; j--) {
        if( gap & (1<<j) ) {
            a = up[a][j];
        }
    }

    if(a==b)
        return a;

    for(ll j=LOG; j>=0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];

}

void dfs(ll node, vector<ll> adj[], ll par) {
    for(ll c:adj[node]) {
        if(c!=par) {
            depth[c] = depth[node]+1;
            up[c][0] = node;
            for(ll j=1; j<LOG; j++) {
                up[c][j] = up[up[c][j-1]][j-1];
            }
            dfs(c,adj,node);
        }
    }
}

int main()
{
	fastio;

    ll n,q;
    cin>>n>>q;

    LOG = 0;
    while( (1<<LOG) <= n)
        LOG++;

    depth = vector<ll> (n+1);
    up = vector<vector<ll>> (n+1, vector<ll> (LOG));

    vector<ll> adj[n+1];
    for(ll i=0; i<n-1; i++) {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, adj, 0);


    while(q--) {
        ll a,b;
        cin>>a>>b;

        ll LCA = lca(a,b);
        ll dist1 = depth[a]-depth[LCA];
        ll dist2 = depth[b]-depth[LCA];
        cout<<(long long int)dist1+dist2<<"\n";
    }
    
	return 0;
}