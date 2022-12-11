#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    // ------------------------------ INPUT ------------------------------
    int size;
    fin >> size;
    vector<vector<int>> matrix(size);

    for(int i = 0; i < size; ++i) {
        matrix[i].resize(size);
        for(int j = 0; j < size; ++j) {
            fin >> matrix[i][j];
        }
    }

    // ------------------------------ BFS ------------------------------
    vector<int> answ(size);
    vector<bool> visited(size, false);
    queue<int> q;
    int num = 1;
    for(int i = 0; i < size; ++i) {
        if(visited[i]) { continue; }
        visited[i] = true;
        q.push(i);
        answ[i] = num++;
        while(!q.empty()) {
            int v = q.front();  q.pop();
            for(int i = 0; i < size; ++i) {
                if(matrix[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    answ[i] = num++;
                    q.push(i);
                }
            }
        }
    }

    // ------------------------------ OUTPUT ------------------------------    
    for(int i : answ) {
        fout << i << " ";
    }

    return 0;
}