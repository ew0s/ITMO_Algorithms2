#include <iostream>
#include <vector>
#include <cmath>
constexpr int MAX = 31415926535;
using std::cin;
using std::cout;

void findMST (std::vector <std::vector <int>> graph,
              std::vector <int> &min_weight,
              std::vector <bool> &used,
              int n)
{
    min_weight[0] = 0;
    for (size_t i = 0; i < n; i++) {
        int v = -1;
        for (size_t j = 0; j < n; j++)
            if (!used[j] && (v == -1 || min_weight[j] < min_weight[v]))
                v = j;
        used[v] = true;
        for (size_t j = 0; j < n; j++)
            if (!used[j] && graph[v][j] < min_weight[j] && v != j)
                min_weight[j] = graph[v][j];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    std::vector <std::pair <int, int>> graph_field (n);
    std::vector <std::vector <int>> graph (n, std::vector<int> (n));
    std::vector <int> min_weight (n, MAX);
    std::vector <bool> used (n, false);

    for (auto& field : graph_field)
        cin >> field.first >> field.second;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {

            graph[i][j] = pow(graph_field[i].first - graph_field[j].first, 2) + pow(graph_field[i].second - graph_field[j].second, 2);
        }
    }


    findMST(graph, min_weight, used, n);

    double weightMST = 0;
    for (size_t i = 0; i < n; i++) {
        weightMST += sqrt(min_weight[i]);
    }
    std::cout.precision(10);
    cout << weightMST << "\n";

    return 0;
}