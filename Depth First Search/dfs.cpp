#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
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
}
