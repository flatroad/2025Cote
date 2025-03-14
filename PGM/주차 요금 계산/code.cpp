#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <map>

struct feePolicy
{
    static void init(int a, int b, int c, int d)
    {
        feePolicy::basicTime = a;
        feePolicy::basicPay = b;
        feePolicy::overTime = c;
        feePolicy::overPay = d;
    }
    static int basicTime;
    static int basicPay;
    static int overTime;
    static int overPay;
};

int feePolicy::basicTime = 0;
int feePolicy::basicPay = 0;
int feePolicy::overTime = 0;
int feePolicy::overPay = 0;

int TransTime(int h, int m)
{
    return ((h * 60) + m);
}

void SystemRecord(std::unordered_map<int, int>& unmap, std::map<int, int>& timeRecord, const std::string& s)
{
    std::stringstream ss(s);
    int h, m, carNum;
    char c;
    ss >> h >> c >> m >> carNum;
    h = TransTime(h, m);
    
    if (timeRecord.find(carNum) == timeRecord.end())
    {
        timeRecord[carNum] = 0;
    }
    
    if (unmap.find(carNum) != unmap.end())
    {
        int inTime = unmap[carNum];
        int useH = h - inTime;
        timeRecord[carNum] = timeRecord[carNum] + useH;
        unmap.erase(carNum);    
    }
    else
    {
        unmap[carNum] = h;
    }
}

void CalcPay(std::map<int, int>& timeRecord, std::vector<int>& answer)
{
    for (std::map<int, int>::iterator it = timeRecord.begin(); it != timeRecord.end(); ++it)
    {
        int useTime = it->second;
        useTime = std::max(0, useTime - feePolicy::basicTime);
        
        int count = (useTime / feePolicy::overTime) + (useTime % feePolicy::overTime ? 1 : 0);
        answer.push_back(feePolicy::basicPay + (count * feePolicy::overPay));
    }
}

std::vector<int> solution(std::vector<int> fees, std::vector<std::string> records) 
{ 
    const int maxTime = TransTime(23, 59); 
    std::unordered_map<int, int> unmap;
    std::map<int, int> timeRecord;
    std::vector<int> answer;
    feePolicy::init(fees[0], fees[1], fees[2], fees[3]);
    for (std::string s : records)
    {
        SystemRecord(unmap, timeRecord, s);
    }
    
    for (std::unordered_map<int, int>::iterator it = unmap.begin(); it != unmap.end(); ++it)
    {
        int carNum = it->first;
        int inTime = it->second;
        int useTime = maxTime - inTime;
        timeRecord[carNum] = timeRecord[carNum] + useTime;
    }
    CalcPay(timeRecord, answer);
    return answer;
}