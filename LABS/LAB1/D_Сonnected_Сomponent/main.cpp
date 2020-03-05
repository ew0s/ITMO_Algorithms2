#include <iostream>
#include <fstream>


struct adjacencyList{
    int number = -1;
    struct adjacencyList* next = nullptr;
};


void DFS (adjacencyList* pointerOnTop, int* componentsArray, bool* isBurn, int& componentsCount){
    isBurn[pointerOnTop->number] = true;
    componentsArray[pointerOnTop->number] = componentsCount;

    while (pointerOnTop->next != nullptr){

        if (!isBurn[pointerOnTop->next->number]){
            DFS (pointerOnTop->next, componentsArray, isBurn, componentsCount);
        }
        pointerOnTop = pointerOnTop->next;
    }

}


void searchComponents (adjacencyList* List, int* componentsArray, bool* isBurn, int& componentsCount, int size){
    for (int i = 0; i < size; i++){

        if (!isBurn[i]){
            componentsCount++;
            DFS (&List[i], componentsArray, isBurn, componentsCount);
        }
    }
}


int main(){
    std::ifstream fin ("input.txt");
    std::ofstream fOut ("output.txt");

    int n;
    int m;
    fin >> n >> m;

    adjacencyList adjacencyArray[100000];
    for (int i = 0; i < n; i++)
        adjacencyArray[i].number = i;

    int row;
    int column;

    for (int i = 0; i < m; i++) {
        fin >> row >> column;

        auto newRibColumn = new adjacencyList();
        newRibColumn->number = column - 1;

        auto newRibRow = new adjacencyList();
        newRibRow->number = row - 1;

        adjacencyList *p = &adjacencyArray[row - 1];
        adjacencyList *q = &adjacencyArray[column - 1];

        while (p->next != nullptr) {
            p = p->next;
        }
        (*p).next = newRibColumn;

        while (q->next != nullptr){
            q = q->next;
        }
        (*q).next = newRibRow;
    }

    fin.close();

    int componentsArray[100000] = {0};
    int componentsCount = 0;
    bool isBurn[100000] = {false};

    searchComponents(adjacencyArray, componentsArray, isBurn, componentsCount, n);

    fOut << componentsCount << "\n";
    for (int i = 0; i < n; i++)
        fOut << componentsArray[i] << " ";

    fOut.clear();

    return 0;
}