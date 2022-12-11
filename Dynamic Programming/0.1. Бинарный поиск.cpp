#include <iostream>
using namespace std;

int BinarySearch(int arr[], int l, int r, int x, int n)
{
    if (l > r) {
        return n;
    }
    else {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            return BinarySearch(arr, mid + 1, r, x, n);
        }
        else {
            return BinarySearch(arr, l, mid - 1, x, n);
        }
    }
}

int LowerBound(int arr[], int l, int r, int x, int n) {
    if (l > r) {
        return l;
    }
    else {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            return LowerBound(arr, l, mid - 1, x, n);
        }
        else {
            return LowerBound(arr, mid + 1, r, x, n);
        }
    }
}

int UpperBound(int arr[], int l, int r, int x, int n) {
    if (l > r) {
        return l;
    }
    int mid = l + (r - l) / 2;
    if (arr[mid] <= x) {
        return UpperBound(arr, mid + 1, r, x, n);
    }
    return UpperBound(arr, l, mid - 1, x, n);
}

int main(){
    // ----------------- input -----------------
    int n = 0;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k = 0;
    cin >> k;
    int* request = new int[k];
    for(int i = 0; i < k; i++){
        cin >> request[i];
    }

    // ----------------- solution -----------------
    for(int i = 0; i < k; ++i) {
        int b = BinarySearch(arr, 0, n - 1, request[i], n);
        int l = LowerBound(arr, 0, n - 1, request[i], n);
        int r = UpperBound(arr, 0, n - 1, request[i], n);
        if (b != n) {
            b = 1;
            cout << b << " " << l << " " << r << endl;
        }
        else {
            b = 0;
            cout << b << " " << l << " " << r << endl;
        }
    }
}