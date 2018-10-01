#include "../detail/type_half.hpp"

namespace glm{
namespace detail
{
	template<length_t L, qualifier Q>
	struct compute_half
	{};

	template<qualifier Q>
	struct compute_half<1, Q>
	{
		GLM_FUNC_QUALIFIER static vec<1, uint16, Q> pack(vec<1, float, Q> const& v)
		{
			int16 const Unpack(detail::toFloat16(v.x));
			vec<1, uint16, Q> Packed;
			memcpy(&Packed, &Unpack, sizeof(Packed));
			return Packed;
		}

		GLM_FUNC_QUALIFIER static vec<1, float, Q> unpack(vec<1, uint16, Q> const& v)
		{
			vec<1, int16, Q> Unpack;
			memcpy(&Unpack, &v, sizeof(Unpack));
			return vec<1, float, Q>(detail::toFloat32(v.x));
		}
	};

	template<qualifier Q>
	struct compute_half<2, Q>
	{
		GLM_FUNC_QUALIFIER static vec<2, uint16, Q> pack(vec<2, float, Q> const& v)
		{
			vec<2, int16, Q> const Unpack(detail::toFloat16(v.x), detail::toFloat16(v.y));
			vec<2, uint16, Q> Packed;
			memcpy(&Packed, &Unpack, sizeof(Packed));
			return Packed;
		}

		GLM_FUNC_QUALIFIER static vec<2, float, Q> unpack(vec<2, uint16, Q> const& v)
		{
			vec<2, int16, Q> Unpack;
			memcpy(&Unpack, &v, sizeof(Unpack));
			return vec<2, float, Q>(detail::toFloat32(v.x), detail::toFloat32(v.y));
		}
	};

	template<qualifier Q>
	struct compute_half<3, Q>
	{
		GLM_FUNC_QUALIFIER static vec<3, uint16, Q> pack(vec<3, float, Q> const& v)
		{
			vec<3, int16, Q> const Unpack(detail::toFloat16(v.x), detail::toFloat16(v.y), detail::toFloat16(v.z));
			vec<3, uint16, Q> Packed;
			memcpy(&Packed, &Unpack, sizeof(Packed));
			return Packed;
		}

		GLM_FUNC_QUALIFIER static vec<3, float, Q> unpack(vec<3, uint16, Q> const& v)
		{
			vec<3, int16, Q> Unpack;
			memcpy(&Unpack, &v, sizeof(Unpack));
			return vec<3, float, Q>(detail::toFloat32(v.x), detail::toFloat32(v.y), detail::toFloat32(v.z));
		}
	};

	template<qualifier Q>
	struct compute_half<4, Q>
	{
		GLM_FUNC_QUALIFIER static vec<4, uint16, Q> pack(vec<4, float, Q> const& v)
		{
			vec<4, int16, Q> const Unpack(detail::toFloat16(v.x), detail::toFloat16(v.y), detail::toFloat16(v.z), detail::toFloat16(v.w));
			vec<4, uint16, Q> Packed;
			memcpy(&Packed, &Unpack, sizeof(Packed));
			return Packed;
		}

		GLM_FUNC_QUALIFIER static vec<4, float, Q> unpack(vec<4, uint16, Q> const& v)
		{
			vec<4, int16, Q> Unpack;
			memcpy(&Unpack, &v, sizeof(Unpack));
			return vec<4, float, Q>(detail::toFloat32(v.x), detail::toFloat32(v.y), detail::toFloat32(v.z), detail::toFloat32(v.w));
		}
	};
}//namespace detail

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, uint16, Q> packFloatToHalf(vec<L, float, Q> const& v)
	{
		return detail::compute_half<L, Q>::pack(v);
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, float, Q> unpackHalfToFloat(vec<L, uint16, Q> const& v)
	{
		return detail::compute_half<L, Q>::unpack(v);
	}
}//namespace glm
