#include <fstream>
#include <vector>
#include <queue>


using std::vector;

typedef vector <vector <bool>> Matrix;
typedef vector <bool> bool_vector;
typedef vector <int> int_vector;

int Ford_Felkerson (Matrix &, int, int);

int BFS (Matrix &, int, int, int_vector &);


int main()
{
    std::ifstream fin ("matching.in");
    std::ofstream fOut ("matching.out");

    int n, m, k;
    fin >> n >> m >> k;

    Matrix graph (n + m + 2, bool_vector(n + m + 2, false));

    int from, to;
    for (int i = 0; i < k; i++)
    {
        fin >> from >> to;
        graph[from][to + n] = true;
    }

    for (int i = 1; i <= n; i++)
        graph[0][i] = true;

    for (int i = n + 1; i <= m + n; i++)
        graph[i][n + m + 1] = true;

    fin.close();

    fOut << Ford_Felkerson(graph, 0, n + m + 1);

    fOut.close();

    return 0;
}


int BFS (Matrix &graph, int s, int t, int_vector &parent)
{
    std::queue <int> q;
    bool_vector visited (graph.size(), false);

    q.push(s);
    visited[s] = true;

    int from;

    while (!q.empty())
    {
        from = q.front();
        q.pop();

        for (int to = 0; to < graph.size(); to++)
        {
            if (!visited[to] && graph[from][to])
            {
                q.push(to);
                visited[to] = true;
                parent[to] = from;
            }
        }
    }

    return visited[t];
}

int Ford_Felkerson (Matrix &graph, int s, int t)
{
    int_vector parent (graph.size());

    int max_flow = 0;
    int from;

    while (BFS(graph, s, t, parent))
    {
        for (int to = t; to != s; to = parent[to])
        {
            from = parent[to];
            graph[from][to] = false;
            graph[to][from] = true;
        }
        max_flow++;
    }

    return max_flow;
}
