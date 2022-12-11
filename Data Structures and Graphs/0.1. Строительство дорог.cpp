#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

class DSU {
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        count = n;
        for (int i = 1; i < n + 1; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int FindSet(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = FindSet(parent[x]);
    }

    void Union(int x, int y) {
        x = FindSet(x);
        y = FindSet(y);
        if (x != y) {
            count--;
            if (rank[x] < rank[y]) {
                swap(x, y);
            }
            parent[y] = x;
            if (rank[x] == rank[y]) {
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

    int n, q;
    fin >> n >> q;
    DSU dsu(n);    
    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> a >> b;
        dsu.Union(a, b);
        fout << dsu.count << endl;
    }

    return 0;
}