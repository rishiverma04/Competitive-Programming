#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>g[N];
int par[N];
void dfs(int v,int p=-1){
    par[v]=p;
    for(int child:g[v]){
        if(child==p) continue;
        dfs(child,v);
    }
}
vector<int>path(int v){
    vector<int>ans;
    while(v!=-1){
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int x,y;
    cin>>x>>y;
    vector<int>path_x=path(x);
    vector<int>path_y=path(y);
    int mn=min(path_x.size(),path_y.size());
    int lca=-1;
    for(int i=0;i<mn;i++){
        if(path_x[i]==path_y[i]){
            lca=path_x[i];
        }
        else{
            break;
        }
    }
    cout << lca << endl;
    return 0;
}
