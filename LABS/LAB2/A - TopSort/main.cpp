#include <fstream>
#include <iostream>
#include <vector>

std::vector <int> color;
std::vector <int> answer;
std::vector <std::vector <int>>  graph;


void DFS (int top, bool& cycle) {

    color[top] = 1;

    for (int i = 0; i < graph[top].size(); i++) {

        if (cycle){
            return;
        }

        if (color[graph[top][i]] == 1) {
            cycle = true;
            return;
        }

        if (color[graph[top][i]] == 0)
            DFS(graph[top][i], cycle);
    }

    color[top] = 2;

    answer.push_back(top + 1);
}


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::ifstream fin ("topsort.in");
    std::ofstream fOut ("topsort.out");

    int n, m;
    fin >> n >> m;

    color.resize(n);
    graph.resize(n);


    int startRib;
    int finishRib;

    for (int i = 0; i < m; i++) // Filling graph
    {
        fin >> startRib >> finishRib;
        graph[startRib - 1].push_back(finishRib - 1);
    }
    fin.close();

    bool cycle = false;

    for (int i = 0; i < graph.size(); i++){

        if (color[i] == 0){
            DFS(i, cycle);
        }

        if (cycle){
            fOut << -1;
            return 0;
        }
    }

    for (size_t i = answer.size() - 1; i > 0; i--){
        fOut << answer[i] << " ";
    }
    fOut << answer[0];


    fOut.close();
    return 0;
}