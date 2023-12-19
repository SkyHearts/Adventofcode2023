#include <iostream>
#include <string>
#include <fstream>
#include <climits>

std::string arr[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

char find_first(std::string line)
{
	std::string num;
	int str_i = INT_MAX;
	for (int k = 0; k < 9; k++){
		int tmp_i;
		if ((tmp_i = line.find(arr[k])) != std::string::npos){
			if (str_i > tmp_i) {
				str_i = tmp_i;
				num = arr[k];
			}
		}
	}
	int i = line.find_first_of("0123456789");
	if (str_i < i){
		for (int k = 0; k < 10; k++){
			if (num == arr[k])
				return k + 48 + 1;
		}
	}
	return line[i];
}

char find_last(std::string line)
{
	std::string num;
	int str_i = -1;
	for (int k = 0; k < 9; k++){
		int tmp_i;
		if ((tmp_i = line.rfind(arr[k])) != std::string::npos){
			if (str_i < tmp_i) {
				str_i = tmp_i;
				num = arr[k];
			}
		}
	}
	int i = line.find_last_of("0123456789");
	if (str_i > i){
		for (int k = 0; k < 10; k++){
			if (num == arr[k]){
				return k + 48 + 1;
			}
		}
	}
	return line[i];
}

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
		num.append(1, find_first(line));
		num.append(1, find_last(line));
		i += std::stoi(num);
	}
	std::cout << i << std::endl;
}