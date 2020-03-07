#include <iostream>
#include <fstream>
#include <vector>

std::vector <std::vector<int>> graph;
std::vector <char> isBurn;
std::vector <char> status; //win == 1; loose == 0;


void DFS (int top){

    isBurn[top] = true;

    for (int i : graph[top]){

        if (!isBurn[i]) {

            DFS(i);

            if (status[i] == 0)
                status[top] = 1;
        }

        else if (isBurn[i] && status[i] == 0) {

            status[top] = 1;
        }
    }
}

int main() {
    std::ifstream fin ("game.in");
    std::ofstream fOut ("game.out");

    int n, m, s;
    fin >> n >> m >> s;
    graph.resize(n);
    status.assign(n, 0);
    isBurn.assign(n, false);

    int startRib, finishRib;
    for (int i = 0; i < m; i++){

        fin >> startRib >> finishRib;
        graph[startRib - 1].push_back(finishRib - 1);
    }
    fin.close();

    for (int i = 0; i < n; i++) {

        if (!isBurn[i])
            DFS(i);
    }

    if (status[s - 1]) {
        fOut << "First player wins";
    } else {
        fOut << "Second player wins";
    }
    fOut.close();


    return 0;
}