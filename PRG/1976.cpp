#include <iostream>

#define MAX_CITY 200

int findRoot(int* arr, int cityNum)
{
    if (arr[cityNum] == cityNum)
        return (cityNum);
    else
    {
        return (arr[cityNum] = findRoot(arr, arr[cityNum]));
    }
}

int main()
{
    int arr[MAX_CITY];
    int N, M;
    std::cin >> N;
    std::cin.get();
    std::cin >> M;
    std::cin.get();
    for (int i = 0; i < N; ++i)
    {
        arr[i] = i;
    }
    for (int i = 0; i < N; ++i)
    {
        int ir = findRoot(arr, i);
        for (int j = 0; j < N; ++ j)
        {
            int visit;
            std::cin >> visit;
            if (visit == 0)
                continue ;
            int jr = findRoot(arr, j);
            if (ir == jr)
            {
                continue ;
            }
            else
            {
                arr[jr] = ir;
            }
        }
        std::cin.get();
    }

    int visit;
    std::cin >> visit;
    int r = findRoot(arr, visit - 1);
    for (int i = 1; i < M; ++i)
    {
        int vst;
        std::cin >> vst;
        int ir = findRoot(arr, vst - 1);
        if (r != ir)
        {
            std::cout << "NO" << std::endl;
            return (0);
        }
        r = ir;
    }
    std::cout << "YES" << std::endl;
    return (0);
}