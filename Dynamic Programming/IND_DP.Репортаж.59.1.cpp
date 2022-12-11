#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    fstream fin("report.in"); ofstream fout("report.out");
    ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);
    int size;
    fin >> size;
    vector<int> days(size);
    for (int i = 0; i < size; i++) {
        fin >> days[i];
    }

    vector<int> LIS1(size, 1);
    for(int i = 1; i < size; ++i) {
        for(int j = 0; j < i; ++j) {
            if(days[j] < days[i] && LIS1[j] + 1 > LIS1[i]) {
                LIS1[i] = LIS1[j] + 1;
            }
        }
    }

    reverse(days.begin(), days.end());
    vector<int> LIS2(size, 1);
    for(int i = 1; i < size; ++i) {
        for(int j = 0; j < i; ++j) {
            if(days[j] < days[i] && LIS2[j] + 1 > LIS2[i]) {
                LIS2[i] = LIS2[j] + 1;
            }
        }
    }
    reverse(days.begin(), days.end());

    int ml = 0;
    int mid = 1;
    for (int i = 0; i < size; i++) {
        if(ml < min(LIS1[i], LIS2[size - i - 1])) {
            ml = min(LIS1[i], LIS2[size - i - 1]);
            mid = i;
        }
    }

    int real_mid = mid;

    vector<int> res1;
    for(int i = mid; i >= 0; --i) {
        if(LIS1[i] + 1 == LIS1[mid] && days[i] < days[mid]) {
            res1.push_back(i + 1);
            mid = i;
        }
    }

    reverse(days.begin(), days.end());
    vector<int> res2;
    mid = size - real_mid - 1;
    for(int i = mid; i >= 0; --i) {
        if(LIS2[i] + 1 == LIS2[mid] && days[i] < days[mid]) {
            res2.push_back(size - i);
            mid = i;
        }
    }

    int k = min(LIS1[real_mid], LIS2[size - real_mid - 1]) - 1;
    fout << k << "\n";

    for(int i = k - 1; i >= 0; --i) { fout << res1[i] << " "; }
    fout << real_mid + 1 << " ";
    for(int i = 0; i < k; ++i) { fout << res2[i] << " "; }
    
    return 0;
}