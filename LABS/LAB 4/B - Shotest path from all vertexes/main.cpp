#include <iostream>
#include <fstream>
#include <vector>

const int MAX = 10000;


struct edge {
    int start;
    int finish;
    int weight;
};


void findMinWeight (std::vector <int> &dist,
        const std::vector <edge> &edges,
        int n,
        int m,
        int vertex) {

    dist[vertex] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {

            int start = edges[j].start;
            int finish = edges[j].finish;
            int weight = edges[j].weight;

            dist[finish] = std::min (dist[finish], dist[start] + weight);
        }
    }
}


int main() {
    std::ifstream fin ("pathsg.in");
    std::ofstream fOut ("pathsg.out");

    int n, m;
    fin >> n >> m;

    std::vector <edge> edges;

    int start, finish, weight;
    for (int i = 0; i < m; i++) {
        fin >> start >> finish >> weight;
        edge newEdge = {start - 1, finish - 1, weight};
        edges.push_back(newEdge);
    }
    fin.close();

    std::vector <int> dist;
    dist.assign(n, MAX);
    std::vector <std::vector <int>> min_weight_matrix;
    min_weight_matrix.assign(n, std::vector <int> (n));

    for (int i = 0; i < n; i++) {

        findMinWeight(dist, edges, n, m, i);

        for (int j = 0; j < n; j++) {
            min_weight_matrix[i][j] = dist[j];
        }

        dist.assign(n, MAX);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fOut << min_weight_matrix[i][j] << " ";
        }
        fOut << '\n';
    }
    fOut.close();

    return 0;
}
