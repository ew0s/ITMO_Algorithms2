#include <iostream>
#include <vector>
#include <fstream>


std::vector <int> computeLPS (std::string txt)
{
    std::vector <int> LPS (txt.size());
    LPS[0] = 0;
    int len = 0;
    int i = 1;

    while (i < txt.size())
    {
        if (txt[i] == txt[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }

        else
        {
            if (len > 0)
                len = LPS[len - 1];
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }

    return LPS;
}

int main()
{
    std::ifstream fin ("prefix.in");
    std::ofstream fOut ("prefix.out");

    std::string pattern;
    fin >> pattern;
    fin.close();

    std::vector <int> prefixes = computeLPS(pattern);

    for (auto prefix : prefixes)
        fOut << prefix << ' ';
    fOut.close();
    return 0;
}
