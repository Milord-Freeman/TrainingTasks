//https://www.codewars.com/kata/513e08acc600c94f01000001/train/cpp
#include <iomanip>
#include <sstream>

class RGBToHex
{
public:
	static std::string rgb(int r, int g, int b);
};

int roundTo(int number)
{
	return number < 0 ? 0 : (number > 255 ? 255 : number);
}

std::string RGBToHex::rgb(int r, int g, int b)
{
	std::stringstream buffer;
	buffer << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << roundTo(r);
	buffer << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << roundTo(g);
	buffer << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << roundTo(b);
	return buffer.str();
}