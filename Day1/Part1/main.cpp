#include <iostream>
#include <string>
#include <fstream>

char find_first(char const *line)
{
	char str[] = "0123456789";
	int i = 0;
	while (line[i]){
		int j = 0;
		while (str[j]){
			if (line[i] == str[j])
				return line[i];
			j++;
		}
		i++;
	}
	return 0;
}

char find_last(char const *line)
{
	char str[] = "0123456789";
	int i = strlen(line);
	while (i >= 0){
		int j = 0;
		while (str[j]){
			if (line[i] == str[j])
				return line[i];
			j++;
		}
		i--;
	}
	return 0;
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
		num.append(1, find_first(line.c_str()));
		std::cout << num << std::endl;
		num.append(1, find_last(line.c_str()));
		std::cout << num << std::endl;
		i += std::stoi(num);
	}
	std::cout << i << std::endl;
}