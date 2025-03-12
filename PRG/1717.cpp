#include <iostream>
#include <vector>

int findHead(std::vector<int> &vec, int i)
{
    if (vec[i] == i)
    {
        return (i);
    }
    else
    {
        return vec[i] = findHead(vec, vec[i]);
    }
}

int main()
{
    std::cin.tie(0);
	std::cin.sync_with_stdio(false);
	std::ios_base::sync_with_stdio(false);
    std::vector<int> vec;
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::cin.get();

    for (int i = 0; i <= n; ++i)
    {
        vec.push_back(i);
    }

    for (int i = 0; i < m; ++i)
    {
        int flag, a, b;
        std::cin >> flag;
        std::cin >> a;
        std::cin >> b;
        std::cin.get();
        if (a == b)
        {
            if (flag == 1)
                std::cout << "YES" << '\n';
            continue ;
        }
        int ah = findHead(vec, a);
        int bh = findHead(vec, b);
        if (flag == 0)
        {
            if (ah < bh)
            {
                vec[bh] = ah;
            }
            else
            {
                vec[ah] = bh;
            }
        }
        else
        {
            if (ah == bh)
                std::cout << "YES" << '\n';
            else
                std::cout << "NO" << '\n';
        }
    }
}