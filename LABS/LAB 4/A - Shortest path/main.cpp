#include <fstream>
#include <vector>

const long long MAX = 2e18;


void Dijkstra (const std::vector <std::vector <std::pair <int, int>>> &graph,
               std::vector <char> &used,
               std::vector <long long> &dist,
               int n,
               int vertex) {

    dist[vertex] = 0;

    for (int i = 0; i < n; i++) {

        vertex = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (vertex == -1 || dist[j] < dist[vertex]))
                vertex = j;
        }

        used[vertex] = true;

        for (int j = 0; j < graph[vertex].size(); j++) {

            int to = graph[vertex][j].second;
            int weight = graph[vertex][j].first;

            dist[to] = std::min (dist[to], dist[vertex] + weight);
        }
    }
}


int main () {
    std::ifstream fin ("pathmgep.in");
    std::ofstream fOut ("pathmgep.out");

    int n;
    int start_vertex;
    int finish_vertex;

    fin >> n >> start_vertex >> finish_vertex;

    std::vector <std::vector <std::pair <int, int>>> graph (n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int weight;
            fin >> weight;
            if (weight != -1)
                graph[i].push_back({weight, j});
        }
    }
    fin.close();

    std::vector <char> used;
    used.assign(n, false);
    std::vector <long long> dist;
    dist.assign(n, MAX);

    Dijkstra(graph, used, dist, n, start_vertex - 1);

    if (dist[finish_vertex - 1] != MAX)
        fOut << dist[finish_vertex - 1];
    else
        fOut << -1;
    fOut.close();

    return 0;
}