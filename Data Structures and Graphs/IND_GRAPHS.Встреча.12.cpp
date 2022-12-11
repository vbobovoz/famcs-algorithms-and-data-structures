#include <fstream>
#include <vector>
#include <limits.h>
#include <algorithm>
const int INF = 1000000000;
using namespace std;

int main() {
    fstream fin("input.in"); ofstream fout("output.out");
    ios_base::sync_with_stdio(false); fin.tie(NULL); fout.tie(NULL);

    int n, m; fin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n, INF));
    for(int i = 0; i < m; ++i) {
        int start, end, cost; fin >> start >> end >> cost;
        matrix[start - 1][end - 1] = cost;
        matrix[end - 1][start - 1] = cost;
    }

    for(int i = 0; i < n; ++i) {
        matrix[i][i] = 0;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
            }
        }
    }

    vector<long long> length(n, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            length[i] += matrix[i][j];
        }
    }

    int house = 0;
    auto it = min_element(length.begin(), length.end());
    fout << it - length.begin() + 1 << " " << *it;

    return 0;
}