#include <fstream>
#include <set>
using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	set<int> st;
	int a = 0;
	while (!fin.eof()) {
		fin >> a;
		st.insert(a);
	}
	long long sum = 0;
	for (auto i : st) {
		sum += i;
	}
	fout << sum;
	return 0;
}