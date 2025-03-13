#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    for (int i = 0; i < query.size(); ++i) 
    {
        int q = query[i];
        if (!(i & 1)) 
        {
            arr.resize(q + 1);
        }
        else
        {
            arr.erase(arr.begin(), arr.begin() + q);
        }
    }
    return arr;
}