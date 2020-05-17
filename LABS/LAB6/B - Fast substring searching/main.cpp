#include <vector>
#include <fstream>


std::vector <int> computeLPS (std::string txt);


std::vector <int> KMP_Search (std::string text, std::string pattern)
{
    std::vector <int> prefixes = computeLPS(pattern);
    std::vector <int> idxes;
    int i = 0;
    int j = 0;

    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == pattern.size())
        {
            idxes.push_back(i - j);
            j = prefixes[j - 1];
        }

        else if (i < text.size() && text[i] != pattern[j])
        {
            if (j != 0)
                j = prefixes[j - 1];
            else
                i++;
        }
    }

    return idxes;
}


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
    std::ifstream fin ("search2.in");
    std::ofstream fOut ("search2.out");

    std::string pattern;
    std::string text;
    fin >> pattern >> text;
    fin.close();

    std::vector <int> idxes = KMP_Search(text, pattern);

    fOut << idxes.size() << "\n";
    for (auto idx : idxes)
        fOut << idx + 1 << ' ';
    fOut.close();
    return 0;
}
