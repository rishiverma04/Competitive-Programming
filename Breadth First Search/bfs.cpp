#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>g[N];
int vis[N],level[N];

void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int curr_node=q.front();
        q.pop();
        cout << curr_node << " ";
     
        for(int child:g[curr_node]){
            if(!vis[child]){
            q.push(child);
            vis[child]=1;
            level[child]=level[curr_node]+1;
            }
        }

    }
    cout << endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    bfs(1);
    for(int i=1;i<=n;i++){
       
    cout << i << ":" << level[i]<<endl;
    
    
    }
    
  
}
