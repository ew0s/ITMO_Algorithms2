#include <vector>
#include <cmath>
#include <iostream>
#include <set>
#include <fstream>

#define MAX 10000


void findMST (std::vector<std::vector <double>> &graph,
              std::vector <double> &min_weight,
              std::vector <bool> &used,
              int n)
{
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || min_weight[j] < min_weight[v]))
                v = j;
        }

        used[v] = true;

        for (int to = 0; to < n; to++) {
            if (graph[v][to] < min_weight[to]) {
                min_weight[to] = graph[v][to];
            }
        }
    }
}


struct top {
    int x_;
    int y_;
};


int main() {
    std::ifstream fin ("spantree.in");
    std::ofstream fOut ("spantree.out");
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    int n = 0;
    fin >> n;

    std::vector <top> graph_field;
    std::vector <std::vector <double>> graph (n, std::vector<double> (n, MAX));
    std::vector <double> min_weight (n, MAX);
    std::vector <bool> used (n);

    int x = 0, y = 0;

    for (size_t i = 0; i < n; i++) {

        fin >> x >> y;
        top newTop = {x, y};
        graph_field.push_back(newTop);
    }
    fin.close();

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {

            double distance = sqrt(pow(graph_field[j].x_ - graph_field[i].x_, 2) +
                                   pow(graph_field[j].y_ - graph_field[i].y_, 2));

            graph[i][j] = distance;
            graph[j][i] = distance;
        }
    }

    min_weight[0] = 0;
    findMST(graph, min_weight, used, n);

    double weightMST = 0;
    for (double i : min_weight) {
        weightMST += i;
    }
    fOut << weightMST;
    fOut.close();


    return 0;
}