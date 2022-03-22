#include <cassert>

class Function
{
public:
	void AddPart(char operation, double num)
	{
		if (operation == '-')
		{
			_restValue -= num;
			return;
		}
		if (operation == '+')
		{
			_restValue += num;
			return;
		}
	}

	double Apply(double num)
	{
		return num + _restValue;
	}

	void Invert()
	{
		_restValue = -_restValue;
	}
private:
	double _restValue = 0.0;
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
	function.AddPart('-', image.freshness * params.a + params.b);
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
	assert(ComputeImageWeight(params, image) == 36);
	assert(ComputeQualityByWeight(params, image, 46) == 20);
	return 0;
}