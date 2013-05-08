///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref gtc_angle
/// @file glm/gtc/angle.hpp
/// @date 2013-05-07 / 2012-05-07
/// @author Christophe Riccio
///
/// @see core (dependence)
/// @see gtc_angle (dependence)
///
/// @defgroup gtc_angle GLM_GTC_angle
/// @ingroup gtc
/// 
/// @brief Handling angles in both radians and degrees.
/// 
/// <glm/gtc/angle.hpp> need to be included to use these features.
///////////////////////////////////////////////////////////////////////////////////

#ifndef GLM_GTX_angle
#define GLM_GTX_angle GLM_VERSION

namespace glm{
namespace detail
{
	template <typename T, precision P>
	class tangle
	{
	public:
		typedef T value_type;

		// Constructors
		tangle();
		template <typename U, precision Q>
		GLM_FUNC_DECL explicit tangle(
			tangle<U, Q> const & q);
		tangle(value_type const & x) :
			data(x)
		{}

		// Operators
		GLM_FUNC_DECL tangle<T, P> & operator+=(tangle<T, P> const & a);
		GLM_FUNC_DECL tangle<T, P> & operator-=(tangle<T, P> const & a);
		GLM_FUNC_DECL tangle<T, P> & operator*=(value_type const & s);
		GLM_FUNC_DECL tangle<T, P> & operator/=(value_type const & s);

	private:
		value_type data;
	};

	template <typename T, precision P>
	detail::tangle<T, P> operator- (
		detail::tangle<T, P> const & q);

	template <typename T, precision P>
	detail::tangle<T, P> operator+ (
		detail::tangle<T, P> const & q,
		detail::tangle<T, P> const & p);

	template <typename T, precision P>
	detail::tangle<T, P> operator- (
		detail::tangle<T, P> const & q,
		detail::tangle<T, P> const & p);

	template <typename T, precision P>
	detail::tangle<T, P> operator* (
		detail::tangle<T, P> const & q,
		T const & s);

	template <typename T, precision P>
	detail::tangle<T, P> operator/ (
		detail::tangle<T, P> const & q,
		T const & s);
}//namespace detail

	/// Low half-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<half, lowp> lowp_hangle;

	/// Medium half-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<half, mediump> mediump_hangle;

	/// High half-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<half, highp> highp_hangle;

#if(defined(GLM_PRECISION_HIGHP_HALF) && !defined(GLM_PRECISION_MEDIUMP_HALF) && !defined(GLM_PRECISION_LOWP_HALF))
	typedef highp_hangle		hangle;
#elif(!defined(GLM_PRECISION_HIGHP_HALF) && defined(GLM_PRECISION_MEDIUMP_HALF) && !defined(GLM_PRECISION_LOWP_HALF))
	typedef mediump_hangle		hangle;
#elif(!defined(GLM_PRECISION_HIGHP_HALF) && !defined(GLM_PRECISION_MEDIUMP_HALF) && defined(GLM_PRECISION_LOWP_HALF))
	typedef lowp_hangle			hangle;
#elif(!defined(GLM_PRECISION_HIGHP_HALF) && !defined(GLM_PRECISION_MEDIUMP_HALF) && !defined(GLM_PRECISION_LOWP_HALF))
	/// Default half-precision floating-point angle.
	typedef highp_hangle		hangle;
#endif

	/// Low single-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<float, lowp> lowp_angle;

	/// Medium single-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<float, mediump> mediump_angle;

	/// High single-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<float, highp> highp_angle;

	/// Low single-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<float, lowp> lowp_fangle;

	/// Medium single-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<float, mediump> mediump_fangle;

	/// High single-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<float, highp> highp_fangle;

#if(defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	typedef highp_fangle		angle;
#elif(!defined(GLM_PRECISION_HIGHP_FLOAT) && defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	typedef mediump_fangle		angle;
#elif(!defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && defined(GLM_PRECISION_LOWP_FLOAT))
	typedef lowp_fangle			angle;
#elif(!defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	/// Default single-precision floating-point angle.
	typedef highp_fangle		angle;
#endif

	/// Default single-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef angle				fangle;

	/// Low double-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<double, lowp> lowp_dangle;

	/// Medium double-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<double, mediump> mediump_dangle;

	/// High double-precision floating-point angle.
	///
	/// @see gtx_angle
	typedef detail::tangle<double, highp> highp_dangle;

#if(defined(GLM_PRECISION_HIGHP_DOUBLE) && !defined(GLM_PRECISION_MEDIUMP_DOUBLE) && !defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef highp_dangle		dangle;
#elif(!defined(GLM_PRECISION_HIGHP_DOUBLE) && defined(GLM_PRECISION_MEDIUMP_DOUBLE) && !defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef mediump_dangle		dangle;
#elif(!defined(GLM_PRECISION_HIGHP_DOUBLE) && !defined(GLM_PRECISION_MEDIUMP_DOUBLE) && defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef lowp_dangle			dangle;
#elif(!defined(GLM_PRECISION_HIGHP_DOUBLE) && !defined(GLM_PRECISION_MEDIUMP_DOUBLE) && !defined(GLM_PRECISION_LOWP_DOUBLE))
	/// Default double-precision floating-point angle.
	typedef highp_dangle		dangle;
#endif

	GLM_FUNC_DECL hangle operator "" _rad_h(long double const radians)
	{
		return hangle(radians);
	}

	GLM_FUNC_DECL fangle operator "" _rad_f(long double const radians)
	{
		return fangle(radians);
	}

	GLM_FUNC_DECL dangle operator "" _rad(long double const radians)
	{
		return dangle(radians);
	}

	GLM_FUNC_DECL detail::tangle<long double> operator "" _rad_l(long double const radians)
	{
		return detail::tangle<long double>(radians);
	}

	GLM_FUNC_DECL hangle operator "" _deg_h(long double const degrees)
	{
		return hangle(half(static_cast<float>(degrees) * static_cast<float>(0.01745329251994329576923690768489L)));
	}

	GLM_FUNC_DECL fangle operator "" _deg_f(long double const degrees)
	{
		return fangle(static_cast<float>(degrees) * static_cast<float>(0.01745329251994329576923690768489L));
	}

	GLM_FUNC_DECL dangle operator "" _deg(long double const degrees)
	{
		return dangle(static_cast<double>(degrees) * static_cast<double>(0.01745329251994329576923690768489L));
	}

	GLM_FUNC_DECL detail::tangle<long double> operator "" _deg_l(long double const degrees)
	{
		return detail::tangle<long double>(degrees * 0.01745329251994329576923690768489L);
	}

}//namespace glm

#include "angle.inl"

#endif//GLM_GTX_angle
