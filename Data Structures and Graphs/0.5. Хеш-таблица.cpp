#include <fstream>
#include <vector>
using namespace std;

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");

    int m, c, n;
    fin >> m >> c >> n;

    vector<int> hash(m, -1);
    for(int i = 0; i < n; ++i) {
        int key;
        fin >> key;
        int hash_try = 0;
        while(true) {
            int tmp = (key % m + c * hash_try) % m;
            if(hash[tmp] == -1 || hash[tmp] == key) {
                hash[tmp] = key;
                break;
            }
            else {
                ++hash_try;
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        fout << hash[i] << " ";
    }

    return 0;
}