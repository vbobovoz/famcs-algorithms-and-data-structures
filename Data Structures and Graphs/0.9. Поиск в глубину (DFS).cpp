#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int t = 1;
void dfs(int v, vector<vector<int>> &matrix, vector<bool> &visited, vector<int> &order) {
    visited[v] = true;
    order[v] = t++;
    for (int i = 0; i < matrix[v].size(); ++i) {
        if (!visited[i] && matrix[v][i] == 1) {
            dfs(i, matrix, visited, order);
        }
    }
}

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    // ------------------------------ INPUT ------------------------------
    int size;
    fin >> size;

    vector<vector<int>> matrix(size);
    vector<bool> visited(size, false);
    vector<int> order(size, 0);
    
    for(int i = 0; i < size; ++i) {
        matrix[i].resize(size);
        for(int j = 0; j < size; ++j) {
            fin >> matrix[i][j];
        }
    }

    // ------------------------------ OUTPUT ------------------------------    
    for(int i = 0; i < size; ++i) {
        if(!visited[i]) { dfs(i, matrix, visited, order); }
    }

    for(int i : order) {
        fout << i << " ";
    }

    return 0;
}