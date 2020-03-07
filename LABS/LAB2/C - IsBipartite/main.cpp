#include <vector>
#include <fstream>
#include <algorithm>

std::vector <std::vector <int>> graph;
std::vector <std::vector <int>> graphRevers;
std::vector <char> isBurn;
std::vector <int> topSequence;
std::vector <int> strongComponent;
std::vector <int> answer;


void graphDFS (int top){

    isBurn[top] = true;

    for (int i : graph[top]) {
        if (!isBurn[i]) {
            graphDFS(i);
        }
    }
    topSequence.push_back(top);
}


void reversGraphDFS (int top) {

    isBurn[top] = true;
    strongComponent.push_back(top);

    for (int i : graphRevers[top]) {
        if (!isBurn[i]) {
            reversGraphDFS(i);
        }
    }
}


int main () {
    std::ifstream fin ("cond.in");
    std::ofstream fOut ("cond.out");

    int n, m;
    fin >> n >> m;

    graph.resize(n);
    graphRevers.resize(n);
    isBurn.resize(n);

    int startRib;
    int finishRib;

    for (int i = 0; i < m; i++){

        fin >> startRib >> finishRib;
        graph[startRib - 1].push_back(finishRib - 1);
        graphRevers[finishRib - 1].push_back(startRib - 1);
    }
    fin.close();

    int componentCount = 0;

    isBurn.assign(n, false);
    for (int i = 0; i < n; i++){

        if (!isBurn[i]) {
            graphDFS(i);
        }
    }

    isBurn.assign(n, false);
    std::reverse (topSequence.begin(), topSequence.end());
    for (int top : topSequence){

        if (!isBurn[top]) {
            reversGraphDFS(top);
            componentCount++;
            for (int j = 0; j < strongComponent.size(); j++){
                answer.push_back(componentCount);
            }
            strongComponent.clear();
        }
    }

    fOut << componentCount << "\n";
    for (int i : answer)
        fOut << i << " ";

    fOut.close();

    return 0;
}