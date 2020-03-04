#include <vector>
#include <fstream>


void DFS (std::vector<std::vector<int>>& adjacencyList, int* components, int top, bool* isBurn, int& componentsCount){
    isBurn[top] = true;
    components[top] = componentsCount;

    for (int i = 0; i < adjacencyList[top].size(); i++){

        if (!isBurn[adjacencyList[top][i]]){
            DFS (adjacencyList, components, adjacencyList[top][i], isBurn, componentsCount);
        }
    }
}


int main(){
    std::ifstream fin ("components.in");
    std::ofstream fOut ("components.out");

    int n, m;
    fin >> n >> m;

    bool isBurn[100000] = {false};
    int components[100000] = {0};
    int componentsCount = 0;
    std::vector <std::vector <int>> adjacencyList (n, std::vector<int> (0));


    int ribBegin;
    int ribEnd;
    for (int i = 0; i < m; i++){
        fin >> ribBegin >> ribEnd;

        adjacencyList[ribBegin - 1].push_back(ribEnd - 1);
        adjacencyList[ribEnd - 1].push_back(ribBegin - 1);
    }
    fin.close();


    for (int i = 0; i < adjacencyList.size(); i++){

        if (!isBurn[i]){
            componentsCount++;
            DFS(adjacencyList, components, i, isBurn, componentsCount);
        }
    }


    fOut << componentsCount << "\n";

    for (int i = 0; i < n; i++){
        fOut << components[i] <<  " ";
    }


    return 0;
}