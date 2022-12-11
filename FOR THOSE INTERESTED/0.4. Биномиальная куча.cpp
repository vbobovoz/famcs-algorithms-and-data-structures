#include <fstream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    long long n;
    fin >> n;
    string bin = bitset<64>(n).to_string();
    for(int i = 64; i > 0; --i) {
        if(bin[i] == '1') {
            fout << 63 - i << endl;
        }
    }

    return 0;
}