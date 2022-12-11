#include <fstream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<long long> distance) {
    priority_queue<pair<int, int>> queue;
    distance[start] = 0;
    queue.push({0, start});
    
    while (!queue.empty()) {
        if(distance[queue.top().second] < -queue.top().first) {
            queue.pop();
            continue;
        }
        int cur = queue.top().second; queue.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (distance[cur] + graph[cur][i].second < distance[graph[cur][i].first]) {
                distance[graph[cur][i].first] = distance[cur] + graph[cur][i].second;
                queue.push({-distance[graph[cur][i].first], graph[cur][i].first});
            }
        }
    }
    return distance;
}

int main() {
    fstream fin("input.txt"); ofstream fout("output.txt");
    ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);

    int n, m; fin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for(int i = 0; i < m; i++) {
        int a, b, c; fin >> a >> b >> c;
        graph[a - 1].push_back(make_pair(b - 1, c));
        graph[b - 1].push_back(make_pair(a - 1, c));
    }

    vector<long long> distance(n, LLONG_MAX); distance = dijkstra(graph, 0, distance);
    fout << distance[n - 1];

    return 0;
}