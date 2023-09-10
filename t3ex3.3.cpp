#include <iostream>
#include <string>
#include <utility>
#include <regex>

int main()
{
	std::string str_pr{"hello my friend"};
	
	std::cout << "Enter the string: ";
	std::string str_in;
	std::getline(std::cin, str_in);
	
	std::string str{};
	if(str_pr.size() < str_in.size())
	{
		str += std::move(str_pr) + " " + std::move(str_in);
	}
	else
	{
		str += std::move(str_in) + " " + std::move(str_pr);
	}
	
	std::cout << str << "\n";
	
	//работа с методами строк
	str = " " + str + " ";
	std::size_t index{}, i{};
	while((i = str.find(" ")) != std::string::npos)
	{
		str.replace(i, 1, "$");
		if(i - index == 2)
		{
			str.replace(index, 3, "$");
		}
		else
			index = i;
	}
	
	while((i = str.find("$")) != std::string::npos)
	{
		str.replace(i, 1, " ");
	}
	
	str.erase(0, 1);
	str.erase(str.size() - 1, 1);
	
	std::cout << str << "\n";
	
	//альтернативный вариант с регулярными выражениями
//	str_pr.clear();
//	std::regex rx(" .{1} ");
//	str_pr = std::regex_replace(str, rx, " ");
//	std::cout << str_pr << "\n";
	//конец альтернативныого варианта
	
	return 0;
}