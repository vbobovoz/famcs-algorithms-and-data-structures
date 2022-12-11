#include <fstream>
#include <string>
using namespace std;

int min(int value1, int value2, int value3) {
    int min = value1;
    if (value2 < min) { min = value2; }
    if (value3 < min) { min = value3; }
    return min;
}

int main() {
    fstream fin("in.txt");
    ofstream fout("out.txt");
    int del_cost, ins_cost, rep_cost;
    string str1, str2;
    fin >> del_cost;
    fin >> ins_cost;
    fin >> rep_cost;
    fin >> str1;
    fin >> str2;
    int rows = str1.length() + 1;
    int cols = str2.length() + 1;

    // ------------------ FIRST INIT ------------------
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    for(int i = 0; i < rows; ++i) {
        matrix[i][0] = i * del_cost;
    }
    for(int j = 0; j < cols; ++j) {
        matrix[0][j] = j * ins_cost;
    }

    // ------------------ FILLING ------------------
    for(int i = 1; i < rows; ++i) {
        for(int j = 1; j < cols; ++j) {
            int delta;
            if (str1[i - 1] == str2[j - 1]) { delta = 0; }
            else { delta = 1; }
            matrix[i][j] = min(matrix[i - 1][j] + del_cost, matrix[i][j - 1] + ins_cost, matrix[i - 1][j - 1] + delta * rep_cost);
        }
    }

    fout << matrix[rows - 1][cols - 1];

    return 0;
}