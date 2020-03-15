#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <fstream>


std::vector <std::pair<double, int>> graph;
std::vector <char> isBurn;


struct top {
    int x_;
    int y_;
};


int main() {
    std::ifstream fin ("spantree.in");
    std::ofstream fOut ("spantree.out");

    int n;
    fin >> n;

    std::vector <top> graph_field;
    graph.reserve(n);

    int x, y;

    for (size_t i = 0; i < n; i++){

        fin >> x >> y;
        top newTop = {x, y};
        graph_field.push_back(newTop);
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++){

            double distance = sqrt(pow (graph_field[j].x_ - graph_field[i].x_, 2) +
            pow (graph_field[j].y_ - graph_field[i].y_, 2));

            graph.push_back(distance, i);
            graph[j] = {distance, i};
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << i << " -> " <<  graph[i].second << "with distance " << graph[i].first << "\n";
    }


    return 0;
}