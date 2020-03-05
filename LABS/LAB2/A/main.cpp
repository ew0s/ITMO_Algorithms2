#include <fstream>
#include <vector>
#include <algorithm>

std::vector <int> color;
std::vector <std::vector <int>> graph;
std::vector <int> answer;

void DFS (int top, bool& cycle, int& cycleTop, bool& foundCycleTop) {

    color[top] = 1;

    for (int i : graph[top]){

        if (color[i] == 1){

            answer.push_back(top);
            cycle = true;
            cycleTop = i;

            if (cycleTop == top) {
                foundCycleTop = true;
                answer.pop_back();
            }
            return;
        }

        if (color[i] == 0) {
            DFS(i, cycle, cycleTop, foundCycleTop);
        }

        if (foundCycleTop){
            return;
        }

        if (cycle && top != cycleTop){
            answer.push_back(top);
            return;
        }

        else if (cycle && top == cycleTop){
            foundCycleTop = true;
            return;
        }
    }

    color[top] = 2;

}


int main() {
    std::ifstream fin ("cycle.in");
    std::ofstream fOut ("cycle.out");

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
    bool foundCycleTop = false;
    int cycleTop = 0;

    for (int i = 0; i < graph.size(); i++){

        if (cycle) {
            break;
        }

        if (color[i] == 0){
            DFS (i, cycle, cycleTop, foundCycleTop);
        }
    }

    if (cycle) {

        fOut << "YES\n";

        std::reverse(answer.begin(), answer.end());

        for (int i : answer){
            fOut << (i + 1) << " ";
        }
        fOut << cycleTop + 1;

        fOut.close();
        return 0;
    }

    fOut << "NO";

    fOut.close();
    return 0;
}