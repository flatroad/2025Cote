#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

struct GameInfo
{
	GameInfo(const std::vector<int>& numberList, int* calcMark, int maxRound)
		: numberList_(numberList)
	{
		memcpy(this->calcMark_, calcMark, sizeof(int) * 4);
		this->maxRound_ = maxRound;
		this->maxNum_ = -2147483648;
		this->minNum_ = 2147483647;

	};
	const std::vector<int>& numberList_;
	int calcMark_[4];
	int maxRound_ = 0;
    int maxNum_ = 0;
	int minNum_ = 0;
};

void calcRepeat(GameInfo& gInfo, int round, int answer)
{
	if (round == gInfo.maxRound_)
	{
		gInfo.maxNum_ = std::max(answer, gInfo.maxNum_);
		gInfo.minNum_ = std::min(answer, gInfo.minNum_);
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (gInfo.calcMark_[i] > 0)
		{
			gInfo.calcMark_[i] = gInfo.calcMark_[i] - 1;
			if (i == 0)
			{
				calcRepeat(gInfo, round + 1, answer + gInfo.numberList_[round]);
			}
			if (i == 1)
			{
				calcRepeat(gInfo, round + 1, answer - gInfo.numberList_[round]);
			}
			if (i == 2)
			{
				calcRepeat(gInfo, round + 1, answer * gInfo.numberList_[round]);
			}
			if (i == 3)
			{
				calcRepeat(gInfo, round + 1, (answer < 0 ? -(-answer / gInfo.numberList_[round]) : answer / gInfo.numberList_[round]));
			}
			gInfo.calcMark_[i] = gInfo.calcMark_[i] + 1;
		}
	}
	return;
}

int main()
{
	int N;
	std::cin >> N;
	std::cin.get();

	std::vector<int> numberList;
	int calcMark[4] = { 0, 0, 0, 0 };
	std::string s = "";
	std::getline(std::cin, s);
	std::stringstream ss(s);
	for (int i = 0; i < N; ++i)
	{
		int num;
		ss >> num;
		numberList.push_back(num);
	}
	s = "";
	std::getline(std::cin, s);
	ss.clear();
	ss.str(s);
	for (int i = 0; i < 4; ++i)
	{
		int num;
		ss >> num;
		calcMark[i] = num;
	}
	GameInfo gInfo(numberList, calcMark, N);
	calcRepeat(gInfo, 1, numberList[0]);
	std::cout << gInfo.maxNum_ << std::endl;
	std::cout << gInfo.minNum_ << std::endl;
	return (0);
}