#include <fstream>
#include <vector>
using namespace std;

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    int size;
    fin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
    
    // vector<int> arr(size, 0);
    for(int i = 0; i < size; ++i) {
        int v1, v2;
        fin >> v1 >> v2;
        arr[v2 - 1] = v1;
    }

    for(int i = 0; i < size; ++i) {
        fout << arr[i] << " ";
    }
    return 0;
    // for(int i : arr) {
    //     fout << i << " ";
    // }
}