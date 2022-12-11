#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

class Sum {
private:
    int k;
    long long bsum = 0;
    string operation;
    string s_num1;
    string s_num2;
    int num1;
    int num2;

public:
    vector<long long> b_arr;
    int a_size;
    long long* a_arr;
    Sum(long long* arr, int size) {
        a_arr = arr;
        a_size = size;
        k = floor(sqrt(size));
        
        for(int i = 0; i < size; ++i) {
            if((i + 1) % k == 0) {
                bsum += a_arr[i];
                b_arr.push_back(bsum);
                bsum = 0;
            }
            else {
                bsum += a_arr[i];
            }
        }
    }

    void Add(int value1, int value2) {
        a_arr[value1] += value2;
        int block = value1 / k;
        b_arr[block] += value2;
    }

    long long FindSum(int value1, int value2) {
        long long sum = 0ll;
        int block1 = value1 / k;
        int block2 = value2 / k;

        if(block1 == block2) {
            for(int i = value1; i < value2; ++i) {
                sum += a_arr[i];
            }
        } else {
            for(int i = value1; i < (block1 + 1) * k; ++i) {
                sum += a_arr[i];
            }
            for(int i = block1 + 1; i < block2; ++i) {
                sum += b_arr[i];
            }
            for(int i = block2 * k; i < value2; ++i) {
                sum += a_arr[i];
            }
        }
        return sum;
    }

    void Do() {
        if(operation == "FindSum") {
            cout << FindSum(num1, num2) << endl;
        } else if(operation == "Add") {
            Add(num1, num2);
        }
    }

    void Input() {
        getline(cin, s_num2);
        stringstream ss(s_num2);
        ss >> operation;
        ss >> s_num1;
        ss >> s_num2;
        num1 = stoi(s_num1);
        num2 = stoi(s_num2);
    }
};

int main() {
    // ----------------- INPUT -----------------
    int size;
    cin >> size;
    long long* arr = new long long[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int request;
    cin >> request;

    // ----------------- READ EMPTY -----------------
    string t;
    getline(cin, t);

    // ----------------- PROCESS -----------------
    Sum s(arr, size);
    for(int i = 0; i < request; ++i) {
        s.Input();
        s.Do();
    }
    return 0;
}