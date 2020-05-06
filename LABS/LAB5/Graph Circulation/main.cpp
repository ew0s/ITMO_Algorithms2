#include <fstream>
#include <vector>
#include <queue>

using std::vector;

struct edge
{
    int from, to, capacity, flow;
};

typedef vector<int> int_vector;
typedef vector<vector<int>> matrix;
typedef vector<edge> edge_vector;

edge_vector edges;
int_vector ptr;
int_vector levels;
matrix graph;

int source = 0, sink = 0, vertexes_count = 0, edges_count = 0;


bool BFS()
{
    levels.assign(vertexes_count, 0);
    std::queue <int> q;

    q.push(source);
    levels[source] = 1;

    while (!q.empty() && !levels[sink])
    {
        int from = q.front();
        q.pop();

        for (auto & edge : graph[from])
        {
            if (!levels[edges[edge].to] && edges[edge].capacity > edges[edge].flow)
            {
                q.push(edges[edge].to);
                levels[edges[edge].to] = levels[from] + 1;
            }
        }
    }

    return levels[sink];
}


int DFS(int vertex = source, int flow = INT_MAX)
{
    if (!flow)
        return 0;

    if (vertex == sink)
        return flow;

    while (ptr[vertex] < graph[vertex].size())
    {
        int edge = graph[vertex][ptr[vertex]];
        if (levels[vertex] + 1 == levels[edges[edge].to])
        {
            int pushed = DFS(edges[edge].to,
                    std::min (flow, edges[edge].capacity - edges[edge].flow));
            if (pushed)
            {
                edges[edge].flow += pushed;
                edges[edge ^ 1].flow -= pushed;
                return pushed;
            }
        }
        ptr[vertex]++;
    }
    return 0;
}


void add_edge (int from, int to, int capacity)
{
    graph[from].push_back(edges.size());
    edges.emplace_back(edge{ from, to, capacity, 0});
    graph[to].push_back(edges.size());
    edges.emplace_back(edge{ to, from, 0, 0 });
}


int main()
{
    std::ifstream fin ("circulation.in");
    std::ofstream fOut ("circulation.out");

    fin >> vertexes_count >> edges_count;
    vertexes_count += 2;

    graph.resize(vertexes_count);
    ptr.resize(vertexes_count, 0);

    sink = vertexes_count - 1;

    int from, to, low_capacity, high_capacity;
    for (int i = 0; i < edges_count; i++)
    {
        fin >> from >> to >> low_capacity >> high_capacity;
        add_edge(source, to, low_capacity);
        add_edge(from, to, high_capacity - low_capacity);
        add_edge(from, sink, low_capacity);
    }

    while (BFS())
    {
        while (DFS());
        ptr.assign(vertexes_count, 0);
    }

    for (int edge : graph[0])
    {
        if (edges[edge].flow < edges[edge].capacity)
        {
            fOut << "NO";
            fOut.close();
            return 0;
        }
    }

    fOut << "YES\n";

    for (int i = 0; i < edges.size(); i += 6)
        fOut << edges[i + 2].flow + edges[i + 4].flow << '\n';
    fOut.close();

    return 0;
}
