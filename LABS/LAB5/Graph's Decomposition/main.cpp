#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using std::vector;

const int INF = INT_MAX;

struct edge
{
    int to, capacity, flow, number;
};

vector <vector <int>> graph;
vector <edge> edges;
vector <int> levels;
vector <int> ptr;
vector <vector<int>> paths;

int s = 0;
int t = 0;


bool BFS()
{
    levels.assign(levels.size(), 0);
    std::queue <int> q;

    q.push(s);
    levels[s] = 1;

    while (!q.empty() && !levels[t])
    {
        int from = q.front();
        q.pop();

        for (auto & to : graph[from])
        {
            if (edges[to].capacity - edges[to].flow <= 0)
                continue;

            if (!levels[edges[to].to])
            {
                q.push(edges[to].to);
                levels[edges[to].to] = levels[from] + 1;
            }
        }
    }

    return levels[t];
}


void redirect_flow (int & position, int & flow)
{
    edges[position].flow += flow;
    edges[position ^ 1].flow -= flow;
}


int DFS (int min_flow, int pointer)
{
    if (!min_flow)
        return 0;

    if (t == pointer)
        return min_flow;

    for (; ptr[pointer] < graph[pointer].size(); ptr[pointer]++)
    {
        edge& to = edges[graph[pointer][ptr[pointer]]];
        int from = pointer;
        int levels_to = levels[to.to];
        int levels_from = levels[from];
        if (levels_to == levels_from + 1)
        {
            int pushed = DFS(std::min(min_flow, to.capacity - to.flow), to.to);

            if (pushed)
            {
                redirect_flow(graph[pointer][ptr[pointer]], pushed);
                return pushed;
            }
        }
    }

    return 0;
}


int show_paths(int pointer, int flow_value)
{
    if (pointer == t)
    {
        paths.emplace_back();
        return flow_value;
    }

    for (auto & to : graph[pointer])
    {
        if (edges[to].flow > 0)
        {
            int flow = show_paths(edges[to].to,
                    std::min(flow_value, edges[to].flow));

            if (flow)
            {
                paths.back().push_back(edges[to].number);
                if (pointer == s)
                {
                    paths.back().push_back(paths[paths.size() - 1].size());
                    paths.back().push_back(flow);
                    std::reverse(paths.back().begin(), paths.back().end());
                }

                edges[to].flow -= flow;
                return flow;
            }
        }
    }

    return 0;
}


void add_edge(int from, int to, int weight, int numb)
{
    graph[from].push_back(edges.size());
    edges.push_back({to, weight, 0, numb});
    graph[to].push_back(edges.size());
    edges.push_back({from, 0, 0, numb});
}


int main()
{
    std::ifstream fin ("decomposition.in");
    std::ofstream fOut ("decomposition.out");

    int n, m;
    fin >> n >> m;

    graph.resize(n, vector<int>());
    levels.resize(n, 0);
    ptr.resize(n, 0);

    int from, to, weight;
    for (int i = 0; i < m; i++)
    {
        fin >> from >> to >> weight;
        add_edge(from - 1, to - 1, weight, i + 1);
    }
    fin.close();

    s = 0;
    t = n - 1;
    while (BFS())
    {
        while (DFS(INF, s));
        ptr.assign(n, 0);
    }

    while (show_paths(s, INF));

    fOut << paths.size() << "\n";

    for (auto & i : paths)
    {
        for (auto &j : i)
            fOut << j << " ";
        fOut << "\n";
    }
    fOut.close();

    return 0;
}