#include <fstream>
#include <vector>
using namespace std;


int main() {
    ifstream fin ("input.txt");
    ofstream fOut ("output.txt");

    int n;
    int m;
    fin >> n >> m;

    vector <vector<int>> adjacencyMatrix (n, vector<int> (n, 0));


    int row, column;
    for (int i = 0; i < m; i++){

        fin >> row >> column;

        adjacencyMatrix[row - 1][column - 1] ++;
        adjacencyMatrix[column - 1][row - 1] ++;

        if (adjacencyMatrix[row - 1][column - 1] >= 2){
            fOut << "YES";

            fin.close();
            fOut.close();
            return 0;
        }
    }

    fOut << "NO";

    fin.close();
    fOut.close();
    return 0;
}
