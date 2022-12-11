#include <fstream>
#include <limits.h>
using namespace std;

int solution(int size, int *arr) {
    int ** matrix = new int*[size];
    for(int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }
    for(int i = 1; i < size; ++i) {
        for(int j = 1; j < size; ++j) {
            matrix[i][j] = 0;
        }
    }

    for(int l = 2; l < size; ++l) {
        for(int i = 1; i < size - l + 1; ++i) {
            int j = i + l - 1;
            matrix[i][j] = INT_MAX;
            for(int k = i; k < j; ++k) {
                int cost = matrix[i][k] + matrix[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if(cost < matrix[i][j]) {
                    matrix[i][j] = cost;
                }
            }
        }
    }
    return matrix[1][size - 1];
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int size;
    fin >> size;
    int *arr = new int[size + 1];    
    for(int i = 0, j = 0; i < size; ++i) {
        fin >> arr[j];
        if(i == size - 1) {
            fin >> arr[j + 1];
        }
        else {
            int t;
            fin >> t;
            ++j;
        }
    }
    fout << solution(size + 1, arr);
}