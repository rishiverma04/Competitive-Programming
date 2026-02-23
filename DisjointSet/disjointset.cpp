#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) 
            return x;// if node points to itself return the root
        return parent[x] = find(parent[x]); // Path Compression
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (sz[a] < sz[b])  // connect smaller tree with bigger tree
                swap(a, b);

            parent[b] = a;  // make parent a of b
            sz[a] += sz[b]; // update the size of a
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b); // check whether node belong to same root
    }

    int size(int x) {
        return sz[find(x)]; // returns size of component
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    while (m--) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " -> Parent: " << dsu.find(i) << "\n";
    }
} same se samjhao
