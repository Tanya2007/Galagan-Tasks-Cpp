#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

struct Point
{
	int x{};
	int y{};
	int z{};
};

void calculationCoefficients(int &A, int &B, int &C, int &D, const std::vector<Point> &vec_point);
void readFile(const std::string &file_name, std::vector<Point> &vec_point);

int main()
{
	std::vector<Point> vec_point;
	readFile("t6ex6.2_point.txt", vec_point);

	int i{1};
	for(const auto &elem : vec_point)
	{
		std::cout << i << ".\t(" << elem.x << ",\t" << elem.y << ",\t" << elem.z << ")\n";
		++i;
	}

	//вычислим коэффициенты при x, y и z, а также свободный член
	//для составления уравнения плоскости в пространстве
	//по трем произвольным точкам вида Ax + By + Cz + D = 0;
	//проверим, все точки на принадлежность этой плоскости
	int A, B, C, D;
	calculationCoefficients(A, B, C, D, vec_point);
	
	std::cout << "Let's check all the points for belonging to the plane of the form:\n";
	std::cout << A << "x"; std::cout.setf(std::ios::showpos);
	std::cout << B << "y" << C << "z" << D << " = 0\n";
	std::cout.unsetf(std::ios::showpos);
	std::cout << "Points belonging to a given plane:\n";
	
	for (const auto &elem : vec_point)
	{
		if(A * elem.x + B * elem.y + C * elem.z + D == 0)
		{
			std::cout << "(" << elem.x << ",\t" << elem.y << ",\t" << elem.z << ")\n";
		}
	}
	
	return 0;
}

void readFile(const std::string &file_name, std::vector<Point> &vec_point)
{
	std::ifstream inf(file_name);
	Point temp;
	if(inf)
	{
		while(inf >> temp.x >> temp.y >> temp.z)
		{
			vec_point.push_back(temp);
		}
		inf.close();
	}
	else
	{
		std::cout << "Could not open the file: " << file_name << "\n";
	}
}

void calculationCoefficients(int &A, int &B, int &C, int &D, const std::vector<Point> &vec_point)
{
	auto myGenerate =
	    [&vec_point]() -> std::size_t
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(0, vec_point.size() - 1);
		return static_cast<std::size_t>(distrib(rnd));
	};
	
	const Point &_1 = vec_point[myGenerate()];
	const Point &_2 = vec_point[myGenerate()];
	const Point &_3 = vec_point[myGenerate()];
	
	A = (_2.y - _1.y) * (_3.z - _1.z) - (_2.z - _1.z) * (_3.y - _1.y);
	B = (_2.z - _1.z) * (_3.x - _1.x) - (_2.x - _1.x) * (_3.z - _1.z);
	C = (_2.x - _1.x) * (_3.y - _1.y) - (_2.y - _1.y) * (_3.x - _1.x);
	D = - A * _1.x - B * _1.y - C * _1.z;
	
	while((A % 2 == 0) && (B % 2 == 0) && (C % 2 == 0) && (D % 2 == 0))
	{
		A /= 2;
		B /= 2;
		C /= 2;
		D /= 2;
	}
	
	if(A < 0 )
	{
		A = -A;
		B = -B;
		C = -C;
		D = -D;
	}
}