#include "../detail/type_half.hpp"

namespace glm
{
	GLM_FUNC_QUALIFIER uint16 packHalf(float Scalar)
	{
		return detail::toFloat16(Scalar);
	}

	GLM_FUNC_QUALIFIER float unpackHalf(uint16 Packed)
	{
		return detail::toFloat32(Packed);
	}
}//namespace glm
