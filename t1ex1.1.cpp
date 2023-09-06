#include <iostream>

int main()
{
	std::cout << "X = ";
	double x, y;
	std::cin >> x;
	
	if(x <= -6)
	{
		y = - x - 2;
	}
	else if(x > -6 && x <= 0)
	{
		y = 4;
	}
	else
	{
		y = 2.0 / 3 * x - 4;
	}
	
	std::cout << "Y = " << y << "\n";
	
	return 0;
}