//https://www.codewars.com/kata/55c6126177c9441a570000cc/train/cpp
#include <set>
#include <string>
#include <map>
#include <sstream>

class WeightSort
{
public:
	static std::string orderWeight(const std::string& strng);
};

int getSummOfString(const std::string& testString)
{
	int result = 0;
	for (auto& currentChar : testString)
	{
		result += currentChar - '0';
	}
	return result;
}

std::string WeightSort::orderWeight(const std::string& strng)
{
	std::string result = {};
	std::map<int, std::multiset<std::string>> priorityMap = {};

	std::stringstream inputStream(strng);
	std::multiset<std::string> myStringsNumbers = std::multiset<std::string>(std::istream_iterator<std::string>(inputStream), std::istream_iterator<std::string>());

	for (auto currentNumber : myStringsNumbers)
	{
		int summ = getSummOfString(currentNumber);
		priorityMap[summ].insert(currentNumber);
	};

	for (auto& currentPair : priorityMap)
	{
		for (auto& currentString : currentPair.second)
		{
			result += currentString;
			result += " ";
		}
	}
	if (!result.empty())
	{
		result.pop_back();
	}
	return result;
}