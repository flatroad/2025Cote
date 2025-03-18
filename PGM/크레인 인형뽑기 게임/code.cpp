#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int height = board.size();
    int width = board[0].size();
    stack<int> answer;
    vector<queue<int>> bd(width);
    for (vector<int> wdboard : board)
    {
        for (int i = 0; i < width; ++i)
        {
            if (wdboard[i] != 0)
            {
                bd[i].push(wdboard[i]);
            }
        }
    }
    int count = 0;
    for (int k : moves)
    {
        if (!bd[k - 1].empty())
        {
            count = count + 1;
            int pin = bd[k - 1].front();
            bd[k - 1].pop();
            if (!answer.empty() && answer.top() == pin)
            {
                answer.pop();
            }
            else
            {
                answer.push(pin);
            }
        }
    }
   
    return (count - answer.size());
}