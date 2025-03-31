#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

using umStrInt = unordered_map<string, int>;

vector<int> find_answer(const vector<string> &gems, umStrInt &jewelsCount)
{
    vector<int> answer{0, 0};
    deque<pair<string, int>> searchAns;
    int jewelTypeCount = jewelsCount.size();
    int answerListLen = 2147483647;
    int eachJewelHave = 0;

    for (int i = 0; i < gems.size(); ++i)
    {
        string jewel = gems[i];

        if (!searchAns.empty() && searchAns.front().first == jewel)
        {
            searchAns.pop_front();

            while (!searchAns.empty() && jewelsCount[searchAns.front().first] >= 2)
            {
                jewelsCount[searchAns.front().first] = jewelsCount[searchAns.front().first] - 1;
                searchAns.pop_front();
            }
        }
        else
        {
            if (jewelsCount[jewel] == 0)
            {
                eachJewelHave = eachJewelHave + 1;
            }

            jewelsCount[jewel] = jewelsCount[jewel] + 1;
        }

        pair<string, int> part = make_pair(jewel, i);
        searchAns.push_back(part);

        if (eachJewelHave == jewelTypeCount && answerListLen > searchAns.size())
        {
            answerListLen = searchAns.size();
            answer[0] = searchAns.begin()->second + 1;
            answer[1] = (--searchAns.end())->second + 1;
        }
    }
    
    return (answer);
}

vector<int> solution(vector<string> gems) 
{
    umStrInt jewelsCount;
    
    for (string s : gems)
    {
        jewelsCount[s] = 0;
    }
    
    return find_answer(gems, jewelsCount);
}