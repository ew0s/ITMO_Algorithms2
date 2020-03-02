#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("input.txt");
    ofstream fOut ("output.txt");

    int n;
    fin >> n;

    int** adjacencyArray = new int* [n];
    for (int i = 0; i < n; i++)
        adjacencyArray[i] = new int [n];

    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){
            fin >> adjacencyArray[i][j];
        }
    }

    fin.close();

    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){

            if (i != j){
                if (adjacencyArray[i][j] != adjacencyArray[j][i]){
                    fOut << "NO";
                    return 0;
                }
            }
            else {
                if (adjacencyArray[i][j] == 1){
                    fOut << "NO";
                    return 0;
                }
            }
        }
    }

    fOut << "YES";
    fOut.close();
    return 0;
}
