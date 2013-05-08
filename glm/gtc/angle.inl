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
/// @ref gtx_angle
/// @file glm/gtx/angle.inl
/// @date 2013-05-07 / 2013-05-07
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <limits>

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
	GLM_FUNC_QUALIFIER tangle<T, P>::tangle() :
		data(0)
	{}

	template <typename T, precision P>
	template <typename U, precision Q>
	GLM_FUNC_QUALIFIER tangle<T, P>::tangle
	(
		tangle<U, Q> const & a
	) :
		data(a.data)
	{}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER detail::tangle<T, P> operator-
	(
		detail::tangle<T, P> const & a
	)
	{

	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER detail::tangle<T, P> operator+
	(
		detail::tangle<T, P> const & q,
		detail::tangle<T, P> const & p
	)
	{

	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER detail::tangle<T, P> operator-
	(
		detail::tangle<T, P> const & q,
		detail::tangle<T, P> const & p
	)
	{

	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER detail::tangle<T, P> operator*
	(
		detail::tangle<T, P> const & q,
		T const & s
	)
	{

	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER detail::tangle<T, P> operator/
	(
		detail::tangle<T, P> const & q,
		T const & s
	)
	{

	}

}//namespace detail
}//namespace glm
