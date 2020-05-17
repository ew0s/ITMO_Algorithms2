#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;


bool equal(string &main_str, string &sub_str, int start)
{
    for (int i = 0; i < sub_str.length(); i++)
        if (main_str[start + i] != sub_str[i])
            return false;

    return true;
}


vector <int> find_all_substrings (string &main_str, string &sub_str)
{
    int n = main_str.length();
    int m  = sub_str.length();
    vector <int> indexes;

    for (int i = 0; i <= n - m; i++)
    {
        if (equal(main_str, sub_str, i))
            indexes.push_back(i);
    }

    return indexes;
}


int main() {
    std::ifstream fin ("search1.in");
    std::ofstream fOut ("search1.out");

    string sub_str, main_str;
    fin >> sub_str >> main_str;
    fin.close();

    vector <int> answer = find_all_substrings(main_str, sub_str);

    fOut << answer.size() << "\n";
    for (int & it : answer)
        fOut << it + 1 << ' ';
    fOut.close();

    return 0;
}
