/// @ref ext_vector_packing
/// @file glm/ext/vector_packing.hpp
///
/// @defgroup ext_vector_packing GLM_EXT_vector_packing
/// @ingroup ext
///
/// Exposes comparison functions for vector types that take a user defined epsilon values.
///
/// Include <glm/ext/vector_packing.hpp> to use the features of this extension.
///
/// @see core_packing

#pragma once

// Dependencies
#include "../detail/qualifier.hpp"
#include "../ext/scalar_uint_sized.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_packing extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_packing
	/// @{

	/// Returns an unsigned integer vector obtained by converting the components of a floating-point vector
	/// to the 16-bit floating-point representation found in the OpenGL Specification.
	/// The first vector component specifies the 16 least-significant bits of the result;
	/// the forth component specifies the 16 most-significant bits.
	///
	/// @see vec<L, float, Q> unpackHalf(vec<L, uint16, Q> const& p)
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.4 Floating-Point Pack and Unpack Functions</a>
	template<length_t L, qualifier Q>
	GLM_FUNC_DECL vec<L, uint16, Q> packHalf(vec<L, float, Q> const& v);

	/// Returns a floating-point vector with components obtained by reinterpreting an integer vector as 16-bit floating-point numbers and converting them to 32-bit floating-point values.
	/// The first component of the vector is obtained from the 16 least-significant bits of v;
	/// the forth component is obtained from the 16 most-significant bits of v.
	///
	/// @see vec<L, uint16, Q> packHalf(vec<L, float, Q> const& v)
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.4 Floating-Point Pack and Unpack Functions</a>
	template<length_t L, qualifier Q>
	GLM_FUNC_DECL vec<L, float, Q> unpackHalf(vec<L, uint16, Q> const& p);

	/// @}
}//namespace glm

#include "vector_packing.inl"
