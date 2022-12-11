#include <fstream>
using namespace std;

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    int size;
    fin >> size;

    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
        for(int j = 0; j < size; ++j) {
            fin >> matrix[i][j];
        }
    }

    for(int j = 0; j < size; ++j) {
        for(int i = 0; i < size; ++i) {
            if(matrix[i][j] == 1) {
                fout << i + 1 << " ";
                break;
            } else if(i == size - 1) {
                fout << 0 << " ";
            }
        }
    }
}