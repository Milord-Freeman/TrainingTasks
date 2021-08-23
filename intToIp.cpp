//https://www.codewars.com/kata/52e88b39ffb6ac53a400022e/train/cpp

#include <string>

std::string uint32_to_ip(const uint32_t ip)
{
	return std::to_string((ip & 0xFF000000) >> 24) + "." + std::to_string((ip & 0xFF0000) >> 16) + "." + std::to_string((ip & 0xFF00) >> 8) + "." + std::to_string(ip & 0xFF);
}