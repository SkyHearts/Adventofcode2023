#include <iostream>
#include <string>
#include <fstream>
#include <climits>

std::string arr[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
	std::fstream file;
	std::string line;
	int i = 0;
	file.open("input.txt", std::ios::in);
	if (!file)
		std::cout << "File not found" << std::endl;
	while(getline(file, line)){
		std::string num;
		i += std::stoi(num);
	}
	std::cout << i << std::endl;
}