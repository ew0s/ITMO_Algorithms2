#include <fstream>
#include <vector>
using namespace std;


int main() {
    ifstream fin ("input.txt");
    ofstream fOut ("output.txt");
    int n;
    int m;
    fin >> n >> m;

    vector <vector<int>> adjacencyArray(n, vector<int> (n, 0));

    int row;
    int column;
    for(int i = 0; i < m; i++){
        fin >> row >> column;
        adjacencyArray[row - 1][column - 1] = 1;
    }

    fin.close();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fOut << adjacencyArray[i][j];
            if (j != n - 1){
                fOut << " ";
            }
        }

        if (i != n - 1) {
            fOut << "\n";
        }
    }

    fOut.close();

    return 0;
}