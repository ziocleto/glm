#include <glm/ext/scalar_constants.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/ext/vector_packing.hpp>
#include <glm/ext/vector_ulp.hpp>
#include <glm/ext/vector_float1.hpp>
#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>
#include <vector>

template <glm::length_t L, glm::qualifier Q>
static int test_half()
{
	typedef glm::vec<L, glm::uint16, Q> vecUType;
	typedef glm::vec<L, int, Q> vecIType;
	typedef glm::vec<L, float, Q> vecFType;

	float const Epsilon = 0.01f;

	int Error = 0;

	struct test
	{
		test(vecFType const& Data, vecIType const& ULPs)
			: Data(Data)
			, ULPs(ULPs)
		{}

		vecFType Data;
		vecIType ULPs;
	};

	std::vector<test> Tests;
	Tests.push_back(test(vecFType(1.0f), vecIType(0)));
	Tests.push_back(test(vecFType(0.0f), vecIType(0)));
	Tests.push_back(test(vecFType(2.0f), vecIType(0)));
	Tests.push_back(test(vecFType(0.1f), vecIType(3277)));
	Tests.push_back(test(vecFType(0.5f), vecIType(0)));
	Tests.push_back(test(vecFType(-0.9f), vecIType(1638)));

	for(std::size_t i = 0; i < Tests.size(); ++i)
	{
		vecFType const Data = Tests[i].Data;

		vecUType const p0 = glm::packFloatToHalf(Data);

		vecFType const v0 = glm::unpackHalfToFloat(p0);
		Error += glm::all(glm::equal(v0, Data, Epsilon)) ? 0 : 1;

		vecUType const p1 = glm::packFloatToHalf(v0);
		Error += glm::all(glm::equal(p0, p1)) ? 0 : 1;

		vecFType const v1 = glm::unpackHalfToFloat(p1);
		Error += glm::all(glm::equal(v1, Data, Epsilon)) ? 0 : 1;

		vecIType const ULPs = glm::float_distance(Data, v0);
		Error += glm::all(glm::equal(ULPs, Tests[i].ULPs)) ? 0 : 1;
	}

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_half<1, glm::defaultp>();
	Error += test_half<2, glm::defaultp>();
	Error += test_half<3, glm::defaultp>();
	Error += test_half<4, glm::defaultp>();

	Error += test_half<1, glm::lowp>();
	Error += test_half<2, glm::lowp>();
	Error += test_half<3, glm::lowp>();
	Error += test_half<4, glm::lowp>();

	Error += test_half<1, glm::mediump>();
	Error += test_half<2, glm::mediump>();
	Error += test_half<3, glm::mediump>();
	Error += test_half<4, glm::mediump>();

	Error += test_half<1, glm::highp>();
	Error += test_half<2, glm::highp>();
	Error += test_half<3, glm::highp>();
	Error += test_half<4, glm::highp>();

	return Error;
}
