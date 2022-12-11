#include <fstream>
using namespace std;

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    // ------------------- INIT -------------------
    int n, m;
    fin >> n >> m;
    int** matrix = new int*[n];
    for(int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for(int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }

    // ------------------- SOLUTION -------------------
    for(int i = 0; i < m; ++i) {
        int v1 = -1, v2 = -1;
        fin >> v1 >> v2;
        matrix[v1 - 1][v2 - 1] = 1;
        matrix[v2 - 1][v1 - 1] = 1;
    }

    // ------------------- PRINT ------------------
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }

    return 0;
}