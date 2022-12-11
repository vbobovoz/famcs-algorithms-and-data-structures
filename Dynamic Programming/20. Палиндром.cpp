#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");
    string input;
    fin >> input;
    int size = input.length();

    // MATRIX
    int **matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = 0;
        }
    }

    // FILL MATRIX
    for (int i = 0; i < size; ++i) {
        matrix[i][i] = 1;
    }
    for(int i = 0; i < size - 1; ++i) {
        if (input[i] == input[i + 1]) {
            matrix[i][i + 1] = 2;
        } else {
            matrix[i][i + 1] = 1;
        }
    }
    for(int i = 2; i < size; ++i) {
        for(int j = 0; j < size - i; ++j) {
            if (input[j] == input[j + i]) {
                matrix[j][j + i] = matrix[j + 1][j + i - 1] + 2;
            } else {
                matrix[j][j + i] = max(matrix[j + 1][j + i], matrix[j][j + i - 1]);
            }
        }
    }

    // UNCODE MATRIX
    int i = 0;
    int j = size - 1;
    string result = "";
    while (i <= j) {
        if (input[i] == input[j]) {
            result += input[i];
            i++;
            j--;
        } else if (matrix[i][j] == matrix[i + 1][j]) {
            i++;
        } else {
            j--;
        }
    }
    if(matrix[0][size - 1] % 2 == 0) {
        result = result + string(result.rbegin(), result.rend());
    } else {
        result = result + string(result.rbegin() + 1, result.rend());
    }
    fout << matrix[0][size - 1] << endl;
    fout << result;
    return 0;
}