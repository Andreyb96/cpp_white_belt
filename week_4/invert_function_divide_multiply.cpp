#include <cassert>
#include <map>

class Function
{
public:
	void AddPart(char operation, double num)
	{
		_operations.insert({ operation, num });
	}

	double Apply(double num)
	{
		auto result = num;
		for (auto operation : _operations)
		{
			if (operation.first == '+')
			{
				result += operation.second;
			}
			else if (operation.first == '-')
			{
				result -= operation.second;
			}
			else if (operation.first == '*')
			{
				result *= operation.second;
			}
			else
			{
				result /= operation.second;
			}
		}
		return result;
	}

	void Invert()
	{
		std::map<char, double> operations;
		for (auto operation : _operations)
		{
			if (operation.first == '+')
			{
				operations.insert({ '-', operation.second });
			}
			else if (operation.first == '-')
			{
				operations.insert({ '+', operation.second });
			}
			else if (operation.first == '*')
			{
				operations.insert({ '/', operation.second });
			}
			else
			{
				operations.insert({ '*', operation.second });
			}
		}
		_operations = operations;
	}
private:
	std::map<char, double> _operations;
};

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

Function MakeWeightFunction(const Params& params,
	const Image& image) {
	Function function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
	const Image& image,
	double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

int main() {
	Image image = { 10, 2, 6 };
	Params params = { 4, 2, 6 };
	assert(ComputeImageWeight(params, image) == 72);
	assert(ComputeQualityByWeight(params, image, 52) == 5);
	return 0;
}