#include <fstream>
#include <vector>
#include <stack>

std::vector <std::vector <int>> graph;
std::vector <char> color;
std::stack <int> answer;

void DFS (int top){

    color[top] = 1;

    for (int i : graph[top]) {

        if (! int(color[i])) {
            DFS(i);
        }
    }

    answer.push(top);
}


int main() {
    std::ifstream fin ("hamiltonian.in");
    std::ofstream fOut ("hamiltonian.out");

    int n, m;
    fin >> n >> m;

    int startRib, finishRib;
    graph.resize(n);
    color.assign(n, 0);

    for (int i = 0; i < m; i++) {

        fin >> startRib >> finishRib;
        graph[startRib - 1].push_back(finishRib - 1);
    }
    fin.close();

    for (int i = 0; i < n; i++) {

        if (! int(color[i])) {
            DFS (i);
        }
    }

    int that = 0, prev = 0;
    bool isHamiltonian = false;

    if (!answer.empty()) {
        isHamiltonian = true;
        prev = answer.top();
        answer.pop();
    }

    while (!answer.empty() && isHamiltonian) {

        that = answer.top();
        answer.pop();
        isHamiltonian = false;

        for (int i : graph[prev]) {

            if (i == that) {
                isHamiltonian = true;
                break;
            }
        }

        prev = that;
    }

    if (isHamiltonian)
        fOut << "YES";
    else
        fOut << "NO";
    fOut.close();

    return 0;
}
