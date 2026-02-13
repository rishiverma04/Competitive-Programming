#include<bits/stdc++.h>
using namespace std;

/*const int N=1e5+10;
vector<int>g[N];
bool vis[N];

void dfs(int vertex){
    cout << vertex<<"\n";
    vis[vertex]=true;
    for(int child:g[vertex]){
        cout<<"parent: "<<vertex<< " child:"<<child<<"\n";
        if(vis[child]) continue;

        dfs(child);
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
}*/

const int N=1e5+10;
vector<int>g[N];
int depth[N];

void dfs(int vertex,int par=-1){
    for(int child:g[vertex]){
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int mx_depth=-1;
    int mx_d;
    for(int i=1;i<=n;i++){
        if(mx_depth<depth[i]){
            mx_depth=depth[i];
            mx_d=i;
        }
        depth[i]=0;
    }
    dfs(mx_d);
    mx_depth=-1;
    for(int i=1;i<=n;i++){
        if(mx_depth<depth[i]){
         mx_depth=depth[i];
         mx_d=i;
        }
    }
    cout << mx_depth << endl;
}
