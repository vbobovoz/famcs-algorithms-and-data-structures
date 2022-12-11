#include <fstream>
#include <queue>
using namespace std;

int main() {
    fstream fin("huffman.in");
    ofstream fout("huffman.out");

    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    long long n;
    fin >> n;

    long long total = 0;
    priority_queue<long long, vector<long long>, greater<long long>> q;

    for (int i = 0; i < n; i++) {
        long long tmp;
        fin >> tmp;
        q.push(tmp);
    }

    for(int i = 0; i < n - 1; ++i) {
        long long it_sum = q.top();
        q.pop();

        it_sum += q.top();
        q.pop();

        q.push(it_sum);
        total += it_sum;
    }
    fout << total;

    return 0;
}