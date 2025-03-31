#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    size_t maxLen = 0;
    for (int i = 0; i < 5; ++i)
    {
        string word = "";
        getline(cin, word);
        words.push_back(word);
        maxLen = max(words[i].size(), maxLen);
    }
    for (int i = 0; i < 5; ++i)
    {
        int neenCount = maxLen - words[i].size();
        for (int j = 0; j < neenCount; ++j)
        {
            words[i].push_back(' ');
        }
    }
    string answer = "";
    for (int i = 0; i < maxLen; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (words[j][i] != ' ')
            {
                answer.push_back(words[j][i]);
            }
        }
    }
    cout << answer << endl;
    return (0);
}
