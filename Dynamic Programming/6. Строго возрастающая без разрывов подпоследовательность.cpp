#include <fstream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int size;
    fin >> size;
    vector<int> input;
    for(int i = 0; i < size; ++i) {
        int t;
        fin >> t;
        input.push_back(t);
    }

    vector<int> output(size + 2);
    output[0] = INT_MIN;
    for(int i = 1; i < size + 2; ++i) {
        output[i] = INT_MAX;
    }

    for(int i = 0; i < size; ++i) {
        int ind = distance(output.begin(), upper_bound(output.begin(), output.end(), input[i]));
        if(output[ind] > input[i] && output[ind - 1] < input[i]) {
            output[ind] = input[i];
        }
    }
    int count = 0;
    for(int i = 0; i < output.size(); ++i) {
        if(output[i] != INT_MAX && output[i] != INT_MIN) {
            count++;
        }
    }
    fout << count;
    return 0;
}