#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define pp pair<int, int>
#define ppl pair<long long int, long long int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n,m;
vector<int> disc,low,st;
stack<int> instack;
int timer = 0;

void dfs(int u, vector<int> adj[]) {
    disc[u] = low[u] = timer;
    timer++;
    st[u] = 1;
    instack.push(u);

    for(int v:adj[u]) {
        if(disc[v] == -1) {
            // if the adjacent node is never visited
            dfs(v, adj);
            low[u] = min(low[u], low[v]);
        }
        // if visited then the edge must be a cross edge or back edge
        // if the node v is present in the stack then it will surely be back edge else cross edge
        // we do not consider cross edge
        // if v in stack then it means node and v are in same scc
        else if(st[v]){
            // back edge
            low[u] = min(low[u], disc[v]);
        }
    }

    // focus on printing the scc
    if(low[u] == disc[u]) {
        // then u is the head node of scc, start printing
        while(instack.top() != u) {
            cout<<instack.top()<<" ";
            st[instack.top()] = 0;
            instack.pop(); 
        }
        cout<<u<<"\n";
        st[u] = 0;
        instack.pop();
    }
}


void tarjan(vector<int> adj[]) {
    disc = vector<int> (n,-1);
    low = vector<int> (n,-1);
    st = vector<int> (n);

    for(int i=0; i<n; i++) {
        if(disc[i] == -1) {
            dfs(i, adj);
        }
    }

}
int main() {
    fastio;
    cin>>n>>m;
    
    vector<int> adj[n];
    for(int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    
    tarjan(adj);
    
    return 0;
}
