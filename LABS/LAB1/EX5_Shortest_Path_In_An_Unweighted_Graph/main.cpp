#include <vector>
#include <queue>
#include <fstream>


int main(){
    std::ifstream fin("pathbge1.in");
    std::ofstream fOut("pathbge1.out");

    int n, m;
    fin >> n >> m;

    std::vector <std::vector<int>> adjacencyList (n);

    int ribBegin, ribEnd;
    for (int i = 0; i < m; i++){
        fin >> ribBegin >> ribEnd;

        adjacencyList[ribBegin - 1].push_back(ribEnd - 1);
        adjacencyList[ribEnd - 1].push_back(ribBegin - 1);
    }

    fin.close();

    bool isBurn[100000] = {false};
    int LenOfPath[100000] = {0};
    std::queue <int> q;

    isBurn[0] = true;
    q.push(0);

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 0; i < adjacencyList[top].size(); i++) {

            if (!isBurn[adjacencyList[top][i]]) {
                isBurn[adjacencyList[top][i]] = true;
                LenOfPath[adjacencyList[top][i]] = LenOfPath[top] + 1;
                q.push(adjacencyList[top][i]);
            }
        }
    }

    for (int i = 0; i < n; i++){
        fOut << LenOfPath[i] << " ";
    }
    fOut.close();

    return 0;
}
