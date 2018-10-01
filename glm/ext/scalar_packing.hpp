/// @ref ext_scalar_packing
/// @file glm/ext/scalar_packing.hpp
///
/// @defgroup ext_scalar_packing GLM_EXT_scalar_packing
/// @ingroup ext
///
/// Exposes comparison functions for scalar types that take a user defined epsilon values.
///
/// Include <glm/ext/scalar_packing.hpp> to use the features of this extension.
///
/// @see core_packing
/// @see ext_vector_packing

#pragma once

// Dependencies
#include "../detail/qualifier.hpp"
#include "../ext/scalar_uint_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_scalar_packing extension included")
#endif

namespace glm
{
	/// @addtogroup ext_scalar_packing
	/// @{

	/// Returns an unsigned integer scalar obtained by converting the components of a floating-point scalar
	/// to the 16-bit floating-point representation found in the OpenGL Specification.
	/// The first vector component specifies the 16 least-significant bits of the result;
	/// the forth component specifies the 16 most-significant bits.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.4 Floating-Point Pack and Unpack Functions</a>
	GLM_FUNC_DECL uint16 packHalf(float s);

	/// Returns a floating-point scalar with components obtained by reinterpreting an integer scalar as 16-bit floating-point numbers and converting them to 32-bit floating-point values.
	/// The first component of the vector is obtained from the 16 least-significant bits of v;
	/// the forth component is obtained from the 16 most-significant bits of v.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 8.4 Floating-Point Pack and Unpack Functions</a>
	GLM_FUNC_DECL float unpackHalf(uint16 p);

	/// @}
}//namespace glm

#include "scalar_packing.inl"
