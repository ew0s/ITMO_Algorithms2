#include <iostream>
#include <fstream>
#include <vector>
#include <set>


void findMST_Prim(
        std::vector <std::vector <std::pair <int, int>>> graph,
        std::vector <int> &min_weight,
        std::vector <bool> used,
        std::set <std::pair <int, int>> q);


int main() {
    std::ifstream fin ("spantree3.in");
    std::ofstream fOut ("spantree3.out");
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    int n, m;
    fin >> n >> m;

    std::vector <std::vector <std::pair <int, int>>> graph (n);
    std::vector <int> min_weight (n, 100000);
    std::vector <bool> used (n, false);
    std::set <std::pair <int, int>> q;

    int startRib, finishRib;
    int weight;
    for (int i = 0; i < m; i++) {

        fin >> startRib >> finishRib >> weight;
        graph[startRib - 1].push_back({weight, finishRib - 1});
        graph[finishRib - 1].push_back({weight, startRib - 1});
    }
    fin.close();

    min_weight[0] = 0;
    q.insert({0, 0});
    findMST_Prim(graph, min_weight, used, q);

    long long weightMST = 0;
    for (int i = 0; i < min_weight.size(); i++) {
        weightMST += min_weight[i];
    }
    fOut << weightMST;

    fOut.close();

    return 0;
}


void findMST_Prim(
        std::vector <std::vector <std::pair <int, int>>> graph,
        std::vector <int> &min_weight,
        std::vector <bool> used,
        std::set <std::pair <int, int>> q){

    while(!q.empty()) {

        int top = q.begin()->second;
        q.erase(q.begin());

        for (int i = 0; i < graph[top].size(); i++) {

            int to = graph[top][i].second;
            int cost = graph[top][i].first;

            if (!used[to]) {

                if (cost < min_weight[to]) {
                    q.erase({min_weight[to], to});
                    min_weight[to] = cost;
                    q.insert({min_weight[to], to});
                }
            }
        }
        used[top] = true;
    }
}