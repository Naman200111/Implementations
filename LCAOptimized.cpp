// binary lifting
// lca in (log n)
#include <bits/stdc++.h>
using namespace std; 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


vector<int> depth;
vector<vector<int>> up;
int LOG;


int lca(int a, int b) {
    // returns lca of node a and node b
    // assume a to have more depth
    if(depth[a] < depth[b])
        swap(a,b);

    // bring the nodes on the same height
    int gap = depth[a]-depth[b];
    for(int j=LOG; j>=0; j--) {
        if( gap & (1<<j) ) {
            a = up[a][j];
        }
    }

    // base case if(b is the lca only)
    if(a==b)
        return a;

    // same depth
    // move the nodes a and b such that ancestor not equal
    // because if with the jump k, I get the same ancestor then this node might be lca or might not be
    // the lca might be some node below with lesser jump
    // so lets make smaller jump
    for(int j=LOG; j>=0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    // now the answer is parent of a or b node
    return up[a][0];

}


void dfs(int node, vector<int> adj[]) {
    for(int c:adj[node]) {
        depth[c] = depth[node]+1;
        up[c][0] = node;
        for(int j=1; j<LOG; j++) {
            up[c][j] = up[up[c][j-1]][j-1];
        }
        dfs(c,adj);
    }
}

int main()
{
	fastio;
    int n;
    cin>>n;

    // finding the maximum power of 2 jump we can make from the leaf node in LOG
    LOG = 0;
    while( (1<<LOG) <= n)
        LOG++;

    depth = vector<int> (n+1);
    up = vector<vector<int>> (n+1, vector<int> (LOG));

    vector<int> adj[n+1];
    for(int i=0; i<n; i++) {
        int childs;
        cin>>childs;
        for(int j=0; j<childs; j++) {
            int child;
            cin>>child;
            adj[i].push_back(child);
        }
    }

    dfs(0, adj);

    int q;
    cin>>q;

    while(q--) {
        int u, v;
        cin>>u>>v;

        cout << lca(u,v) << "\n";
    }


	return 0;
}