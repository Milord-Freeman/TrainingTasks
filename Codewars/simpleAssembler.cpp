//https://www.codewars.com/kata/58e24788e24ddee28e000053/train/cpp

#include <string>
#include <unordered_map>
#include <sstream>

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
	std::unordered_map<std::string, int> regs = {};
	int currentInstruction = 0;
	while (currentInstruction < program.size())
	{
		std::istringstream iss(program.at(currentInstruction));
		std::vector<std::string> instructions{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };

		if (instructions.at(0) == "mov")
		{
			regs[instructions.at(1)] = (regs.find(instructions.at(2)) != regs.end()) ? regs[instructions.at(2)] : std::stoi(instructions.at(2));
		}
		else if (instructions.at(0) == "jnz")
		{
			if (instructions.at(1) != "0" && (regs.find(instructions.at(1)) != regs.end()) ? (regs[instructions.at(1)] != 0) : true) // I don't like that
			{
				currentInstruction += (regs.find(instructions.at(2)) != regs.end()) ? regs[instructions.at(2)] : std::stoi(instructions.at(2));
				continue;
			}
		}
		else if (instructions.at(0) == "inc")
		{
			if (regs.find(instructions.at(1)) != regs.end())
			{
				regs[instructions.at(1)]++;
			}
		}
		else if (instructions.at(0) == "dec")
		{
			if (regs.find(instructions.at(1)) != regs.end())
			{
				regs[instructions.at(1)]--;
			}
		}
		currentInstruction++;
	}
	return regs;
}