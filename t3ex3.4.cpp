#include <iostream>
#include <random>
#include <iomanip>

const int N{8};
void fillingMatrix(int matrix[][N]);
void matrixOutput(const int matrix[][N]);
void outMinSecondLine(const int matrix[][N]);
void multiplicationNegative(const int matrix[][N]);
void replacementSide(int matrix[][N]);

int main()
{
	int matrix[N][N];
	fillingMatrix(matrix);
	matrixOutput(matrix);
	outMinSecondLine(matrix);
	multiplicationNegative(matrix);
	replacementSide(matrix);
	matrixOutput(matrix);
	
	return 0;
}

void fillingMatrix(int matrix[][N])
{
	std::cout << "select the action: 1 - enter the matrix values from the keyboard, 2 - software generation of values: ";
	int action;
	bool action_no_correct{true};
	while(action_no_correct)
	{
		std::cin >> action;
		switch(action)
		{
			case 1:
				for(int i{}; i < N; ++i)
				{
					for(int j{}; j < N; ++j)
					{
						std::cin >> matrix[i][j];
					}
				}
				action_no_correct = false;
				break;

			case 2:
			{
				auto myGenerate =
				    []() -> int
				{
					std::random_device rd;
					std::mt19937 rnd(rd());
					std::uniform_int_distribution<int> distrib(-20, 20);
					return distrib(rnd);
				};

				for(int i{}; i < N; ++i)
				{
					for(int j{}; j < N; ++j)
					{
						matrix[i][j] = myGenerate();
					}
				}
				action_no_correct = false;
				break;
			}

			default:
				std::cout << "The choice is not correct. Try again: ";
				break;
		}
	}
}

void matrixOutput(const int matrix[][N])
{
	std::cout << "\n\n";
	for(int i{}; i < N; ++i)
	{
		for(int j{}; j < N; ++j)
		{
			std::cout <<  std::setw(5) << matrix[i][j] << " ";
		}
		std::cout << "\n\n";
	}
}

void outMinSecondLine(const int matrix[][N])
{
	for(int i{1}; i < N; i += 2)
	{
		int min{INT_MAX};
		for(int j{}; j < N; ++j)
		{
			if(matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
		}
		std::cout << "the minimum element in " << i + 1 << " line: " << min << "\n"; 
	}
}

void multiplicationNegative(const int matrix[][N])
{
	std::cout << "\n";
	long long multip(1);
	for(int i{0}; i < N; ++i)
	{
		for(int j{i + 1}; j < N; ++j)
		{
			if(matrix[i][j] < 0)
				multip *= matrix[i][j];
		}
	}
	std::cout << "multiplication of negative elements above the main diagonal: " << multip << "\n\n"; 
}

void replacementSide(int matrix[][N])
{
	int i{};
	int j{N - 1};
	while(i < N)
	{
		matrix[i][j] = 0;
		++i;
		--j;
	}
}