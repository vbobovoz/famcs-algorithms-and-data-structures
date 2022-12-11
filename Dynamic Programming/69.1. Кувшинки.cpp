#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int count;
    fin >> count;
    int *mosquitoes = new int[count];
    for(int i = 0; i < count; ++i) {
        fin >> mosquitoes[i];
    }
    int *max_arr = new int[count];
    max_arr[0] = mosquitoes[0];
    max_arr[1] = -1;
    max_arr[2] = mosquitoes[0] + mosquitoes[2];
    for(int i = 3; i < count; ++i) {
        max_arr[i] = max(max_arr[i - 2], max_arr[i - 3]) + mosquitoes[i];
    }
    if(max_arr[count - 1] >= 0) {
        fout << max_arr[count - 1];
    }
    else{
        fout << -1;
    }
    return 0;
}