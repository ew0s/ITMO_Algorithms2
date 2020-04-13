#include <fstream>
#include <vector>
#include <set>

const long long MAX = 2e18;


void Dijkstra (const std::vector <std::vector <std::pair <int, int>>> &graph,
               std::vector <long long> &dist,
               std::set <std::pair <long long, int>> &q,
               int vertex)
               {
    dist[vertex] = 0;
    q.insert ({0, vertex});

    while (!q.empty())
    {
        vertex = q.begin()->second;
        q.erase(q.begin());

        for (size_t j = 0; j < graph[vertex].size(); j++)
        {
            int to = graph[vertex][j].second;
            int weight = graph[vertex][j].first;

            if (dist[to] > dist[vertex] + weight)
            {
                q.erase({dist[to], to});
                dist[to] = dist[vertex] + weight;
                q.insert({dist[to], to});
            }
        }
    }
}


int main () {
    std::ifstream fin ("pathbgep.in");
    std::ofstream fOut ("pathbgep.out");

    int n, m;

    fin >> n >> m;

    std::vector <std::vector <std::pair <int, int>>> graph (n);

    int startRib, finishRib, weight;
    for (int i = 0; i < m; i++)
    {
        fin >> startRib >> finishRib >> weight;

        graph[startRib - 1].push_back({weight, finishRib - 1});
        graph[finishRib - 1].push_back({weight, startRib - 1});
    }
    fin.close();

    std::vector <long long> dist;
    dist.assign(n, MAX);
    std::set <std::pair <long long, int>> q;

    Dijkstra(graph, dist, q, 0);

    for (int i = 0; i < n; i++)
    {
        fOut << dist[i] << " ";
    }
    fOut.close();

    return 0;
}
