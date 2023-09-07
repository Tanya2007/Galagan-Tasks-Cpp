#include <iostream>
#include <cmath>

int main()
{
	double t{1.};
	const double delta_t{0.5};
	const double a{2.5};
	
	double y;
	
	while(t <= 5.)
	{
		if(t < a)
		{
			y = (1 / std::exp(a * t)) * std::cos(a * t);
		}
		else if(t == a)
		{
			y = t * std::sin(a * t);
		}
		else
		{
			y = t * std::sqrt(t - a);
		}
		
		std::cout << "t = " << t << "\t\ty = " << y << "\n";
		
		t += delta_t;
	}
	
	return 0;
}