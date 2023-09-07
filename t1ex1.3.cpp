#include <iostream>

int main()
{
	std::cout << "x = ";
	double x;
	std::cin >> x;
	
	std::cout << "y = ";
	double y;
	std::cin >> y;
	
	bool hits_target{false};
	
	if(x >= -2 && x <= 0)
	{
		if(y >= 0 && y <= 2)
		{
			if((x * x + y * y >= 1) && (x * x + y * y <= 4))
			{
				hits_target = true;
			}
		}
		else if(y >= -2 && y < 0)
		{
			if((x * x + y * y >= 1) && (y >= - x - 2))
			{
				hits_target = true;
			}
		}
	}
	else if(x > 0 && x <= 2)
	{
		if(y >= -2 && y <= 0)
		{
			if((x * x + y * y >= 1) && (x * x + y * y <= 4))
			{
				hits_target = true;
			}
		}
		else if(y > 0 && y <= 2)
		{
			if((x * x + y * y >= 1) && (y <= - x + 2))
			{
				hits_target = true;
			}
		}
	}
	
	if(hits_target)
		std::cout << "The dot (" << x << ", " << y << ") hits the target.\n";
	else
		std::cout << "The dot (" << x << ", " << y << ") misses the target.\n";
	
	return 0;
}