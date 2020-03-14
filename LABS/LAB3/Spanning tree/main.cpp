#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <fstream>

struct top {
    int x_;
    int y_;
};


void makeMST (std::vector <std::vector <double>> &graph) {

}


int main() {
    std::ifstream fin ("spantree.in");
    std::ofstream fOut ("spantree.out");

    int n;
    fin >> n;

    std::vector <std::vector <double >> graph (n);
    std::vector <top> graph_field;
    std::vector <char> isBurn (n, 0);
    int r = 0;

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

            graph[i].push_back(distance);
            graph[j].push_back(distance);
        }
    }

    std::priority_queue()


    return 0;
}