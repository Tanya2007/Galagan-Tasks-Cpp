#include <iostream>
#include <fstream>
#include <set>
#include <random>

struct Point
{
	int x{};
	int y{};
	int z{};
	
	friend bool operator < (const Point &p1, const Point &p2);
};

bool operator < (const Point &p1, const Point &p2)
{
	if(p1.x < p2.x)
		return true;
	else if(p1.x == p2.x)
	{
		if(p1.y < p2.y)
			return true;
		else if(p1.y == p2.y)
			return p1.z < p2.z; 
	}
	
	return false;
}

void generatePoint(std::set<Point> &set_point)
{
	auto myGenerate =
	    [](int start, int end) -> int
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(start, end);
		return distrib(rnd);
	};
	
	Point temp;
	std::size_t size_point{static_cast<std::size_t>(myGenerate(2000, 3000))};
	while(set_point.size() <= size_point)
	{
		temp.x = myGenerate(-10, 10);
		temp.y = myGenerate(-10, 10);
		temp.z = myGenerate(-10, 10);
		
		set_point.insert(temp);
	}
}

int main()
{
	//сгенерируем множество = 2000 - 3000 различных точек в пространстве
	//с координатами в диапазоне от -10 до 10
	std::set<Point> set_point;
	generatePoint(set_point);
	
	std::ofstream outf("t6ex6.2_point.txt");
	int i{1};
	for(const auto &elem : set_point)
	{
		std::cout << i << ".\t(" << elem.x << ",\t" << elem.y << ",\t" << elem.z << ")\n";
		++i;
		outf << elem.x << " " << elem.y << " " << elem.z << "\n";
	}
	outf.close();
	
	return 0;
}