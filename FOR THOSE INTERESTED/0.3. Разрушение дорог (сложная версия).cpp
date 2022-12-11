#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        count = n;
        for(int i = 1; i < n + 1; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int FindSet(int x) {
        if(x == parent[x]) {
            return x;
        }
        return parent[x] = FindSet(parent[x]);
    }

    void Union(int x, int y) {
        x = FindSet(x);
        y = FindSet(y);
        if(x != y) {
            count--;
            if(rank[x] < rank[y]) {
                swap(x, y);
            }
            parent[y] = x;
            if(rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    } 

    int count;
    vector<int> parent;
    vector<int> rank;
};

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    ios_base::sync_with_stdio(false);
    fin.tie(0);
    fout.tie(0);

    int n, m, q;
    fin >> n >> m >> q;
    DSU dsu(n);
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        edges.push_back({ a, b });
    }

    vector<int> queries(q);
    vector<bool> destroyed(m, false);
    for(int i = 0; i < q; ++i) {
        fin >> queries[i];  queries[i]--;
        destroyed[queries[i]] = true;
    }

    long long flag = 0;
    for(int i = 0; i < m; ++i) {
        if(!destroyed[i]) {
            dsu.Union(edges[i].first, edges[i].second);
        }
    }

    reverse(queries.begin(), queries.end());
    for(int i = 0; i < q; ++i) {
        if(dsu.count == 1) { break; }
        flag++;
        dsu.Union(edges[queries[i]].first, edges[queries[i]].second);
    }

    for(int i = 0; i < q - flag; ++i) { fout << 1; }
    for(int i = 0; i < flag; ++i) { fout << 0; }
    return 0;
}