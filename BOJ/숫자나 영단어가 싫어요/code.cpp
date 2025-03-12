#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    std::string str = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            str.push_back(s[i]);
        }
        else if (s[i] == 'z')
        {
            str.push_back('0');
            i = i + 3;
        }
        else if (s[i] == 'o')
        {
            str.push_back('1');
            i = i + 2;
        }
        else if (s[i] == 't')
        {
            if (s[i + 1] == 'w')
            {
                str.push_back('2');
                i = i + 2;
            }
            else 
            {
                str.push_back('3');
                i = i + 4;
            }
        }
        else if (s[i] == 'f')
        {
            if (s[i + 1] == 'o')
            {
                str.push_back('4');
            }
            else
            {
                str.push_back('5');

            }
            i = i + 3;
        }
        else if (s[i] == 's')
        {
            if (s[i + 1] == 'i')
            {
                str.push_back('6');
                i = i + 2;
            }
            else
            {
                str.push_back('7');
                i = i + 4;
            }
        }
        else if (s[i] == 'e')
        {
            str.push_back('8');
            i = i + 4;
        }
        else
        {
            str.push_back('9');
            i = i + 3;
        }
    }
    return stoi(str);
}