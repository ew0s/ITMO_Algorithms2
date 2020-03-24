#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream fin ("input.txt");
    std::ofstream fOut ("output.txt");

    int n, m;
    fin >> n >> m;

    std::vector <std::vector <int>> graph;
    graph.resize(n);

    int startRib, finishRib;
    for (int i = 0; i < m; i++) {

        fin >> startRib >> finishRib;
        graph[startRib - 1].push_back(finishRib - 1);
        graph[finishRib - 1].push_back(startRib - 1);
    }
    fin.close();

    for (int i = 0; i < n; i++)
        fOut << graph[i].size() << " ";
    fOut.close();
    return 0;
}
