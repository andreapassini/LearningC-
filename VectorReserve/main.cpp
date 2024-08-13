#include "vector"
#include "iostream"
#include "string"

int main()
{
	std::vector<int> v1;
	v1.reserve(100);

	v1.push_back(1);
	v1.push_back(2);
	size_t newSize = 11;
	if (v1.size() < newSize)
		v1.resize(newSize);

	v1.insert(v1.begin() + 11, 11);
	v1.erase(v1.begin() + 1);

	std::cout << "Size: " << v1.size() << std::endl;
	
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << std::endl;
	}
}