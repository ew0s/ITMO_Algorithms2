#include <vector>
#include <iostream>


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
    int capacity;
    std::string text;
    std::cin >> capacity >> text;

    std::vector <std::vector <int>> statements (text.size() + 1, std::vector <int> (capacity, 0));
    std::vector <int> prefixes = computeLPS(text);

    for (int i = 0; i < text.size() + 1; i++)
    {
        for (char letter = 'a'; letter < 'a' + capacity; letter++)
        {
            if (i > 0 && letter != text[i])
                statements[i][letter - 'a'] = statements[prefixes[i - 1]][letter - 'a'];

            else
                statements[i][letter - 'a'] = i + (letter == text[i]);
        }
    }

    for (const auto& condition : statements)
    {
        for (auto input : condition)
        {
            std::cout << input << ' ';
        }
        std::cout << "\n";
    }

    return 0;
}