#include <fstream>
#include <vector>
using namespace std;

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    // ------------------- INIT -------------------
    int n, m;
    fin >> n >> m;
    vector<vector<int>> matrix(n);
    for(int i = 0; i < m; ++i) {
        int v1, v2;
        fin >> v1 >> v2;
        matrix[v1 - 1].push_back(v2);
        matrix[v2 - 1].push_back(v1);
    }

    // ------------------- OUTPUT -------------------
    for(int i = 0; i < n; ++i) {
        int size = matrix[i].size();
        fout << size << " ";
        for(int j = 0; j < size; ++j) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }

    return 0;
}