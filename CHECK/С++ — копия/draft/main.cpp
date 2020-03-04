#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> g [100];
bool win [100];
bool loose [100];
bool used[100];
int degree[100];

void dfs (int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (!used[to]) {
            if (loose[v])
                win[to] = true;
            else if (--degree[to] == 0)
                loose[to] = true;
            else
                continue;
            dfs(to);
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::ifstream fin ("topsort.in");
    std::ofstream fOut ("topsort.out");

    int n, m;
    fin >> n >> m;

    int startRib;
    int finishRib;

    for (int i = 0; i < m; i++) // Filling graph
    {
        fin >> startRib >> finishRib;
        g[startRib - 1].push_back(finishRib - 1);
    }
    fin.close();


    for (int i = 0; i < g->size(); i++){
        if (!used[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < 15; i++) {
        cout << loose[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 15; i++) {
        cout << win[i] << " ";
    }
    fOut.close();
    return 0;
}