#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    cin >> size;
    int* arr1 = new int[size];
    int* arr2 = new int[size];
    
    // INPUT ARRAYS
    for(int i = 0; i < size; ++i) {
        cin >> arr1[i];
    }
    for(int i = 0; i < size; ++i) {
        cin >> arr2[i];
    }

    // CREATE MATRIX
    int** matrix = new int*[size + 1];
    for(int i = 0; i < size + 1; ++i) {
        matrix[i] = new int[size + 1];
    }

    // FILL FIRST ROW AND FIRST COL
    for(int i = 0; i < size + 1; ++i) {
        matrix[i][0] = 0;
        matrix[0][i] = 0;
    }

    // FILL MATRIX
    for(int i = 1; i < size + 1; ++i) {
        for(int j = 1; j < size + 1; ++j) {
            if(arr1[i - 1] == arr2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    // UNCODE MATRIX
    int vsize = matrix[size][size];
    vector<int> v1;
    vector<int> v2;
    int i = size, j = size;
    while(matrix[i][j] != 0) {
        if(arr1[i - 1] == arr2[j - 1]) {
            v1.push_back(i - 1);
            v2.push_back(j - 1);
            --i; --j;
        } else {
            if(matrix[i][j] == matrix[i - 1][j]) {
                --i;
            }
            else {
                --j;
            }
        }
    }

    // PRINT
    cout << matrix[size][size] << endl;
    for(auto it = v1.rbegin(); it != v1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = v2.rbegin(); it != v2.rend(); ++it) {
        cout << *it << " ";
    }
    return 0;
}