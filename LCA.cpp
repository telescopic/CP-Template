/*input
6
1 2
2 3
1 4
4 6
4 5
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e5+1; 
const ll depth=32; // adjust this as per the maximum height of the tree !! 


vector <ll> adj[maxn];
ll st[maxn][depth+1];
ll pw2[depth+1];
ll lvl[maxn];
bool vis[maxn];

ll n,e;
ll x,y;

// initial dfs for 
void dfs(ll node,ll parent,ll level){
	lvl[node]=level;
	st[node][0]=parent;
	for(auto it:adj[node]){
		if(it!=parent) dfs(it,node,level+1);
	}
}

// jumps to an ancestor at a distance of "node" at a distance of "dist" 
ll jump(ll node,ll dist){
	if(dist==0) return node;
	ll u=node;
	ll cntr=0;
	while(dist){
		if(dist%2==1){ u=st[u][cntr]; }
		dist/=2;
		cntr++;
	}
	return u;
}

ll find_lca(ll u,ll v){
	if(lvl[u]>lvl[v]){
		u=jump(u,lvl[u]-lvl[v]);
	}
	else {
		v=jump(v,lvl[v]-lvl[u]);
	}
	if(u==v) {
		return v; // one node is the ancestor of the other 	
	}
	else{
		for(int k=depth-1;k>=0;k--){
			if(st[u][k]!=st[v][k]){u=st[u][k]; v=st[v][k];}
		}
		return st[u][0];
	}
}

int main(){
	
	// accepting graph input
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// precalculation for sparse table st[i][j] is 2^jth ancestor of ith node 
	dfs(1,1,0);
	for(int j=1;j<depth;j++) {
	for(int i=1;i<=n;i++){
		st[i][j]=st[st[i][j-1]][j-1];
	}}
	return 0;
}