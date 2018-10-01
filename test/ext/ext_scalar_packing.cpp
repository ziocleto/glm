#include <glm/ext/scalar_int_sized.hpp>
#include <glm/ext/scalar_packing.hpp>
#include <glm/ext/scalar_relational.hpp>
#include <vector>

static int test_half()
{
	int Error = 0;

	std::vector<float> Tests;
	Tests.push_back(0.0f);
	Tests.push_back(1.0f);
	Tests.push_back(-1.0f);
	Tests.push_back(2.0f);
	Tests.push_back(-2.0f);
	Tests.push_back(1.9f);

	for(std::size_t i = 0; i < Tests.size(); ++i)
	{
		glm::uint16 p0 = glm::packFloatToHalf(Tests[i]);
		float v0 = glm::unpackHalfToFloat(p0);
		Error += glm::equal(v0, Tests[i], 0.01f) ? 0 : 1;

		glm::uint16 p1 = glm::packFloatToHalf(v0);
		float v1 = glm::unpackHalfToFloat(p1);
		Error += glm::equal(v1, Tests[i], 0.01f) ? 0 : 1;

		Error += glm::equal(v0, v1, 0) ? 0 : 1;
	}

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_half();

	return Error;
}
