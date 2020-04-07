#include <fstream>
#include <vector>

const long long INF = 8e18;

struct edge {
    int from;
    int to;
    long long weight = INF;
};

std::vector <edge> edges;
std::vector <std::vector<int>> graph;
std::vector <long long> dist;
std::vector <int> parent;
std::vector <bool> used;


void DFS (int from)
{
    used[from] = true;

    for (int to : graph[from])
    {
        if (!used[to])
        {
            DFS(to);
        }
    }
}


void find_min_weight (int n, int m, int s)
{

    dist[s] = 0;
    int last_relax_top = -1;

    for (int i = 0; i < n; i++)
    {
        last_relax_top = -1;
        for (int j = 0; j < m; j++)
        {
            int from = edges[j].from;
            int to = edges[j].to;
            long long weight = edges[j].weight;

            if (dist[from] < INF)
            {
                if (dist[to] > dist[from] + weight)
                {
                    dist[to] = std::max (-INF, dist[from] + weight);
                    parent[to] = from;
                    last_relax_top = to;
                }
            }
        }
    }

    if (last_relax_top != -1)
    {
        for (int i = 0; i < n; i++)
            last_relax_top = parent[last_relax_top];

        DFS(last_relax_top);

        for (int i = 0; i < n; i++)
        {
            if (used[i])
                dist[i] = -INF;
        }
    }
}


int main() {
    std::ifstream fin ("path.in");
    std::ofstream fOut ("path.out");

    int n, m, s;
    fin >> n >> m >> s;

    dist.assign(n, INF);
    parent.assign(n, -1);
    graph.resize(n);
    used.resize(n);

    int from, to;
    long long weight;

    for (int i = 0; i < m; i++)
    {
        fin >> from >> to >> weight;
        edges.push_back({from - 1, to - 1, weight});
        graph[from - 1].push_back(to - 1);
    }
    fin.close();

    find_min_weight(n, m, s - 1);

    for (long long thisDist : dist)
    {
        switch (thisDist)
        {
            case -INF:
                fOut << "-";
                break;

            case INF:
                fOut << "*";
                break;

            default:
                fOut << thisDist;
        }
        fOut << '\n';
    }
    fOut.close();

    return 0;
}