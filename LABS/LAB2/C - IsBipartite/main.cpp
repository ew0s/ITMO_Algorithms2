#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector <int>> graph;
std::vector <int> color;


inline int transposition (int whatColor) {

    (whatColor == 1) ? whatColor = 2 : whatColor = 1;
    return whatColor;
}

void DFS (const int& top, int whatColor, bool& isBipartite) {

    color[top] = whatColor;

    for (int i : graph[top]) {

        if (color[i] == 0) {
            DFS (i, transposition(whatColor), isBipartite);
        }

        if (!isBipartite) {
            return;
        }

        if (color[i] == whatColor) {
            isBipartite = false;
            return;
        }
    }
}

int main() {
    std::ifstream fin ("bipartite.in");
    std::ofstream fOut ("bipartite.out");

    int n, m;
    fin >> n >> m;

    graph.resize(n);
    color.resize(n);

    int startRib;
    int finishRib;

    for (int i = 0; i < m; i++) // Filling graph
    {
        fin >> startRib >> finishRib;
        graph[startRib - 1].push_back(finishRib - 1);
        graph[finishRib - 1].push_back(startRib - 1);
    }
    fin.close();

    int whatColor = 1;
    bool isBipartite = true;

    for (int i = 0; i < graph.size(); i++){

        if (color[i] == 0) {
            DFS (i, whatColor, isBipartite);
        }
    }

    if (isBipartite) {
        fOut << "YES";
    }
    else {
        fOut << "NO";
    }

    fOut.close();

    return 0;
}
