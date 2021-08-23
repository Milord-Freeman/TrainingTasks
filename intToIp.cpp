//https://www.codewars.com/kata/52e88b39ffb6ac53a400022e/train/cpp

#include <string>

std::string uint32_to_ip(const uint32_t ip)
{
	return std::to_string((ip >> 24) & 0xFF) + "." + std::to_string((ip >> 16) & 0xFF) + "." + std::to_string((ip >> 8) & 0xFF) + "." + std::to_string(ip & 0xFF);
}
