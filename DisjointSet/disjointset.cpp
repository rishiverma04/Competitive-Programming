#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
   vector<int>rank,parent,size;
   public:
   DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
parent[i]=i;
size[i]=1;
    }
   }
   int findUPar(int node){
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]); 
   }
   void unionbyRank(int u,int v){
    int ultimate_pu=findUPar(u);
    int ultimate_pv=findUPar(v);
    if(ultimate_pu==ultimate_pv) // same component
    return ; 
    if(rank[ultimate_pu]<rank[ultimate_pv]){ // if not same component and u<v
    parent[ultimate_pu]=ultimate_pv; // attach smaller to largest u->v
    }
    else if(rank[ultimate_pv]<rank[ultimate_pu]){
        parent[ultimate_pv]=ultimate_pu;
    }
    else{
        parent[ultimate_pv]=ultimate_pu; // if same
        rank[ultimate_pu]++; // rank will increase


    }
   }
   void unionbySize(int u,int v){
    int ultimate_pu=findUPar(u);
    int ultimate_pv=findUPar(v);
    if(ultimate_pu==ultimate_pv) // same component
    return ; 
     if(size[ultimate_pu]<size[ultimate_pv]){ //u<v
        parent[ultimate_pu]=ultimate_pv; 
        size[ultimate_pv]+=size[ultimate_pu]; //attach to v
     }
     else{
parent[ultimate_pv]=ultimate_pu;  //u>v
        size[ultimate_pu]+=size[ultimate_pv];
     }
   }
};
int main()
{
    DisjointSet ds(7);
    ds.unionbySize(1,2);
     ds.unionbySize(2,3);
      ds.unionbySize(4,5);
       ds.unionbySize(6,7);
       ds.unionbySize(5,6);
       // we check if 3 &7 belong to same component or not
       if(ds.findUPar(3)==ds.findUPar(7)){
        cout << "Same"<<endl;
       }
       else{
        cout << "Not Same"<<endl; // here it is not same
       }
        ds.unionbySize(3,7);
        if(ds.findUPar(3)==ds.findUPar(7)){
        cout << "Same"<<endl;
       }
       else{
        cout << "Not Same"<<endl; // here it is  same
       }
       return 0;
}