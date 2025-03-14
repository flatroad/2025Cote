#include <iostream>
#include <vector>
#include <string>
#include <sstream>

size_t CalcTotalPay(const std::vector<size_t>& distance, const std::vector<size_t>& oilPrice, size_t cityCount)
{
    size_t totalPrice = 0;
    size_t nowPrice = 2147483647;
    for (size_t i = 0; i < cityCount - 1; ++i)
    {
        nowPrice = std::min(nowPrice, oilPrice[i]);
        totalPrice = totalPrice + (distance[i] * nowPrice);
    }
    return (totalPrice);
}

int main()
{
    size_t cityCount;
    std::cin >> cityCount;
    std::vector<size_t> distance;
    std::vector<size_t> oilPrice;

    std::cin.get();
    std::string str;
    std::getline(std::cin, str);
    std::stringstream ss(str);
    for (size_t i = 0; i < cityCount - 1; ++i)
    {
        size_t dist;
        ss >> dist;
        distance.push_back(dist);
    }

    ss.clear();
    str = "";
    std::getline(std::cin, str);
    ss.str(str);
    for (size_t i = 0; i < cityCount; ++i)
    {
        size_t price;
        ss >> price;
        oilPrice.push_back(price);
    }
    size_t answer = CalcTotalPay(distance, oilPrice, cityCount);

    std::cout << answer << std::endl;

    return (0);
}