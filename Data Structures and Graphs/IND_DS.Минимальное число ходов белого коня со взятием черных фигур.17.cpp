#include <fstream>
#include <vector>
#include <queue>
#include <limits.h>
#include <set>
using namespace std;

ofstream fout("out.txt");

pair<int, int> steps[8] = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2},
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};

void get_answ(vector<vector<long long>> &a, vector<vector<long long>> &b, pair<int, int> start, pair<int, int> finish, int mx, int my) {
    set<pair<int, int>> s;
    s.emplace(start);
    while(!s.empty()) {
        pair<int, int> cur = *s.begin();
        s.erase(s.begin());
        for(int i = 0; i < 8; i++) {
            pair<int, int> next = {cur.first + steps[i].first, cur.second + steps[i].second};
            if(next.first < 0 || next.first >= mx || next.second < 0 || next.second >= my) continue;
            if(a[next.first][next.second] == -1) continue;
            if(b[cur.first][cur.second] + a[next.first][next.second] < b[next.first][next.second]) {
                b[next.first][next.second] = b[cur.first][cur.second] + a[next.first][next.second];
                s.emplace(next);
            }
        }
    }

    if(b[finish.first][finish.second] == INT_MAX || b[finish.first][finish.second] == -1) fout << "No";
    else fout << b[finish.first][finish.second];
    return;
}

int main() {
    fstream fin("in.txt");
    ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);

    int n, m; fin >> n >> m;
    vector<vector<long long>> board = vector<vector<long long>>(n, vector<long long>(m, 0));    
    vector<vector<long long>> result_board = vector<vector<long long>>(n, vector<long long>(m, INT_MAX));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            fin >> board[i][j];
            if(board[i][j] == 0) { board[i][j] = 1; }
            else if(board[i][j] == 1) { board[i][j] = 2; }
        }
    }

    int x1, y1, x2, y2; fin >> x1 >> y1 >> x2 >> y2;
    --x1; --y1; --x2; --y2;

    result_board[x1][y1] = 0;

    get_answ(board, result_board, {x1, y1}, {x2, y2}, n, m);
    return 0;
}