#include <fstream>
using namespace std;

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");
    
    // ------------------ INPUT ------------------
    int size;
    fin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        fin >> array[i];
    }

    // ------------------ TASK ------------------
    bool is_heap = true;
    for(int i = 0; i < size; ++i) {
        if(((2 * i + 1 < size) && (array[i] > array[2 * i + 1])) || (2 * i + 2 < size) && (array[i] > array[2 * i + 2])) {
            is_heap = false;
            break;
        }
    }
    fout << ((is_heap == true) ? "Yes" : "No");
    return 0;
}