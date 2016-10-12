#include <iostream>
#include <vector>
#include <cmath>

void ssort(std::vector<double> &v);
void segments(std::vector<double> v);

int main()
{
	size_t N;
	std::vector<double> v = {};
	std::cin >> N;
	if (N == 0)
		std::cout << "0" << std::endl;
	else
	{
		for (size_t i = 0; i < N; ++i)
		{
			double X;
			std::cin >> X;
			v.push_back(X);
		}
		ssort(v);
		segments(v);
	}
	//system("pause");
	return 0;
}

void ssort(std::vector<double> &v)
{
	for (size_t i = 0; i < v.size() - 1; ++i)
	{
		double min = v[i];
		for (size_t j = i; j < v.size(); ++j)
				if (v[j] < min)
				{
					min = v[j];
					v[j] = v[i];
					v[i] = min;
				}
	}
	std::vector<double> v_sort = {};
	v_sort.push_back(v[0]);
	for (size_t i = 1; i < v.size(); ++i)
	{
		bool r = true;
		for (size_t k = 0; k < v_sort.size(); ++k)
			if (v[i] == v_sort[k])
			{
				r = false;
				break;
			}
		if (r)
			v_sort.push_back(v[i]);
	}
	v.clear();
	v = v_sort;
}
void segments(std::vector<double> v)
{
	size_t count = 1;
	double len = v[0] + 1;
	for (size_t i = 1; i < v.size(); ++i)
		if (v[i] > len)
		{
			++count;
			len = v[i] + 1;
		}
	std::cout << count << std::endl;
}