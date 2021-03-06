#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

struct top {
    struct top* left = nullptr;
    struct top* right = nullptr;
    struct top* down = nullptr;
    struct top* up = nullptr;
    std::string path = "";
    bool isBurn = false;
    int numb = 0;
    int distance = 0;
};


void fillingGraph (top* graph, int (*graphMatrix)[102], int n, int m){

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){

            if (graphMatrix[i][j] != -1) {

                if (graphMatrix[i][j - 1] != -1) {
                    graph[graphMatrix[i][j]].left = &graph[graphMatrix[i][j - 1]];
                }

                if (graphMatrix[i - 1][j] != -1) {
                    graph[graphMatrix[i][j]].up = &graph[graphMatrix[i - 1][j]];
                }

                if (graphMatrix[i][j + 1] != -1) {
                    graph[graphMatrix[i][j]].right = &graph[graphMatrix[i][j + 1]];
                }

                if (graphMatrix[i + 1][j] != -1) {
                    graph[graphMatrix[i][j]].down = &graph[graphMatrix[i + 1][j]];
                }
            }
        }
    }
}


void BFS (top* graph, std::queue <int>& q, int finishTop){
    std::ofstream fOut ("output.txt");


    while (!q.empty()){

        int top = q.front();
        graph[top].isBurn = true;
        q.pop();

        if (graph[top].left != nullptr && !graph[top].left->isBurn){
            graph[top].left->isBurn = true;
            graph[top].left->distance = graph[top].distance + 1;
            graph[top].left->path = graph[top].path + 'L';
            q.push(graph[top].left->numb);
        }

        if (graph[top].right != nullptr && !graph[top].right->isBurn){
            graph[top].right->isBurn = true;
            graph[top].right->distance = graph[top].distance + 1;
            graph[top].right->path = graph[top].path + 'R';
            q.push(graph[top].right->numb);
        }

        if (graph[top].up != nullptr && !graph[top].up->isBurn){
            graph[top].up->isBurn = true;
            graph[top].up->distance = graph[top].distance + 1;
            graph[top].up->path = graph[top].path + 'U';
            q.push(graph[top].up->numb);
        }

        if (graph[top].down != nullptr && !graph[top].down->isBurn){
            graph[top].down->isBurn = true;
            graph[top].down->distance = graph[top].distance + 1;
            graph[top].down->path = graph[top].path + 'D';
            q.push(graph[top].down->numb);
        }

        if (top == finishTop){
            fOut << graph[top].distance << "\n" << graph[top].path;
            fOut.close();
            exit(0);
        }
    }
}


int main() {
    std::ifstream fin ("input.txt");
    std::ofstream fOut ("output.txt");


    // Filling graphMatrix
    int n, m;
    int graphMatrix[102][102];
    for (int i = 0; i < 102; i++){
        for (int j = 0; j < 102; j++){
            graphMatrix[i][j] = -1;
        }
    }

    int startRow = 0, startColumn = 0;
    int finishRow = 0, finishColumn = 0;
    int topCount = 0;

    fin >> n >> m;
    std::string str;

    for (int i = 0; i < n; i++){

        fin >> str;
        for (int j = 0; j < m; j++){

            if (str[j] == 'S'){
                graphMatrix[i + 1][j + 1] = topCount;
                topCount++;
                startRow = i + 1, startColumn = j + 1;
            }

            else if (str[j] == 'T'){
                graphMatrix[i + 1][j + 1] = topCount;
                topCount++;
                finishRow = i + 1, finishColumn = j + 1;
            }

            else if (str[j] == '.'){
                graphMatrix[i + 1][j + 1] = topCount;
                topCount++;
            }

            else {
                graphMatrix[i + 1][j + 1] = -1;
            }
        }
    }
    fin.close();


    //definition and declaration Graph
    auto graph = new top [topCount];
    for (int i = 0; i < topCount; i++)
        graph[i].numb = i;


    fillingGraph(graph, graphMatrix, n, m);

    //declaration queue
    std::queue <int> q;
    q.push(graphMatrix[startRow][startColumn]);

    int finishTop = graphMatrix[finishRow][finishColumn];
    if (n + m != 0 && n + m != 1 && n + m != 2)
        BFS(graph, q, finishTop);

    fOut << -1;
    fOut.close();
    return 0;
}
