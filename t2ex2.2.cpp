#include <iostream>

int main()
{
	std::cout << "x = ";
	double x;

	while(true)
	{
		std::cin >> x;
		if(std::cin.fail() || x == -1)
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			break;
		}

		std::cout << "Incorrect input or x == -1, repeat the input: ";
	}

	double sum{};
	int m{};
	
	do
	{
		sum += (x - 1) / ((m + 1) * (x + 1));
		++m;
	}while(m <= 10);
	
	std::cout << "sum = " << sum << "\n";
	
	return 0;
}